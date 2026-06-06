#include "raylib.h"
#include "grid.h"

 /* GAME LOOP: Event Handling -> Update -> Render*/

int main(void){

    InitWindow(800, 800, "Chess-plusplus");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.print();


    while(WindowShouldClose() == false){


        BeginDrawing();
        ClearBackground(BLUE);
        grid.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}