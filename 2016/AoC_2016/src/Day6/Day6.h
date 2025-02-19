#pragma once
#include <iostream>
#include <map>
#include "AoCUtilities.h"

void AoC2016D6P1() {
    std::vector<std::string> input = getFileInput(".//src//Day6//Day6.txt");
    std::string key = "";

    for (int i = 0; i < input[0].size(); i++) {
        std::map<char, int> charCounts;

        for (int j = 0; j < input.size(); j++) {
            //find the item in the map
            auto search = charCounts.find(input[j][i]);

            //if found increase count
            if (search != charCounts.end()) {
                search->second++;
            }
            else {
                //otherwise add a new map entry
                std::pair<char, int> newPair(input[j][i], 1);
                charCounts.insert(newPair);
            }
        }

        int max = 0;
        std::string matches = "";
        std::map<char, int>::iterator it;

        //pick out the kays that have the largest counts
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

        key += matches;
    }

    std::cout << key << std::endl;
}

void AoC2016D6P2() {
    std::vector<std::string> input = getFileInput(".//src//Day6//Day6.txt");
    std::string key = "";

    for (int i = 0; i < input[0].size(); i++) {
        std::map<char, int> charCounts;

        for (int j = 0; j < input.size(); j++) {
            //find the item in the map
            auto search = charCounts.find(input[j][i]);

            //if found increase count
            if (search != charCounts.end()) {
                search->second++;
            }
            else {
                //otherwise add a new map entry
                std::pair<char, int> newPair(input[j][i], 1);
                charCounts.insert(newPair);
            }
        }

        int least = 100;
        std::string matches = "";
        std::map<char, int>::iterator it;

        //pick out the kays that have the largest counts
        for (it = charCounts.begin(); it != charCounts.end(); it++) {
            if (it->second < least) {
                matches = "";
                matches += it->first;
                least = it->second;
            }
            else if (it->second == least) {
                matches += it->first;
            }
        }

        key += matches;
    }

    std::cout << key << std::endl;
}
