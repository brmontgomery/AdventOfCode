#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D25P1() {
    std::vector<std::string> input = getFileInput(".//src//Day25//Day25.txt");
    
    //many of the inputs were not in the .txt. Had to initialize more hard coded values than I'd like.
    uint64_t multiplier = 252533, divisor = 33554393;
    std::vector<std::string> inputWords = parseStringToString(input[0], ' ');
    int rowLength = 2;
    uint64_t goalX = std::stoi(inputWords[18].substr(0, 4)), goalY = std::stoi(inputWords[16].substr(0, 4)), itX = 1, itY = 2, lastResult = 20151125;

    //iterates in an up to the left direction on the infinite grid while also performing the modular multiplication.
    //once we pass the correct index, we exit.
    while (itX != goalX + 1 || itY != goalY - 1) {
        lastResult = (lastResult * multiplier) % divisor;

        if (itY == 1) {
            rowLength++;
            itY = rowLength;
            itX = 1;
            std::cout << std::to_string(itY) << std::endl;
        }
        else {
            itY--;
            itX++;
        }
    }

    std::cout << std::to_string(lastResult) << std::endl << std::endl;
}

void AoC2015D25P2() {
    std::vector<std::string> input = getFileInput(".//src//Day25//Day25.txt");
    
    //There was no 50th question... Just had to get 49 stars to get the 50th.
}