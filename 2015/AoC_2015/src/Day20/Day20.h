#pragma once
#include <iostream>
#include <cmath>
#include "AoCUtilities.h"

void AoC2015D20P1() {
    std::vector<std::string> input = getFileInput(".//src//Day20//Day20.txt");
    if (input[0] == "1") { std::cout << "1" << std::endl << std::endl; return; }

    bool found = false;
    int i = 2;

    while (!found) {
        int count = 1;
        for (int j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                count += j;
            }
        }
        if ((count + i) * 10 >= std::stoi(input[0])) {
            std::cout << std::to_string(i) << std::endl << std::endl;
            found = true;
        }
        i++;
    }
}

void AoC2015D20P2() {
    std::vector<std::string> input = getFileInput(".//src//Day20//Day20.txt");
    if (input[0] == "1") { std::cout << "1" << std::endl << std::endl; return; }

    bool found = false;
    int i = 2;
    std::vector<int> visited = { 0, 1 };

    while (!found) {
        int count = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                if (visited[j] < 50) {
                    count += j;
                    visited[j]++;
                }
            }
        }
        visited.push_back(1);

        if ((count + i) * 11 >= std::stoi(input[0])) {
            std::cout << std::to_string(i) << std::endl << std::endl;
            found = true;
        }
        i++;
    }
}
