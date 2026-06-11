#include "raylib.h"
#include "ChessBoard.h"
#include "configs.h"




void drawBoard(){
    for(int rows = 0; rows < 8; rows++){
        for(int cols = 0; cols < 8; cols++){

            if((rows % 2 == 0 && cols % 2 == 0) || (rows % 2 != 0 && cols % 2 != 0)){
                DrawRectangle   (configs::tile_height * rows, configs::tile_width * cols, 
                                configs::tile_height, configs::tile_width, WHITE);
            } else { 
                DrawRectangle   (configs::tile_height * rows, configs::tile_width * cols, 
                                configs::tile_height, configs::tile_width, BLACK); 
            }
        }
    }
}


/* GAME LOOP: Event Handling -> Update -> Render*/
int main(void){

    InitWindow(configs::window_Width, configs::window_Height, configs::ProjectName);
    SetTargetFPS(60);

    while(WindowShouldClose() == false){


        BeginDrawing();

        ClearBackground(BLUE);
        drawBoard();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}