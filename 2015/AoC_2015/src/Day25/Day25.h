#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D25P1() {
    std::vector<std::string> input = getFileInput(".//src//Day25//Day25.txt");
    /*std::vector<std::vector<uint64_t>> codes =    {{20151125,  18749137, 17289845, 30943339, 10071777, 33511524},
                                                    { 31916031,  21629792, 16929656, 7726640,  15514188, 4041754 }, 
                                                    { 16080970,  8057251,  1601130,  7981243,  11661866, 16474243 },
                                                    { 24592653,  32451966, 21345942, 9380097,  10600672, 31527494},
                                                    { 77061,     17552253, 28094349, 6899651,  9250759,  31663883},
                                                    { 33071741,  6796745,  25397450, 24659492, 1534922,  27995004} };*/
    
    uint64_t multiplier = 252533, divisor = 33554393;
    std::vector<std::string> inputWords = parseStringToString(input[0], ' ');
    int rowLength = 2;
    uint64_t goalX = std::stoi(inputWords[18].substr(0, 4)), goalY = std::stoi(inputWords[16].substr(0, 4)), itX = 1, itY = 2, lastResult = 20151125;

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
    
}