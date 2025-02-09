#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include "AoCUtilities.h"

//see my MD5 implementation in the Utilities folder, most of the work for this problem went there

void AoC2016D4P1() {
    std::vector<std::string> input = getFileInput(".//src//Day4//Day4.txt");
    std::vector<std::string> checkSums;
    std::vector<int> roomNumbers;
    std::vector<std::string> names;
    int sum = 0;

    for (int i = 0; i < input.size(); i++) {
        auto pos = input[i].find_last_of('-');
        auto posB1 = input[i].find_first_of('['); 

        checkSums.push_back(input[i].substr(posB1 + 1, 5));
        roomNumbers.push_back(std::stoi(input[i].substr(pos+1, posB1-(pos+1))));
        names.push_back(input[i].substr(0, pos));
    }

    for (int i = 0; i < input.size(); i++) {
        //get char counts
        std::map<char, int> charCounts;
        for (int j = 0; j < names[i].size(); j++) {
            if (names[i][j] != '-') {
                auto search = charCounts.find(names[i][j]);
                if (search != charCounts.end()) {
                    search->second++;
                }
                else {
                    std::pair<char, int> newPair(names[i][j], 1);
                    charCounts.insert(newPair);
                }
            }
        }

        std::string key = "";
        while (key.size() < 5) {
            int max = 0;
            std::string matches = "";
            std::map<char, int>::iterator it;

            for (it = charCounts.begin(); it != charCounts.end(); it++) {
                if (it->second > max) {
                    matches = "";
                    matches += it->first;
                    max = it->second;
                } else if (it->second == max) {
                    matches += it->first;
                }
            }

            for (int j = 0; j < matches.size(); j++) {
                charCounts.erase(matches[j]);
            }

            std::sort(matches.begin(), matches.end());
            if (matches.size() > 5 - key.size()) {
                key += matches.substr(0, 5 - key.size());
            }
            else {
                key += matches;
            }
        }

        if (key == checkSums[i]) {
            sum += roomNumbers[i];
        }
    }

    std::cout << std::to_string(sum) << std::endl;
}

void AoC2016D4P2() {
    std::vector<std::string> input = getFileInput(".//src//Day4//Day4.txt");
    std::vector<std::string> checkSums;
    std::vector<int> roomNumbers;
    std::vector<std::string> names;
    std::vector<int> realRooms;

    for (int i = 0; i < input.size(); i++) {
        auto pos = input[i].find_last_of('-');
        auto posB1 = input[i].find_first_of('[');

        checkSums.push_back(input[i].substr(posB1 + 1, 5));
        roomNumbers.push_back(std::stoi(input[i].substr(pos + 1, posB1 - (pos + 1))));
        names.push_back(input[i].substr(0, pos));
    }

    for (int i = 0; i < input.size(); i++) {
        //get char counts
        std::map<char, int> charCounts;
        for (int j = 0; j < names[i].size(); j++) {
            if (names[i][j] != '-') {
                auto search = charCounts.find(names[i][j]);
                if (search != charCounts.end()) {
                    search->second++;
                }
                else {
                    std::pair<char, int> newPair(names[i][j], 1);
                    charCounts.insert(newPair);
                }
            }
        }

        std::string key = "";
        while (key.size() < 5) {
            int max = 0;
            std::string matches = "";
            std::map<char, int>::iterator it;

            for (it = charCounts.begin(); it != charCounts.end(); it++) {
                if (it->second > max) {
                    matches = "";
                    matches += it->first;
                    max = it->second;
                }
                else if (it->second == max) {
                    matches += it->first;
                }
            }

            for (int j = 0; j < matches.size(); j++) {
                charCounts.erase(matches[j]);
            }

            std::sort(matches.begin(), matches.end());
            if (matches.size() > 5 - key.size()) {
                key += matches.substr(0, 5 - key.size());
            }
            else {
                key += matches;
            }
        }

        if (key == checkSums[i]) {
            realRooms.push_back(i);
        }
    }

    std::vector<std::string> newNames;
    for (int i = 0; i < realRooms.size(); i++) {
        std::string newString = "";
        int cypherFactor = roomNumbers[realRooms[i]] % 26;

        for (int j = 0; j < names[realRooms[i]].size(); j++) {
            if (names[realRooms[i]][j] == '-') {
                newString += ' ';
            }
            else {
                int asciiValue = static_cast<int>(names[realRooms[i]][j]);
                asciiValue += cypherFactor;
                if (asciiValue > 122) {
                    asciiValue -= 26;
                }
                newString += (char)asciiValue;
            }
        }
        if (newString == "northpole object storage") {
            std::cout << std::to_string(roomNumbers[realRooms[i]]) << std::endl;
        }
    }
}