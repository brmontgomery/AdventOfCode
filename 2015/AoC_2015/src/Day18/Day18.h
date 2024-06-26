#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D18P1() {
    std::vector<std::string> input = getFileInput(".//src//Day18//Day18.txt");

    Grid2D<int> grid = Grid2D<int>(0, 100, 100);

    //set initial configuration for thegrid.
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (input[i][j] == '#') {
                grid.setValue(1, i, j);
            }
        }
    }

    //for each step, 
    // a light that is on, stays on if it has two or 3 on neighbors, otherwise it turns off
    //a light that is off turns on if exactly 3 of its neightbors are on, otherise it stay off
    //most of the below math is detecting edges (always considered off)
    for (int step = 0; step < 100; step++) {
        Grid2D<int> grid2 = Grid2D<int>(0, 100, 100);
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int count = 0;

                if (i > 0) {
                    if (grid.getValue(i - 1, j) == 1) {
                        count++;
                    }
                    if (j > 0) {
                        if (grid.getValue(i - 1, j-1) == 1) {
                            count++;
                        }
                    }
                    if (j < 99) {
                        if (grid.getValue(i - 1, j + 1) == 1) {
                            count++;
                        }
                    }
                }
                if (i < 99) {
                    if (grid.getValue(i + 1, j) == 1) {
                        count++;
                    }
                    if (j > 0) {
                        if (grid.getValue(i + 1, j - 1) == 1) {
                            count++;
                        }
                    }
                    if (j < 99) {
                        if (grid.getValue(i + 1, j + 1) == 1) {
                            count++;
                        }
                    }
                }
                if (j > 0) {
                    if (grid.getValue(i, j - 1) == 1) {
                        count++;
                    }
                }
                if (j < 99) {
                    if (grid.getValue(i, j + 1) == 1) {
                        count++;
                    }
                }

                if (grid.getValue(i, j) == 1)
                {
                    if (count == 2 || count == 3) {
                        grid2.setValue(1, i, j);
                    }
                }
                else {
                    if (count == 3) {
                        grid2.setValue(1, i, j);
                    }
                }
            }
        }
        grid = grid2;
    }

    //return how many lights are on
    std::cout << grid.countValue(1) << std::endl;
}

void AoC2015D18P2() {
    std::vector<std::string> input = getFileInput(".//src//Day18//Day18.txt");

    Grid2D<int> grid = Grid2D<int>(0, 100, 100);

    //initialize grid with the four corners turned on
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (input[i][j] == '#') {
                grid.setValue(1, i, j);
            }
        }
    }
    grid.setValue(1, 0, 0);
    grid.setValue(1, 0, 99);
    grid.setValue(1, 99, 0);
    grid.setValue(1, 99, 99);
    
    //for each step, 
    // a light that is on, stays on if it has two or 3 on neighbors, otherwise it turns off
    //a light that is off turns on if exactly 3 of its neightbors are on, otherise it stay off
    //most of the below math is detecting edges (always considered off)
    for (int step = 0; step < 100; step++) {
        Grid2D<int> grid2 = Grid2D<int>(0, 100, 100);
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int count = 0;

                if (i > 0) {
                    if (grid.getValue(i - 1, j) == 1) {
                        count++;
                    }
                    if (j > 0) {
                        if (grid.getValue(i - 1, j - 1) == 1) {
                            count++;
                        }
                    }
                    if (j < 99) {
                        if (grid.getValue(i - 1, j + 1) == 1) {
                            count++;
                        }
                    }
                }
                if (i < 99) {
                    if (grid.getValue(i + 1, j) == 1) {
                        count++;
                    }
                    if (j > 0) {
                        if (grid.getValue(i + 1, j - 1) == 1) {
                            count++;
                        }
                    }
                    if (j < 99) {
                        if (grid.getValue(i + 1, j + 1) == 1) {
                            count++;
                        }
                    }
                }
                if (j > 0) {
                    if (grid.getValue(i, j - 1) == 1) {
                        count++;
                    }
                }
                if (j < 99) {
                    if (grid.getValue(i, j + 1) == 1) {
                        count++;
                    }
                }

                if (grid.getValue(i, j) == 1)
                {
                    if (count == 2 || count == 3) {
                        grid2.setValue(1, i, j);
                    }
                }
                else {
                    if (count == 3) {
                        grid2.setValue(1, i, j);
                    }
                }
            }
        }
        grid2.setValue(1, 0, 0);
        grid2.setValue(1, 0, 99);
        grid2.setValue(1, 99, 0);
        grid2.setValue(1, 99, 99);
        grid = grid2;
    }

    std::cout << grid.countValue(1) << std::endl;
}