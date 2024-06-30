#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D23P1() {
    std::vector<std::string> input = getFileInput(".//src//Day23//Day23.txt");

    //initialize registers
    int registerA = 0, registerB = 0;
    int stepNum = 0;
    
    //loop through the program until wehave surpassed its end on the step Counter
    while (stepNum < input.size() && stepNum >= 0) {
        std::vector<std::string> stepInputs = parseStringToString(input[stepNum], ' ');
        int jumpAmount = 1;
        //when instruction is "hlf" take specified register and divide by 2
        if (stepInputs[0] == "hlf") {
            if (stepInputs[1] == "a") {
                registerA = registerA / 2;
            } else {
                registerB = registerB / 2;
            }
        //when instruction is "tpl" take specified register and multiply by 3
        } else if (stepInputs[0] == "tpl") {
            if (stepInputs[1] == "a") {
                registerA = registerA * 3;
            } else {
                registerB = registerB * 3;
            }
        //when instruction is "inc" take add 1 to specified register
        } else if (stepInputs[0] == "inc") {
            if (stepInputs[1] == "a") {
                registerA += 1;
            } else {
                registerB += 1;
            }
        //when instruction is "jmp" increment stepcounter by specified value (positive or negative))
        } else if (stepInputs[0] == "jmp") {
            if (stepInputs[1][0] == '+') {
                jumpAmount = std::stoi(stepInputs[1].substr(1));
            } else {
                jumpAmount = -std::stoi(stepInputs[1].substr(1));
            }
        //when instruction is "jie" increment stepcounter by specified value (positive or negative)) only if the specified register is even
        } else if (stepInputs[0] == "jie") {
            if (stepInputs[1][0] == 'a' && registerA % 2 == 0) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                } else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            } else if (stepInputs[1][0] == 'b' && registerB % 2 == 0) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                } else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            }
         //when instruction is "jio" increment stepcounter by specified value (positive or negative)) only if the specified register is equal to 1
        } else if (stepInputs[0] == "jio") {
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

    uint32_t registerA = 1, registerB = 0;
    int stepNum = 0;

    while (stepNum < input.size() && stepNum >= 0) {
        std::vector<std::string> stepInputs = parseStringToString(input[stepNum], ' ');
        int jumpAmount = 1;
        //when instruction is "hlf" take specified register and divide by 2
        if (stepInputs[0] == "hlf") {
            if (stepInputs[1] == "a") {
                registerA = registerA / 2;
            }
            else {
                registerB = registerB / 2;
            }
        }
        //when instruction is "tpl" take specified register and multiply by 3
        else if (stepInputs[0] == "tpl") {
            if (stepInputs[1] == "a") {
                registerA = registerA * 3;
            }
            else {
                registerB = registerB * 3;
            }
        }
        //when instruction is "inc" take add 1 to specified register
        else if (stepInputs[0] == "inc") {
            if (stepInputs[1] == "a") {
                registerA += 1;
            }
            else {
                registerB += 1;
            }
        }
        //when instruction is "jmp" increment stepcounter by specified value (positive or negative))
        else if (stepInputs[0] == "jmp") {
            if (stepInputs[1][0] == '+') {
                jumpAmount = std::stoi(stepInputs[1].substr(1));
            }
            else {
                jumpAmount = -std::stoi(stepInputs[1].substr(1));
            }
        }
        //when instruction is "jie" increment stepcounter by specified value (positive or negative)) only if the specified register is even
        else if (stepInputs[0] == "jie") {
            if (stepInputs[1][0] == 'a' && registerA % 2 == 0) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                }
                else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            }
            else if (stepInputs[1][0] == 'b' && registerB % 2 == 0) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                }
                else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            }
        }
        //when instruction is "jio" increment stepcounter by specified value (positive or negative)) only if the specified register is equal to 1
        else if (stepInputs[0] == "jio") {
            if (stepInputs[1][0] == 'a' && registerA == 1) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                }
                else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            }
            else if (stepInputs[1][0] == 'b' && registerB == 1) {
                if (stepInputs[2][0] == '+') {
                    jumpAmount = std::stoi(stepInputs[2].substr(1));
                }
                else {
                    jumpAmount = -std::stoi(stepInputs[2].substr(1));
                }
            }
        }
        stepNum += jumpAmount;
    }

    std::cout << std::to_string(registerB) << std::endl << std::endl;
}
