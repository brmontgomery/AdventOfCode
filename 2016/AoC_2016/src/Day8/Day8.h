#pragma once
#include <iostream>
#include "2DGrid.h"
#include "AoCUtilities.h"

void AoC2016D8P1() {
    std::vector<std::string> input = getFileInput(".//src//Day8//Day8.txt");
    Grid2D<bool> grid(false, 50, 6);

    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        if (parsed[0] == "rect") {
            auto found = parsed[1].find("x");
            int rowSize = std::stoi(parsed[1].substr(0, found));
            int columnSize = std::stoi(parsed[1].substr(found+1));

            for (int j = 0; j < rowSize; j++) {
                for (int k = 0; k < columnSize; k++) {
                    grid.setValue(1, j, k);
                }
            }
        }
        else if (parsed[1] == "column") {
            int columnNum = std::stoi(parsed[2].substr(2));
            int factor = std::stoi(parsed[4]);
            std::vector<bool> column;

            for (int j = 0; j < grid.getColumnLength(); j++) {
                column.push_back(grid.getValue(columnNum, j));
            }

            for (int j = 0; j < grid.getColumnLength(); j++) {
                grid.setValue(column[j], columnNum, ((j +factor) % grid.getColumnLength()));
            }
        }
        else if (parsed[1] == "row") {
            int rowNum = std::stoi(parsed[2].substr(2));
            int factor = std::stoi(parsed[4]);
            std::vector<bool> row;
            
            for (int j = 0; j < grid.getRowLength(); j++) {
                row.push_back(grid.getValue(j, rowNum));
            }

            for (int j = 0; j < grid.getRowLength(); j++) {
                grid.setValue(row[j], ((j + factor) % grid.getRowLength()), rowNum);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < grid.getRowLength(); i++) {
        for (int j = 0; j < grid.getColumnLength(); j++) {
            if (grid.getValue(i, j) == true) {
                count++;
            }
        }
    }
    std::cout << std::to_string(count) << std::endl;
}

void AoC2016D8P2() {
    std::vector<std::string> input = getFileInput(".//src//Day8//Day8.txt");
    Grid2D<bool> grid(false, 50, 6);

    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        if (parsed[0] == "rect") {
            auto found = parsed[1].find("x");
            int rowSize = std::stoi(parsed[1].substr(0, found));
            int columnSize = std::stoi(parsed[1].substr(found + 1));

            for (int j = 0; j < rowSize; j++) {
                for (int k = 0; k < columnSize; k++) {
                    grid.setValue(1, j, k);
                }
            }
        }
        else if (parsed[1] == "column") {
            int columnNum = std::stoi(parsed[2].substr(2));
            int factor = std::stoi(parsed[4]);
            std::vector<bool> column;

            for (int j = 0; j < grid.getColumnLength(); j++) {
                column.push_back(grid.getValue(columnNum, j));
            }

            for (int j = 0; j < grid.getColumnLength(); j++) {
                grid.setValue(column[j], columnNum, ((j + factor) % grid.getColumnLength()));
            }
        }
        else if (parsed[1] == "row") {
            int rowNum = std::stoi(parsed[2].substr(2));
            int factor = std::stoi(parsed[4]);
            std::vector<bool> row;

            for (int j = 0; j < grid.getRowLength(); j++) {
                row.push_back(grid.getValue(j, rowNum));
            }

            for (int j = 0; j < grid.getRowLength(); j++) {
                grid.setValue(row[j], ((j + factor) % grid.getRowLength()), rowNum);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < grid.getColumnLength(); i++) {
        for (int j = 0; j < grid.getRowLength(); j++) {
            if (grid.getValue(j, i) == true) {
                std::cout << '#';
            }
            else {
                std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
    
}