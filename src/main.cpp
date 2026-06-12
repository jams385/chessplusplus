#include "raylib.h"
#include "ChessBoard.h"
#include "configs.h"
#include "stdio.h"

// function prototypes
void drawBoard();
Vector2 pixelToGrid(Vector2 pixelCord);

/* GAME LOOP: Event Handling -> Update -> Render*/
int main(void){

    InitWindow(configs::window_Width, configs::window_Height, configs::ProjectName);
    SetTargetFPS(60);

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
            RENDER
        ----------------------------------------------------- */

        BeginDrawing();
        ClearBackground(BLUE);

        drawBoard();
        
        
        if((selectedTile.x >= 0 && selectedTile.y >= 0) && (selectedTile.x < 8 && selectedTile.y < 8)){
            DrawRectangle(configs::tile_width * selectedTile.x, configs::tile_height * selectedTile.y, configs::tile_width, configs::tile_height, BLUE);
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