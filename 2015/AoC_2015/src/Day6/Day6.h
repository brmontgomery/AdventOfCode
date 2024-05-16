#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D6P1() {
    std::vector<std::string> input = getFileInput(".//src//Day6//Day6.txt");

    Grid2D grid;
    
    int operation;
    int topLeftRow = 0, topLeftColumn = 0;
    int bottomRightRow = 0, bottomRightColumn = 0;
    
    for (int i = 0; i < input[i]; i++) {
        //parse the input string
        switch (input[i].substr(0, 7) {
            case "toggle "
                input[i] = input[i].substr(7);
                operation = 0;
                break;
            case "turn on":
                input[i] = input[i].substr(8);
                operation = 1;
                break;
            case "turn of":
                input[i] = input[i].substr(9);
                operation = 2
                break;
        }
        int iterator = input[i].find(',');
        topLeftRow = std::stoi(input[i].substr(0, iterator));
        input[i] = input[i].substr(iterator + 1);
        iterator = input[i].find(' ');
        topLeftColumn = std::stoi(input[i].substr(0, iterator));
        iterator = input[i].find_last_of(',') + 1;
        int iterator2 = input[i].find_last_of(' ') + 1;
        bottomRightColumn = input[i].substr(input[i].find_last_of(',') + 1);
        bottomRightRow = std::stoi(input[i].substr(iterator2, iterator - iterator2));

        switch (operation) {
            case 0:
                
                break;
            case 1:
                
                break;
            case 2:
                
                break;
        }
    }
}

void AoC2015D6P2() {
    std::vector<std::string> input = getFileInput(".//src//Day6//Day6.txt");
    
}
