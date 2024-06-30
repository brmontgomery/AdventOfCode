#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D10P1() {
    std::vector<std::string> input = getFileInput(".//src//Day10//Day10.txt");

    int count = 0, charCount = 0;
    std::string result;
    //for each loop, replace all consecutive same characters in the input with a number saying how many of that number there were and the number (11 becomes 21)
    while (count < 40) {
        result = "";
        charCount = 0;
        char lastChar = NULL;
        for (int i = 0; i < input[0].size(); i++) {
            if (lastChar == NULL) {
                lastChar = input[0][i];
                charCount += 1;
            } else if (lastChar != input[0][i]) {
                result += std::to_string(charCount) + lastChar;
                charCount = 1;
                lastChar = input[0][i];
            } else {
                charCount += 1;
            }
        }
        result += std::to_string(charCount) + lastChar;
        input[0] = result;
        count++;
    }
    std::cout << input[0].size() << std::endl << std::endl;
}

void AoC2015D10P2() {
    std::vector<std::string> input = getFileInput(".//src//Day10//Day10.txt");

    int count = 0, charCount = 0;
    std::string result;
    //for each loop, replace all consecutive same characters in the input with a number saying how many of that number there were and the number (11 becomes 21)
    while (count < 50) {
        result = "";
        charCount = 0;
        char lastChar = NULL;
        for (int i = 0; i < input[0].size(); i++) {
            if (lastChar == NULL) {
                lastChar = input[0][i];
                charCount += 1;
            }
            else if (lastChar != input[0][i]) {
                result += std::to_string(charCount) + lastChar;
                charCount = 1;
                lastChar = input[0][i];
            }
            else {
                charCount += 1;
            }
        }
        result += std::to_string(charCount) + lastChar;
        input[0] = result;
        count++;
    }
    std::cout << input[0].size() << std::endl << std::endl;
}
