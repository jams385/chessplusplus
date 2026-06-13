#include "raylib.h"
#include "ChessBoard.h"
#include "configs.h"
#include "stdio.h"
#include "stdlib.h"

// function prototypes
void drawBoard();
Vector2 pixelToGrid(Vector2 pixelCord);
void drawPiece(int x, int y, int size, int piece);

// Initialize class
ChessBoard game;

/* GAME LOOP: Event Handling -> Update -> Render*/
int main(void){

    InitWindow(configs::window_Width, configs::window_Height, configs::ProjectName);
    SetTargetFPS(60);

    // initialize variables
    Vector2 mouse_position = {0, 0};
    Vector2 selectedTile = {-1, -1};

    while(WindowShouldClose() == false){

        /* --------------------------------------------------
            EVENT HANDLING
        ----------------------------------------------------- */

        // gets mouse position when clicked
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            mouse_position = GetMousePosition();
        }

        /* --------------------------------------------------
            UPDATE
        ----------------------------------------------------- */
        
        selectedTile = pixelToGrid(mouse_position);
    
        /* --------------------------------------------------
            RENDER/DRAW
        ----------------------------------------------------- */

        BeginDrawing();
        ClearBackground(BLUE);

        // draws board
        drawBoard();

        // higlights selected tile
        if((selectedTile.x >= 0 && selectedTile.y >= 0) && (selectedTile.x < 8 && selectedTile.y < 8)){
            DrawRectangle   (configs::tile_width * selectedTile.x, configs::tile_height * selectedTile.y, 
                            configs::tile_width, configs::tile_height, BLUE);
        }

        // draw Pieces
        for(int col = 0; col < 8; col++){
            for(int row = 0; row < 8; row++){
                uint8_t square = col + row * 8;
                drawPiece((col*configs::tile_height) + 50, (row*configs::tile_width) + 50, 40, game.getPiece(square));
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void drawBoard(){

    for(int rows = 0; rows < 8; rows++){
        for(int cols = 0; cols < 8; cols++){

            if((rows % 2 == 0 && cols % 2 == 0) || (rows % 2 != 0 && cols % 2 != 0)){
                DrawRectangle   (configs::tile_height * cols, configs::tile_width * rows, 
                                configs::tile_height, configs::tile_width, WHITE);
            } else { 
                DrawRectangle   (configs::tile_height * cols, configs::tile_width * rows, 
                                configs::tile_height, configs::tile_width, BLACK); 
            }
        }
    }

}

Vector2 pixelToGrid(Vector2 pixelCord){
    Vector2 Grid;
    Grid.x  = (int)(pixelCord.x/configs::tile_width);
    Grid.y = (int)(pixelCord.y/configs::tile_height);

    return Grid;
}

void drawPiece(int x, int y, int size, int piece){
    switch(piece){
    case whitePawn:
        DrawCircle(x, y, size/2, WHITE);
        DrawCircleLines(x, y, size/2, BLACK);
        break;
    case blackPawn:
        DrawCircle(x, y, size/2, BLACK);
        DrawCircleLines(x, y, size/2, WHITE);
        break;  // was missing!
    case whiteRook:
        DrawRectangle(x-size/2, y-size/2, size, size, WHITE);
        DrawRectangleLines(x-size/2, y-size/2, size, size, BLACK);
        break;
    case blackRook:
        DrawRectangle(x-size/2, y-size/2, size, size, BLACK);  // was x-size
        DrawRectangleLines(x-size/2, y-size/2, size, size, WHITE);
        break;
    case whiteKing:
        DrawRectangle(x-size/4, y-size/2, size/2, size, WHITE);  // was hardcoded 30,80
        DrawRectangleLines(x-size/4, y-size/2, size/2, size, BLACK);
        break;
    case blackKing:
        DrawRectangle(x-size/4, y-size/2, size/2, size, BLACK);
        DrawRectangleLines(x-size/4, y-size/2, size/2, size, WHITE);
        break;
    case whiteBishop:
        DrawEllipse(x, y, size/2, size, WHITE);  // ellipse takes center, no offset needed
        DrawEllipseLines(x, y, size/2, size, BLACK);
        break;
    case blackBishop:
        DrawEllipse(x, y, size/2, size, BLACK);
        DrawEllipseLines(x, y, size/2, size, WHITE);
        break;
    case whiteQueen:
        DrawRectangle(x-size/2, y-size/4, size, size*3/4, WHITE);
        DrawRectangleLines(x-size/2, y-size/4, size, size*3/4, BLACK);
        DrawCircle(x, y-size/4, size/2, WHITE);
        DrawCircleLines(x, y-size/4, size/2, BLACK);
        break;
    case blackQueen:
        DrawRectangle(x-size/2, y-size/4, size, size*3/4, BLACK);
        DrawRectangleLines(x-size/2, y-size/4, size, size*3/4, WHITE);
        DrawCircle(x, y-size/4, size/2, BLACK);
        DrawCircleLines(x, y-size/4, size/2, WHITE);
        break;
    case whiteKnight:
        DrawRectangle(x-size/2, y-size/4, size, size*3/4, WHITE);
        DrawRectangleLines(x-size/2, y-size/4, size, size*3/4, BLACK);
        DrawRectangle(x-size/4, y-size/2, size/2, size/3, WHITE);
        DrawRectangleLines(x-size/4, y-size/2, size/2, size/3, BLACK);
        break;
    case blackKnight:
        DrawRectangle(x-size/2, y-size/4, size, size*3/4, BLACK);
        DrawRectangleLines(x-size/2, y-size/4, size, size*3/4, WHITE);
        DrawRectangle(x-size/4, y-size/2, size/2, size/3, BLACK);
        DrawRectangleLines(x-size/4, y-size/2, size/2, size/3, WHITE);
        break;
    case empty:
    default:
        break;
    }
}