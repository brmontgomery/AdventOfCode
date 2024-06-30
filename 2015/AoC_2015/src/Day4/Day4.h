#pragma once
#include <iostream>
#include <thread>
#include "AoCUtilities.h"
#include "Cryptographics.h"

//see my MD5 implementation in the Utilities folder, most of the work for this problem went there

void AoC2015D4P1() {
    std::vector<std::string> input = getFileInput(".//src//Day4//Day4.txt");
    
    MD5 MD5Impl;
    std::string searchString = "00000";
    std::string output;
    uint32_t currentInt = 0;
    std::string code;

    //finds the lowest positive number that returns an MD5 hash that starts with 5 leading zeroes
    while (output.substr(0, 5) != searchString) {
        code = input[0] + std::to_string(currentInt);
        output = MD5Impl.MD5CreateHash(code);
        currentInt++;
    }
    
    std::cout << code << std::endl << std::endl;
}

void AoC2015D4P2() {
    std::vector<std::string> input = getFileInput(".//src//Day4//Day4.txt");
    
    MD5 MD5Impl;
    std::string searchString = "000000";
    std::string output;
    uint32_t currentInt = 0;
    std::string code;

    //finds the lowest positive number that returns an MD5 hash that starts with 6 leading zeroes
    while (output.substr(0, 6) != searchString) {
        if (currentInt % 1000000 == 0) {
            std::cout << currentInt;
        }
        code = input[0] + std::to_string(currentInt);
        output = MD5Impl.MD5CreateHash(code);
        currentInt++;
    }

    std::cout << code << std::endl << std::endl;
}