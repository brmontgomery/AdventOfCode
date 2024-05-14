#pragma once
#include <iostream>
#include "AoCUtilities.h"
#include "2DGrid.h"

void move(char input, Grid2D<int>& grid, int& currentX, int& currentY, int& gridExpansion) {
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

    Grid2D<int> grid = Grid2D<int>(0);
    int currentX = 0, currentY = 0, gridExpansion;

    grid.setValue(1, 0, 0);
    
    for (int i = 0; i < input[0].size(); i++) {
        move(input[0][i], grid, currentX, currentY, gridExpansion);
    }

    std::cout << grid.countValue(1) << std::endl;
}

void AoC2015D3P2() {
    std::vector<std::string> input = getFileInput(".//src//Day3//Day3.txt");

    Grid2D<int> grid = Grid2D<int>(0);
    int currentX1 = 0, currentY1 = 0, currentX2 = 0, currentY2 = 0, gridExpansion = 0;

    grid.setValue(1, 0, 0);

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

    std::cout << grid.countValue(1) << std::endl;
}