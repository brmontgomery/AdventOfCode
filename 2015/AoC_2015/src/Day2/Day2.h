#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D2P1() {
    std::vector<std::string> input = getFileInput(".//src//Day2//Day2.txt");
    std::vector<std::vector<int>> dimensions;
    for (int i = 0; i < input.size(); i++) {
        dimensions.push_back(parseString<std::vector<int>>(input[i],'x'));
    }
    int totalSA = 0;
    for (int i = 0; i < dimensions.size(); i++) {
        int lowest = 0;
        int lw = dimensions[i][0] * dimensions[i][1];
        int lh = dimensions[i][0] * dimensions[i][2];
        if (lh < lw) {
            lowest = lh;
        }
        else {
            lowest = lw;
        }
        int wh = dimensions[i][1] * dimensions[i][2];
        if (wh < lowest) {
            lowest = wh;
        }
        totalSA += (2 * (lw + lh + wh)) + lowest;
    }

    std::cout << totalSA << std::endl;
}

void AoC2015D2P2() {
    std::vector<std::string> input = getFileInput(".//src//Day2//Day2.txt");
    std::vector<std::vector<int>> dimensions;
    for (int i = 0; i < input.size(); i++) {
        dimensions.push_back(parseString<std::vector<int>>(input[i], 'x'));
    }
    int totalRibbon = 0;
    for (int i = 0; i < dimensions.size(); i++) {
        int highest = dimensions[i][0];
        if (highest < dimensions[i][1]) {
            highest = dimensions[i][1];
            totalRibbon += 2 * dimensions[i][0];
        }
        else {
            totalRibbon += 2 * dimensions[i][1];
        }
        if (highest < dimensions[i][2]) {
            totalRibbon += 2 * highest;
        }
        else {
            totalRibbon += 2 * dimensions[i][2];
        }

        totalRibbon += (dimensions[i][0] * dimensions[i][1] * dimensions[i][2]);
    }

    std::cout << totalRibbon << std::endl;
}