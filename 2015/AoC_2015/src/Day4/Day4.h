#pragma once
#include <iostream>
#include "AoCUtilities.h"
#include "Cryptographics.h"

void AoC2015D4P1() {
    std::vector<std::string> input = getFileInput(".//src//Day4//Day4.txt");
    
    MD5 MD5Impl;
    MD5Impl.MD5CreateHash("Hello, world!");
}

void AoC2015D4P2() {
    std::vector<std::string> input = getFileInput(".//src//Day4//Day4.txt");
    
}