#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D10P1() {
    std::vector<std::string> input = getFileInput(".//src//Day10//Day10.txt");

    int count = 0, charCount = 0;
    std::string result;
    while (count < 40) {
        result = "";
        charCount = 0;
        char lastChar = '';
        for (int i = 0; i < input[0].size(); i++) {
            if (lastChar == '') {
                lastChar = input[0][i];
                charCount += 1;
            } else if (lastChar != input[0][i]) {
                result += std::to_string(charCount) + lastChar;
                charCount = 1;
                lastChar = input[0][i];
            } else {
                charCount += 1;
            }
            result += std::to_string(charCount) + lastChar;
            input[i] = result;
        }
    }
    std::cout << input[i] << std::endl << std::endl;
}

void AoC2015D10P2() {
    std::vector<std::string> input = getFileInput(".//src//Day10//Day10.txt");
    
}
