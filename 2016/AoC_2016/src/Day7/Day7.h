#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2016D7P1() {
    std::vector<std::string> input = getFileInput(".//src//Day7//Day7.txt");
    int count = 0;

    for (int i = 0; i < input.size(); i++) {
        bool insideBrackets = false;
        bool foundInside = false;
        bool foundOutside = false;

        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == '[') {
                insideBrackets = true;
            }
            else if (input[i][j] == ']') {
                insideBrackets = false;
            }
            else if (j >= 3) {
                std::string search = input[i].substr(j-3, 4);

                if (search[0] == search[3] && search[1] == search[2] && search[0] != search[1]) {
                    if (insideBrackets) {
                        foundInside = true;
                    }
                    else {
                        foundOutside = true;
                    }
                }
            }
        }

        if (!foundInside && foundOutside) {
            count++;
        }
    }

    std::cout << std::to_string(count) << std::endl;
}

void AoC2016D7P2() {
    std::vector<std::string> input = getFileInput(".//src//Day7//Day7.txt");
    int count = 0;

    for (int i = 0; i < input.size(); i++) {
        bool insideBrackets = false;
        bool foundInside = false;
        bool foundOutside = false;
        std::vector<std::string> aba;
        std::vector<std::string> bab;

        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == '[') {
                insideBrackets = true;
            }
            else if (input[i][j] == ']') {
                insideBrackets = false;
            }
            else if (j >= 2) {
                std::string search = input[i].substr(j - 2, 3);

                if (search[0] == search[2] && search[0] != search[1]) {
                    if (!insideBrackets) {
                        aba.push_back(search);
                    }
                    else {
                        bab.push_back(search);
                    }
                }
            }
        }

        bool flag = false;
        for (int k = 0; k < aba.size() && !flag; k++) {
            for (int l = 0; l < bab.size() && !flag; l++) {
                if (aba[k][0] == bab[l][1] && aba[k][2] == bab[l][1] && aba[k][1] == bab[l][0]) {
                    count++;
                    flag = true;
                }
            }
        }
    }

    std::cout << std::to_string(count) << std::endl;
    

}