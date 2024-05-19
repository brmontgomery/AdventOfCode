#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D8P1() {
    std::vector<std::string> input = getFileInput(".//src//Day8//Day8.txt");
    int codeCharCount = 0;
    int memCharCount = 0;

    for (int i = 0; i < input.size(); i++) {
        codeCharCount += input[i].size();
        input[i] = input[i].substr(1, input[i].size() - 2);
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == '\\') {
                if (input[i][j + 1] == 'x') {
                    j += 3;
                }
                else {
                    j += 1;
                }
            }
            memCharCount += 1;
        }
    }

    std::cout << codeCharCount - memCharCount;
}

void AoC2015D8P2() {
    std::vector<std::string> input = getFileInput(".//src//Day8//Day8.txt");
    int codeCharCount = 0;
    int newCodeCharCount = 0;

    for (int i = 0; i < input.size(); i++) {
        codeCharCount += input[i].size();
        newCodeCharCount += 2;
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == '\\') {
                newCodeCharCount += 2;
            }
            else if (input[i][j] == '\"') {
                newCodeCharCount += 2;
            }
            else {
                newCodeCharCount += 1;
            }
        }
    }

    std::cout << newCodeCharCount - codeCharCount;
}