#pragma once
#include <iostream>
#include <string>
#include "AoCUtilities.h"

void AoC2015D5P1() {
    std::vector<std::string> input = getFileInput(".//src//Day5//Day5.txt");
    int niceCount = 0;
    std::string vowels = "aeiou";
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i].find("ab") == std::string::npos && input[i].find("cd") == std::string::npos && input[i].find("pq") == std::string::npos && input[i].find("xy") == std::string::npos) {
            char lastChar = ' ';
            int vowelCount = 0;
            bool doubleFlag = false;
            
            for (int j = 0; j < input[i].size() && (vowelCount < 3 || doubleFlag == false); j++) {
                if (vowelCount < 3) {
                    if (vowels.find(input[i][j]) != std::string::npos) {
                        vowelCount++;
                    }
                }
                if (doubleFlag == false) {
                    if (input[i][j] == lastChar) {
                        doubleFlag = true;
                    }
                }
                lastChar = input[i][j];
            }
            if (vowelCount >= 3 && doubleFlag == true) {
                niceCount++;
            }
        }
    }
    std::cout << niceCount << std::endl << std::endl;
}

void AoC2015D5P2() {
    std::vector<std::string> input = getFileInput(".//src//Day5//Day5.txt");
    int niceCount = 0;
    
    for (int i = 0; i < input.size(); i++) {
        bool oneApartFlag = false, pairsFlag = false;
        for (int j = 2; j < input[i].size() && oneApartFlag == false; j++) {
            if (oneApartFlag == false) {
                if (input [i][j] == input[i][j-2]) {
                    oneApartFlag = true;
                }
            }
        }
        if (oneApartFlag == true) {
            std::vector<std::string> pairs;
            for (int j = 1; j < input[i].size(); j++) {
                pairs.push_back(std::string(input[i][j-1] + input[i][j]));
            }
            for (int j = 0; j < pairs.size() - 2 && pairsFlag == false; j++) {
                for (int k = j + 2; k < pairs.size() && pairsFlag == false; k++) {
                    if (pairs[j] == pairs[k]) {
                        pairsFlag = true;
                        niceCount += 1;
                    }
                }
            }
        }
    }
    std::cout << niceCount << std::endl << std::endl;
}
