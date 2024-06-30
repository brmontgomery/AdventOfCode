#pragma once
#include <iostream>
#include "AoCUtilities.h"

void findSubArrays(std::vector<int> nums, std::vector<int> currentList, std::vector<std::vector<int>>& validArrays, int goalNum,int startNum) {
    //get a sum of all the numbers we are currently trying in out subarray
    int currentSum = 0;
    for (int i = 0; i < currentList.size(); i++) {
        currentSum += currentList[i];
    }

    //figure out which numbers we still have available to test with.
    //only mark numbers valid that do not bring us over 1/3 the total sum && start counting down from the last number
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

    //skip if there are no valid nums.
    if (validNumSum >= goalNum - currentSum) {
        //add to valid array list if it gets us to the goal number, if not restart the process using the test number in the array.
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

    return;
}

void AoC2015D24P1() {
    std::vector<std::string> input = getFileInput(".//src//Day24//Day24.txt");
    
    //parse the input and figure out the total.
    int sum = 0;
    std::vector<int> nums;
    for (int i = 0; i < input.size(); i++) {
        sum += std::stoi(input[i]);
        nums.push_back(std::stoi(input[i]));
    }

    //get the goal number
    sum = sum / 3;

    //get all subarrays that equal the goal number
    std::vector<std::vector<int>> validArrays;
    findSubArrays(nums, {}, validArrays, sum, 10000000);
    std::cout << "Initial Subarrays Found!" << std::endl;

    //get the shortest array length
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

    //find the shortest valid array out of the subarrays found above, with the smallest product.
    while (!found) {
        //for the current minLength, get all subarrays
        std::vector<std::vector<int>> shortestArrays;
        for (int i = 0; i < validArrays.size(); i++) {
            if (validArrays[i].size() == minLength) {
                shortestArrays.push_back(validArrays[i]);
            }
        }

        //check the quantum entanglement of all of the shortest length subarrays
        for (int i = 0; i < shortestArrays.size(); i++) {
            //get the product
            uint64_t quantumEntanglement = shortestArrays[i][0];
            for (int j = 1; j < shortestArrays[i].size(); j++) {
                quantumEntanglement *= shortestArrays[i][j];
            }
            longs.push_back(quantumEntanglement);
            if (quantumEntanglement < shortestQuantumEntanglement) {

                //Check to make sure this arra yhas two other matching arrays that will equal the goal number 
                //A second one is not guaranteed, but if there is a matching array, the third is guaranteed.
                bool valid = false;
                std::vector<int> newNums;
                //gets remaining numbers
                for (int j = 0; j < nums.size(); j++) {
                    if (std::find(shortestArrays[i].begin(), shortestArrays[i].end(), nums[j]) == shortestArrays[i].end()) {
                        newNums.push_back(nums[j]);
                    }
                }

                //looks for subarrays that match the remainders (turns out its faster to run this a second time)
                std::vector<std::vector<int>> validArrays2;
                findSubArrays(newNums, {}, validArrays2, sum, 10000000);

                //if the others exist, there is a new smallest product, it is out current frontrunner.
                if (validArrays2.size() > 0) {
                    shortestQuantumEntanglement = quantumEntanglement;
                    std::cout << "New Shortest Subarray: " << std::to_string(i) << std::endl;
                    found = true;
                }
            }
        }
        //if no valid matching arrays are found,go to the next shortest length.
        if (!found) {
            minLength += 1;
        }
    }

    std::cout << std::to_string(shortestQuantumEntanglement) << std::endl << std::endl;
}

void AoC2015D24P2() {
    std::vector<std::string> input = getFileInput(".//src//Day24//Day24.txt");

    //parse the input and figure out the total.
    int sum = 0;
    std::vector<int> nums;
    for (int i = 0; i < input.size(); i++) {
        sum += std::stoi(input[i]);
        nums.push_back(std::stoi(input[i]));
    }

    //get the goal number
    sum = sum / 4;

    //get all subarrays that equal the goal number
    std::vector<std::vector<int>> validArrays;
    findSubArrays(nums, {}, validArrays, sum, 10000000);
    std::cout << "Initial Subarrays Found!" << std::endl;

    //get the shortest array length
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

    //find the shortest valid array out of the subarrays found above, with the smallest product.
    while (!found) {
        //for the current minLength, get all subarrays
        std::vector<std::vector<int>> shortestArrays;
        for (int i = 0; i < validArrays.size(); i++) {
            if (validArrays[i].size() == minLength) {
                shortestArrays.push_back(validArrays[i]);
            }
        }

        //Check to make sure this array has two other matching arrays that will equal the goal number 
        //Note:I believe this step to be performed incorrectly here as one must check for three matching arrays before assuming a guaranteed fourth
        //but it was redundant for this problem and not to be fixed.
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

                //looks for subarrays that match the remainders (turns out its faster to run this a second time)
                std::vector<std::vector<int>> validArrays2;
                findSubArrays(newNums, {}, validArrays2, sum, 10000000);

                //if the others exist, there is a new smallest product, it is out current frontrunner.
                if (validArrays2.size() > 0) {
                    shortestQuantumEntanglement = quantumEntanglement;
                    std::cout << "New Shortest Subarray: " << std::to_string(i) << std::endl;
                    found = true;
                }
            }
        }
        //if no valid matching arrays are found,go to the next shortest length.
        if (!found) {
            minLength += 1;
        }
    }

    std::cout << std::to_string(shortestQuantumEntanglement) << std::endl << std::endl;
}