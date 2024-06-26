#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D17P1() {
    std::vector<std::string> input = getFileInput(".//src//Day17//Day17.txt");

    int count = 0;
    int max = 1 << input.size();
    //since all combinations is equivalent to 2 ^ n (number of items), we can represent the combination list as an index from 0 to (2^20)-1
    for (int i = 0; i < max; i++) {
        int sum = 0;
        //for each index add up the values of items corresponding to positive bits
        for (int j = 0; j < input.size(); j++) {
            if ((i >> j) & 1) {
                sum += std::stoi(input[j]);
            }
        }
        //add to count if they equal 150
        if (sum == 150) {
            count++;
        }
    }

    std::cout << count << std::endl<< std::endl;
}

void AoC2015D17P2() {
    std::vector<std::string> input = getFileInput(".//src//Day17//Day17.txt");
    
    int count = 0;
    int max = 1 << input.size();
    int minContainers = input.size();

    //since all combinations is equivalent to 2 ^ n (number of items), we can represent the combination list as an index from 0 to (2^20)-1
    for (int i = 0; i < max; i++) {
        int sum = 0;
        int containerCount = 0;
        //for each index add up the values of items corresponding to positive bits
        for (int j = 0; j < input.size(); j++) {
            if ((i >> j) & 1) {
                sum += std::stoi(input[j]);
                containerCount++;
            }
        }
        //add to count if they equal 150
        if (sum == 150) {
            if (containerCount < minContainers) {
                minContainers = containerCount;
                count = 1;
            } else if (containerCount == minContainers) {
                count++;
            }
        }
    }

    std::cout << count << std::endl << std::endl;
}
