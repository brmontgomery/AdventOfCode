#pragma once
#include <iostream>
#include <string>
#include "AoCUtilities.h"

void AoC2015D5P1() {
    std::vector<std::string> input = getFileInput(".//src//Day5//Day5.txt");
    int niceCount = 0;
    std::string vowels = "aeiou";
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i].find("ab") != std::string::npos && input[i].find("cd") != std::string::npos && input[i].find("pq") != std::string::npos && input[i].find("xy") != std::string::npos) {
            char lastChar = '';
            int vowelCount = 0;
            bool doubleFlag = false;
            
            for (int j = 0; j < input[i].size() && (vowelCount < 3 || doubleFlag == false); i++) {
                if (vowelCount < 3) {
                    if (vowels.find(input[i][j]) != std::string::npos) {
                        vowelCount++;
                    }
                }
                if (doubleFlag = false) {
                    if (input[i][j] == lastChar) {
                        doubleFlag = true;
                    }
                }
                lastChar = input[i][j];
            }
            if (vowelCount >= 3 && doubleFlag = true) {
                niceCount++;
            }
        }
    }
    std::cout << niceCount << std::endl << std::endl;
}

void AoC2015D5P2() {
    std::vector<std::string> input = getFileInput(".//src//Day5//Day5.txt");
    
}
