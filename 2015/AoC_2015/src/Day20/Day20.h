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
        int count  = 1;
        for (int j = 2; j < sqrt(i); j++) {
            if (i % j == 0) {
                count += j;
            }
        }
        if ((count + i) * 10 == std::stoi(input[0])) {
            std::cout << std::to_string((count + i) * 10) << std::endl << std::endl;
            found = true;
        }
    }
}

void AoC2015D20P2() {
    std::vector<std::string> input = getFileInput(".//src//Day20//Day20.txt");
    
}
