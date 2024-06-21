#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D23P1() {
    std::vector<std::string> input = getFileInput(".//src//Day23//Day23.txt");

    int registerA = 0, registerB = 0;
    int stepNum = 0;
    
    while (stepNum < input.size() && stepNum >= 0) {
        std::vector<std::string> stepInputs = parseStringFromString(input[stepNum], ' ');
        int jumpAmount = 1;
        if (stepInputs[0] == "hlf") {
            if (stepInputs[1] == "a") {
                registerA = registerA / 2;
            } else {
                registerB = registerB / 2;
            }
        } else if (stepInputs[0] == "tpl") {
            if (stepInputs[1] == "a") {
                registerA = registerA * 3;
            } else {
                registerB = registerB * 3;
            }
        } elseif (stepInputs[0] == "inc") {
            if (stepInputs[1] == "a") {
                registerA += 1;
            } else {
                registerB += 1;
            }
        } elseif (stepInputs[0] == "jmp") {
            if (stepInputs[1][0] == '+') {
                jumpAmount = std::stoi(stepInputs[1].substr(1));
            } else {
                jumpAmount = -std::stoi(stepInputs[1].substr(1));
            }
        } elseif (stepInputs[0] == "jie") {
            if (stepInputs[1] == 'a' && registerA % 2 == 0) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                } else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            } else if (stepInputs[1] == 'b' && registerB % 2 == 0) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                } else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            }
        } elseif (stepInputs[0] == "jio") {
            if (stepInputs[1][0] == 'a' && registerA == 1) {
                if (stepInputs[2][0] == '+') {
                    stepNum += std::stoi(stepInputs[2].substr(1));
                } else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            } else if (stepInputs[1][0] == 'b' && registerB == 1) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                } else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            }
        }
        stepNum += jumpAmount;
    }

    std::cout << std::to_string(registerB) << std::endl << std::endl;
}

void AoC2015D23P2() {
    std::vector<std::string> input = getFileInput(".//src//Day23//Day23.txt");
    
}
