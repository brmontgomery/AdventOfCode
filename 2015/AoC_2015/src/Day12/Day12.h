#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D12P1() {
    std::vector<std::string> input = getFileInput(".//src//Day12//Day12.txt");

    int sum = 0;
    
    for (int i = 0; i < input[0].size(); i++) {
        if (input[0][i] == '-') {
            int digits = 1;
            std::string convert = "-";
            while (input[0][i + digits] >= 48 && input[0][i + digits] <= 57) {
                convert += input[0][i + digits];
                digits++;
            }
            sum += std::stoi(convert);
            i += digits - 1;
        } else if (isNumber(std::to_string(input[0][i]))) {
            int digits = 0;
            std::string convert = "";
            while (input[0][i + digits] >= 48 && input[0][i + digits] <= 57) {
                convert += input[0][i + digits];
                digits++;
            }
            if (convert != "") {
                sum += std::stoi(convert);
                i += digits - 1;
            }
        }
    }

    std::cout << sum << std::endl << std::endl;
}

void AoC2015D12P2() {
    std::vector<std::string> input = getFileInput(".//src//Day12//Day12.txt");

    int sum = 0;
    int bracketCount = 0;
    int lowestRedBracket = -1;
    int sumSinceLastBracket = 0;
    std::vector<std::pair<char,int>> sumSinceLastBracketVec = { {'{', 0} };

    for (int i = 0; i < input[0].size(); i++) {
        if (input[0][i] == '{') {
            bracketCount++;
            sumSinceLastBracketVec[bracketCount - 1].second += sumSinceLastBracket;
            sumSinceLastBracketVec.push_back(std::pair<char, int> {'{', 0});

            sumSinceLastBracket = 0;
        }
        else if (input[0][i] == '[') {
            bracketCount++;
            sumSinceLastBracketVec[bracketCount - 1].second += sumSinceLastBracket;
            sumSinceLastBracketVec.push_back({ '[', 0 });

            sumSinceLastBracket = 0;
        }
        else if (input[0][i] == '}' || input[0][i] == ']') {
            sumSinceLastBracketVec[bracketCount - 1].second += sumSinceLastBracket + sumSinceLastBracketVec[bracketCount].second;
            sumSinceLastBracketVec.pop_back();

            sumSinceLastBracket = 0;
            if (lowestRedBracket != -1) {
                if (bracketCount <= lowestRedBracket) {
                    lowestRedBracket = -1;
                }
            }
            bracketCount--;
        }
        else if (input[0][i] == 'r' && sumSinceLastBracketVec[bracketCount].first == '{') {
            if (i + 2 < input[0].size()) {
                if (input[0][i + 1] == 'e' && input[0][i + 2] == 'd') {
                    if (lowestRedBracket == -1) 
                    { 
                        lowestRedBracket = bracketCount;
                        sumSinceLastBracketVec[bracketCount].second += sumSinceLastBracket;
                        sumSinceLastBracketVec[bracketCount].second = 0;
                        sumSinceLastBracket = 0;
                    }
                    i += 2;
                }
            }
        }
        else if (input[0][i] == '-' && lowestRedBracket == -1) {
            int digits = 1;
            std::string convert = "-";
            while (input[0][i + digits] >= 48 && input[0][i + digits] <= 57) {
                convert += input[0][i + digits];
                digits++;
            }
            if (convert != "") {
                sumSinceLastBracket += std::stoi(convert);
                i += digits - 1;
            }
        }
        else if (isNumber(std::to_string(input[0][i])) && lowestRedBracket == -1) {
            int digits = 0;
            std::string convert = "";
            while (input[0][i + digits] >= 48 && input[0][i + digits] <= 57) {
                convert += input[0][i + digits];
                digits++;
            }
            if (convert == "138") {
                std::cout << convert << std::endl;
            }
            if (convert != "") {
                sumSinceLastBracket += std::stoi(convert);
                i += digits - 1;
            }
        }
    }

    std::cout << sumSinceLastBracketVec[0].second << std::endl << std::endl;
    
}
