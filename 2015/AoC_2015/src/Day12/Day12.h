#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D12P1() {
    std::vector<std::string> input = getFileInput(".//src//Day12//Day12.txt");

    int sum = 0;
    
    for (int i = 0; i < input[0].size(); i++) {
        if (input[0][i] == '-') {
            int digits = 1;
            std::string convert = "-";
            while (isNumber(input[0][i + digits])) {
                convert += input[0][i + digits];
                digits++;
            }
            sum += std::stoi(convert);
        } else if (input[0][i].isNumeric()) {
            int digits = 0;
            std::string convert = "";
            while (isNumber(input[0][i + digits])) {
                convert += input[0][i + digits];
                digits++;
            }
            sum += std::stoi(convert);
        }
    }

    std::cout << sum << std::endl << std::endl;
}

void AoC2015D12P2() {
    std::vector<std::string> input = getFileInput(".//src//Day12//Day12.txt");
    
}
