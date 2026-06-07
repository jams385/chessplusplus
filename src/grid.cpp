#include "grid.h"
#include "iostream"

/* Grid Constructor */
Grid::Grid(){

    numRows = 8;
    numCols = 8;
    cellSize = 100;
    initGrid();
    colors = getCellColors();

}

/* Initializes the grid to hold 0 per tile*/
void Grid::initGrid(){

    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            
            if((row % 2 == 0 && column % 2 == 0) || (row % 2 != 0 && column % 2 != 0)){
                grid[row][column] = 1;
            } else { grid[row][column] = 0; }
        }
    }

}


/* prints the grid in the terminal*/
void Grid::print(){

    for(int row = 0; row < numRows; row++){
        for(int columns = 0; columns < numCols; columns++){
            std::cout << grid[row][columns] << " ";
        }
        std::cout << std::endl;
    }

}

/* Used to color the grid when draw() is called */
std::vector<Color> Grid::getCellColors(){

    Color black = {0, 0, 0, 255};
    Color white = {255, 255, 255, 255};

    return {black, white};
}

/* draws the grid */
void Grid::draw(){

    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize, row * cellSize, cellSize, cellSize, colors[cellValue]);
        }
    }

}
