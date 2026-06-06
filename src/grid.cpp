#include "grid.h"
#include "iostream"

Grid::Grid(){

    numRows = 8;
    numCols = 8;
    cellSize = 100;
    initGrid();
    colors = getCellColors();

}

void Grid::initGrid(){

    for(int row = 0; row < numRows; row++){
        for(int columns = 0; columns < numCols; columns++){
            grid[row][columns] = 0;
        }
    }

}

void Grid::print(){

    for(int row = 0; row < numRows; row++){
        for(int columns = 0; columns < numCols; columns++){
            std::cout << grid[row][columns] << " ";
        }
        std::cout << std::endl;
    }

}

std::vector<Color> Grid::getCellColors(){

    Color black = {0, 0, 0, 255};
    Color white = {255, 255, 255, 255};

    return {black, white};
}

void Grid::draw(){

    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }

}
