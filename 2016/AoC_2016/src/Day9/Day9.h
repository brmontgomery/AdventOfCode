#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2016D9P1() {
    std::vector<std::string> input = getFileInput(".//src//Day9//Day9.txt");
    std::string newString = "";
    int length = 0;
    int repeat = 0;
    bool inLoop = false;

    removeSpaces(input[0]);

    for (int i = 0; i < input[0].size(); i++) {
        if (inLoop) {
            std::string tbr = input[0].substr(i, length);

            for (int j = 0; j < repeat; j++) {
                newString += tbr;
            }
            i += length-1;

            length = 0;
            repeat = 0;
            inLoop = false;

        } else if (input[0][i] == '(') {
            auto divider = input[0].substr(i).find('x') + i;
            auto end = input[0].substr(i).find(')') + i;

            if (divider != std::string::npos) {
                length = std::stoi(input[0].substr((i + 1), (divider - i - 1)));
                repeat = std::stoi(input[0].substr((divider + 1), (end - divider - 1)));
            }

            i = end;
            inLoop = true;
        }
        else {
            newString += input[0][i];
        }

    }

    std::cout << std::to_string(newString.size()) << std::endl;
}

void AoC2016D9P2() {
    std::vector<std::string> input = getFileInput(".//src//Day9//Day9.txt");
    float lengthOfString = 0;
    int currentMultiplier = 1;
    std::vector<std::pair<int, int>> lengths = {};

    for (int i = 0; i < input[0].size(); i++) {
        if (i == 17275) {
            std::cout << "stop";
        }
        if (input[0][i] == '(') {
            auto divider = input[0].substr(i).find('x') + i;
            auto end = input[0].substr(i).find(')') + i;

            if (divider != std::string::npos) {
                int length = std::stoi(input[0].substr((i + 1), (divider - i - 1)));
                int repeat = std::stoi(input[0].substr((divider + 1), (end - divider - 1)));
                lengths.push_back({ length, repeat });
                currentMultiplier *= repeat;
            }

            for (int j = 0; j < lengths.size()-1; j++) {
                lengths[j].first -= (end - i + 1);
                
                if (lengths[j].first <= 0) {
                    currentMultiplier /= lengths[j].second;
                    lengths.erase(lengths.begin() + j);
                    j -= 1;
                } 
            }

            i = end;
        }
        else {
            if (std::isalpha(input[0][i])) {

                lengthOfString += currentMultiplier;

                for (int j = 0; j < lengths.size(); j++) {
                    lengths[j].first -= 1;
                    if (lengths[j].first <= 0) {
                        currentMultiplier /= lengths[j].second;
                        lengths.erase(lengths.begin() + j);
                        j -= 1;
                    }
                    if (j > 0) {
                        if (lengths[j].first > lengths[j - 1].first) {
                            std::cout << "stop?";
                        }
                    }
                }
            }
        }

        
    }

    std::cout << std::to_string(lengthOfString) << std::endl;
}