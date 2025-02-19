#pragma once
#include <iostream>
#include <cctype>
#include <algorithm>
#include "Cryptographics.h"
#include "AoCUtilities.h"

void AoC2016D5P1() {
    std::vector<std::string> input = getFileInput(".//src//Day5//Day5.txt");
    std::string key = "";
    int index = 0;
    MD5 md5;

    while (key.size() < 8) {
        std::string hash = input[0] + std::to_string(index);

        hash = md5.MD5CreateHash(hash);
        if (hash.substr(0, 5) == "00000") {
            key = key + hash[5];
        }

        index++;
    }

    std::cout << key << std::endl;
}

void AoC2016D5P2() {
    std::vector<std::string> input = getFileInput(".//src//Day5//Day5.txt");
    std::string key = "";
    int index = 0;
    MD5 md5;
    std::vector<int> positions;
    std::string newKey = "--------";

    while (key.size() < 8) {
        std::string hash = input[0] + std::to_string(index);

        hash = md5.MD5CreateHash(hash);
        if (hash.substr(0, 5) == "00000" && std::isdigit(hash[5])) {
            if (hash[5] - '0' < 8 && std::find(positions.begin(), positions.end(), hash[5] - '0') != positions.end() == false) {
                positions.push_back(hash[5] - '0');
                key = key + hash[6];
            }
        }

        index++;
    }

    for (int i = 0; i < 8; i++) {
        newKey[positions[i]] = key[i];
    }
    std::cout << newKey << std::endl;
    
}
