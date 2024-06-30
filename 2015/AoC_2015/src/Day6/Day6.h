#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D6P1() {
    std::vector<std::string> input = getFileInput(".//src//Day6//Day6.txt");

    //initialize grid
    Grid2D<bool> grid = Grid2D<bool>(false, 1000, 1000);
    
    int operation;
    int topLeftRow = 0, topLeftColumn = 0;
    int bottomRightRow = 0, bottomRightColumn = 0;

    int onCount = 0;
    
    //for each instruction, either toggle all the values in the specified 2D range, set all values to 1 in the 2D range, or set all values to 0  in the 2D range
    for (int i = 0; i < input.size(); i++) {
        //parse the input string

        //get the instruction
        std::string switchInput = input[i].substr(0, 7);
        if (switchInput == "toggle ") {
            input[i] = input[i].substr(7);
            operation = 0;
        } else if (switchInput == "turn on") {
            input[i] = input[i].substr(8);
            operation = 1;
        } else if (switchInput == "turn of") {
            input[i] = input[i].substr(9);
            operation = 2;
        }


        //get the range
        int iterator = input[i].find(',');
        topLeftRow = std::stoi(input[i].substr(0, iterator));
        topLeftColumn = std::stoi(input[i].substr(iterator + 1, 3));
        
        iterator = input[i].find_last_of(',');
        bottomRightColumn = std::stoi(input[i].substr(iterator + 1));
        bottomRightRow = std::stoi(input[i].substr(iterator-3, 3));

        //implement the actual logic for each instruction
        switch (operation) {
            case 0:
                for (int j = topLeftRow; j <= bottomRightRow; j++) {
                    for (int k = topLeftColumn; k <= bottomRightColumn; k++) {
                        if (grid.getValue(j, k) == false) {
                            grid.setValue(true, j, k);
                        }
                        else {
                            grid.setValue(false, j, k);
                        }
                    }
                }
                break;
            case 1:
                for (int j = topLeftRow; j <= bottomRightRow; j++) {
                    for (int k = topLeftColumn; k <= bottomRightColumn; k++) {
                        grid.setValue(true, j, k);
                    }
                }
                break;
            case 2:
                for (int j = topLeftRow; j <= bottomRightRow; j++) {
                    for (int k = topLeftColumn; k <= bottomRightColumn; k++) {
                        grid.setValue(false, j, k);
                    }
                }
                break;
        }
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (grid.getValue(i, j) == true) {
                onCount++;
            }
        }
    }
    std::cout << onCount << std::endl << std::endl;
}

void AoC2015D6P2() {
    std::vector<std::string> input = getFileInput(".//src//Day6//Day6.txt");

    //initialize grid
    Grid2D<int> grid = Grid2D<int>(0, 1000, 1000);

    int operation;
    int topLeftRow = 0, topLeftColumn = 0;
    int bottomRightRow = 0, bottomRightColumn = 0;

    int onCount = 0;

    //the rules have change:
    //toggle means to increment all the values in the specified 2D range by 2, 
    //Turn off means to decrement all values specified in the 2D range by 1 (min of 0)
    //Turn on means to increment all values specified in the 2D range by 1
    for (int i = 0; i < input.size(); i++) {
        //parse the input string

        //get the instructions
        std::string switchInput = input[i].substr(0, 7);
        if (switchInput == "toggle ") {
            input[i] = input[i].substr(7);
            operation = 0;
        }
        else if (switchInput == "turn on") {
            input[i] = input[i].substr(8);
            operation = 1;
        }
        else if (switchInput == "turn of") {
            input[i] = input[i].substr(9);
            operation = 2;
        }

        //find the ranges
        int iterator = input[i].find(',');
        topLeftRow = std::stoi(input[i].substr(0, iterator));
        topLeftColumn = std::stoi(input[i].substr(iterator + 1, 3));

        iterator = input[i].find_last_of(',');
        bottomRightColumn = std::stoi(input[i].substr(iterator + 1));
        bottomRightRow = std::stoi(input[i].substr(iterator - 3, 3));

        //implement logic
        switch (operation) {
        case 0:
            for (int j = topLeftRow; j <= bottomRightRow; j++) {
                for (int k = topLeftColumn; k <= bottomRightColumn; k++) {
                    grid.setValue(grid.getValue(j, k) + 2, j, k);
                }
            }
            break;
        case 1:
            for (int j = topLeftRow; j <= bottomRightRow; j++) {
                for (int k = topLeftColumn; k <= bottomRightColumn; k++) {
                    grid.setValue(grid.getValue(j,k) + 1, j, k);
                }
            }
            break;
        case 2:
            for (int j = topLeftRow; j <= bottomRightRow; j++) {
                for (int k = topLeftColumn; k <= bottomRightColumn; k++) {
                    if (grid.getValue(j, k) > 0) {
                        grid.setValue(grid.getValue(j, k) - 1, j, k);
                    }
                }
            }
            break;
        }
    }
    //find the sum of all values in grid
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            onCount += grid.getValue(i, j);
        }
    }
    std::cout << onCount << std::endl << std::endl;
}
