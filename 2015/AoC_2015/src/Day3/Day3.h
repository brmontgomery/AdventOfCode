#pragma once
#include <iostream>
#include "AoCUtilities.h"
#include "2DGrid.h"

void move(char input, Grid2D<int>& grid, int& currentX, int& currentY, int& gridExpansion) {
    //using an infinitey extensible 2D grid object that I created, move in whichever direction is indicated by the arrows and set the index's vlue to 1.
    switch (input) {
    case '^':
        currentY--;
        if (currentY < 0) {
            grid.pushFrontColumn();
            currentY++;
            gridExpansion = 2;
        }
        grid.setValue(1, currentX, currentY);
        
        break;

    case 'v':
        currentY++;
        if (currentY >= grid.getColumnLength()) {
            grid.pushBackColumn();
        }
        grid.setValue(1, currentX, currentY);
        break;

    case '<':
        currentX--;
        if (currentX < 0) {
            grid.pushFrontRow();
            currentX++;
            gridExpansion = 1;
        }
        grid.setValue(1, currentX, currentY);
        
        break;

    case '>':
        currentX++;
        if (currentX >= grid.getRowLength()) {
            grid.pushBackRow();
        }
        grid.setValue(1, currentX, currentY);
        break;
    }
}

void AoC2015D3P1() {
    std::vector<std::string> input = getFileInput(".//src//Day3//Day3.txt");

    //initialize grid object
    Grid2D<int> grid = Grid2D<int>(0, 1, 1);
    int currentX = 0, currentY = 0, gridExpansion;

    //set the starting point to 1
    grid.setValue(1, 0, 0);
    
    //for each instruction, set the house to visited.
    for (int i = 0; i < input[0].size(); i++) {
        move(input[0][i], grid, currentX, currentY, gridExpansion);
    }

    //Final answer is the number of grid locations that have been visited.
    std::cout << grid.countValue(1) << std::endl;
}

void AoC2015D3P2() {
    std::vector<std::string> input = getFileInput(".//src//Day3//Day3.txt");

    //init the grid
    Grid2D<int> grid = Grid2D<int>(0, 1, 1);
    int currentX1 = 0, currentY1 = 0, currentX2 = 0, currentY2 = 0, gridExpansion = 0;

    grid.setValue(1, 0, 0);

    //this problem has two indexes that take turns moving around the grid
    //for each instruction, set the house to visited by the active index to 1.
    for (int i = 0; i < input[0].size(); i++) {
        if (i % 2 == 0) {
            move(input[0][i], grid, currentX1, currentY1, gridExpansion);
            if (gridExpansion == 1) {
                currentX2++;
            }
            else if (gridExpansion == 2) {
                currentY2++;
            }
        }
        else {
            move(input[0][i], grid, currentX2, currentY2, gridExpansion);
            if (gridExpansion == 1) {
                currentX1++;
            }
            else if (gridExpansion == 2) {
                currentY1++;
            }
        }
        gridExpansion = 0;
    }

    //return the number of grid locations visited
    std::cout << grid.countValue(1) << std::endl;
}
