#pragma once
#include <iostream>
#include "AoCUtilities.h"

void findSubArrays(std::vector<int> nums, std::vector<int> currentList, std::vector<std::vector<int>>& validArrays, int goalNum,int startNum) {
    int currentSum = 0;
    for (int i = 0; i < currentList.size(); i++) {
        currentSum += currentList[i];
    }

    //if (goalNum - currentSum < startNum) {
        std::vector<int> validNums;
        int validNumSum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= goalNum - currentSum && nums[i] < startNum) {
                if (std::find(currentList.begin(), currentList.end(), nums[i]) == currentList.end()) {
                    validNums.push_back(nums[i]);
                    validNumSum += nums[i];
                }
            }
        }

        if (validNumSum >= goalNum - currentSum) {
            for (int i = 0; i < validNums.size(); i++) {
                if (currentSum + validNums[i] == goalNum) {
                    currentList.push_back(validNums[i]);
                    validArrays.push_back(currentList);
                    return;
                }
                else {
                    std::vector<int> newCurrentList = currentList;
                    newCurrentList.push_back(validNums[i]);
                    findSubArrays(nums, newCurrentList, validArrays, goalNum, validNums[i]);
                }
            }
        }
    //}

    return;
}

void insertionSort(std::vector<std::vector<int>>& numList) {
    for (int i = 1; i < numList.size(); i++) {

        if (numList[i] < numList[i - 1]) {

            std::vector<int> key = numList[i];
            int j = i - 1;

            while (j >= 0 && numList[j].size() > key.size()) {
                numList[j + 1] = numList[j];
                j--;
            }

            numList[j + 1] = key;
        }
    }
}

void AoC2015D24P1() {
    std::vector<std::string> input = getFileInput(".//src//Day24//Day24.txt");
    
    int sum = 0;
    std::vector<int> nums;
    for (int i = 0; i < input.size(); i++) {
        sum += std::stoi(input[i]);
        nums.push_back(std::stoi(input[i]));
    }

    sum = sum / 3;

    std::vector<std::vector<int>> validArrays;
    findSubArrays(nums, {}, validArrays, sum, 10000000);
    //insertionSort(validArrays);
    std::cout << "Initial Subarrays Found!" << std::endl;
    int minLength = 100;
    for (int i = 0; i < validArrays.size(); i++) {
        if (validArrays[i].size() < minLength) {
            minLength = validArrays[i].size();
        }
    }

    bool found = false;
    int lastRoundMinLength = 0;
    uint64_t shortestQuantumEntanglement = 1000000000000000000;

    std::vector<uint64_t> longs;

    while (!found) {
        std::vector<std::vector<int>> shortestArrays;
        for (int i = 0; i < validArrays.size(); i++) {
            if (validArrays[i].size() == minLength) {
                shortestArrays.push_back(validArrays[i]);
            }
        }

        
        for (int i = 0; i < shortestArrays.size(); i++) {
            uint64_t quantumEntanglement = shortestArrays[i][0];
            for (int j = 1; j < shortestArrays[i].size(); j++) {
                quantumEntanglement *= shortestArrays[i][j];
            }
            longs.push_back(quantumEntanglement);
            if (quantumEntanglement < shortestQuantumEntanglement) {

                //check if there are two other equal arrays
                bool valid = false;
                std::vector<int> newNums;
                for (int j = 0; j < nums.size(); j++) {
                    if (std::find(shortestArrays[i].begin(), shortestArrays[i].end(), nums[j]) == shortestArrays[i].end()) {
                        newNums.push_back(nums[j]);
                    }
                }

                std::vector<std::vector<int>> validArrays2;
                findSubArrays(newNums, {}, validArrays2, sum, 10000000);


                if (validArrays2.size() > 0) {
                    shortestQuantumEntanglement = quantumEntanglement;
                    std::cout << "New Shortest Subarray: " << std::to_string(i) << std::endl;
                    found = true;
                }
            }
        }
        if (!found) {
            minLength += 1;
        }
    }

    std::cout << std::to_string(shortestQuantumEntanglement) << std::endl << std::endl;
}

void AoC2015D24P2() {
    std::vector<std::string> input = getFileInput(".//src//Day24//Day24.txt");

    int sum = 0;
    std::vector<int> nums;
    for (int i = 0; i < input.size(); i++) {
        sum += std::stoi(input[i]);
        nums.push_back(std::stoi(input[i]));
    }

    sum = sum / 4;

    std::vector<std::vector<int>> validArrays;
    findSubArrays(nums, {}, validArrays, sum, 10000000);
    //insertionSort(validArrays);
    std::cout << "Initial Subarrays Found!" << std::endl;
    int minLength = 100;
    for (int i = 0; i < validArrays.size(); i++) {
        if (validArrays[i].size() < minLength) {
            minLength = validArrays[i].size();
        }
    }

    bool found = false;
    int lastRoundMinLength = 0;
    uint64_t shortestQuantumEntanglement = 1000000000000000000;

    std::vector<uint64_t> longs;

    while (!found) {
        std::vector<std::vector<int>> shortestArrays;
        for (int i = 0; i < validArrays.size(); i++) {
            if (validArrays[i].size() == minLength) {
                shortestArrays.push_back(validArrays[i]);
            }
        }


        for (int i = 0; i < shortestArrays.size(); i++) {
            uint64_t quantumEntanglement = shortestArrays[i][0];
            for (int j = 1; j < shortestArrays[i].size(); j++) {
                quantumEntanglement *= shortestArrays[i][j];
            }
            longs.push_back(quantumEntanglement);
            if (quantumEntanglement < shortestQuantumEntanglement) {

                //check if there are two other equal arrays
                bool valid = false;
                std::vector<int> newNums;
                for (int j = 0; j < nums.size(); j++) {
                    if (std::find(shortestArrays[i].begin(), shortestArrays[i].end(), nums[j]) == shortestArrays[i].end()) {
                        newNums.push_back(nums[j]);
                    }
                }

                std::vector<std::vector<int>> validArrays2;
                findSubArrays(newNums, {}, validArrays2, sum, 10000000);


                if (validArrays2.size() > 0) {
                    shortestQuantumEntanglement = quantumEntanglement;
                    std::cout << "New Shortest Subarray: " << std::to_string(i) << std::endl;
                    found = true;
                }
            }
        }
        if (!found) {
            minLength += 1;
        }
    }

    std::cout << std::to_string(shortestQuantumEntanglement) << std::endl << std::endl;
}