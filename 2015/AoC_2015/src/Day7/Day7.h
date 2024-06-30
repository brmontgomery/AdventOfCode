#pragma once
#include <iostream>
#include <map>
#include "AoCUtilities.h"

struct Gate {
    std::string input1;
    std::string input2;
    uint16_t value;
    std::string operation;
};

uint16_t getValueOfGate(std::string gateKey, std::map<std::string, Gate>& gates) {
    Gate gate = gates[gateKey];
    uint16_t input1Value = 0;
    uint16_t input2Value = 0;

    //for the current gate we are attmepting to solve, return value if it is just a value
    if (gate.operation != "") {
        //if it has no input values, return 0
        if (gate.input1 != "") {
            //if an input exists, either get its precalculated value, or calculate its value;
            if (gates[gate.input1].value == 0) {
                input1Value = getValueOfGate(gate.input1, gates);
            }
            else {
                input1Value = gates[gate.input1].value;
            }
        }
        else {
            input1Value = 0;
        }
        //if a second input exists, either get its precalculated value, or calculate its value;
        if (gate.input2 != "") {
            if (gates[gate.input2].value == 0) {
                input2Value = getValueOfGate(gate.input2, gates);
            }
            else {
                input2Value = gates[gate.input2].value;
            }
        }
        else {
            input2Value = 0;
        }

        //depending on the gate type, calculate its value from its inputs
        if (gate.operation == "AND") {
            std::cout << gate.input1 << " (" << input1Value << ") AND " << gate.input2 << " (" << input2Value << ") -> " << (input1Value & input2Value) << std::endl;
            gates[gateKey].value = input1Value & input2Value;
            return gates[gateKey].value;
        }
        else if (gate.operation == "OR") {
            std::cout << gate.input1 << " (" << input1Value << ") OR " << gate.input2 << " (" << input2Value << ") -> " << (input1Value | input2Value) << std::endl;
            gates[gateKey].value = input1Value | input2Value;
            return gates[gateKey].value;
        }
        else if (gate.operation == "LSHIFT") {
            std::cout << gate.input1 << " (" << input1Value << ") LSHIFT " << gate.input2 << " (" << input2Value << ") -> " << (input1Value << input2Value) << std::endl;
            gates[gateKey].value = input1Value << input2Value;
            return gates[gateKey].value;
        }
        else if (gate.operation == "RSHIFT") {
            std::cout << gate.input1 << " (" << input1Value << ") RSHIFT " << gate.input2 << " (" << input2Value << ") -> " << (input1Value >> input2Value) << std::endl;
            gates[gateKey].value = input1Value >> input2Value;
            return gates[gateKey].value;
        }
        else if (gate.operation == "NOT") {
            std::cout << "NOT " << gate.input2 << " (" << input2Value << ") -> " << (~input2Value) << std::endl;
            gates[gateKey].value = ~input2Value;
            return gates[gateKey].value;
        }
        else {
            return gates[gateKey].value = input1Value;
            return gates[gateKey].value;
        }
    }
    else {
        return gate.value;
    }
}

void AoC2015D7P1() {
    std::vector<std::string> input = getFileInput(".//src//Day7//Day7.txt");
    std::map<std::string, Gate> gates;

    //get the input values into a readable format for the program
    for (int i = 0; i < input.size(); i++) {
        Gate gate;
        gate.value = 0;
        int space = input[i].find(' ');
        bool operationFlag = false, input2Flag = false;

        //processing the first part of the input string
        gate.input1 = input[i].substr(0, space);
        if (gate.input1 == "NOT") {
            gate.operation = gate.input1;
            gate.input1 = "";
            operationFlag = true;
        }
        else {
            if (isNumber(gate.input1)) {
                if (gates.find(gate.input1) == gates.end()) {
                    Gate numGate;
                    numGate.value = stoi(gate.input1);
                    gates.emplace(gate.input1, numGate);
                }
            }
        }
        input[i] = input[i].substr(space + 1);

        if (operationFlag == false) {
            //parse the operation
            space = input[i].find(' ');
            gate.operation = input[i].substr(0, space);
            if (gate.operation == "->") {
                input2Flag = true;
            }
            input[i] = input[i].substr(space + 1);
        }
        if (input2Flag == false) {
            //parse the second input
            space = input[i].find(' ');
            gate.input2 = input[i].substr(0, space);
            if (isNumber(gate.input2)) {
                if (gates.find(gate.input2) == gates.end()) {
                    Gate numGate;
                    numGate.value = stoi(gate.input2);
                    gates.emplace(gate.input2, numGate);
                }
            }
        }
        else {
            gate.input2 = "";
        }

        //add the gate to the map
        space = input[i].find_last_of(' ');
        gates.emplace(input[i].substr(space + 1), gate);
    }

    //use the get Value of Gate program to see what this chain of gates actually outputs as a value.
    std::cout << getValueOfGate("a", gates) << std::endl << std::endl;
}

void AoC2015D7P2() {
    std::vector<std::string> input = getFileInput(".//src//Day7//Day7.txt");
    std::map<std::string, Gate> gates;

    for (int i = 0; i < input.size(); i++) {
        Gate gate;
        gate.value = 0;
        int space = input[i].find(' ');
        bool operationFlag = false, input2Flag = false;

        //processing the first part of the input string
        gate.input1 = input[i].substr(0, space);
        if (gate.input1 == "NOT") {
            gate.operation = gate.input1;
            gate.input1 = "";
            operationFlag = true;
        }
        else {
            if (isNumber(gate.input1)) {
                if (gates.find(gate.input1) == gates.end()) {
                    Gate numGate;
                    numGate.value = stoi(gate.input1);
                    gates.emplace(gate.input1, numGate);
                }
            }
        }
        input[i] = input[i].substr(space + 1);

        if (operationFlag == false) {
            //parse the operation
            space = input[i].find(' ');
            gate.operation = input[i].substr(0, space);
            if (gate.operation == "->") {
                input2Flag = true;
            }
            input[i] = input[i].substr(space + 1);
        }
        if (input2Flag == false) {
            //parse the second input
            space = input[i].find(' ');
            gate.input2 = input[i].substr(0, space);
            if (isNumber(gate.input2)) {
                if (gates.find(gate.input2) == gates.end()) {
                    Gate numGate;
                    numGate.value = stoi(gate.input2);
                    gates.emplace(gate.input2, numGate);
                }
            }
        }
        else {
            gate.input2 = "";
        }

        //add the gate to the map
        space = input[i].find_last_of(' ');
        gates.emplace(input[i].substr(space + 1), gate);
    }

    //getting gate A value
    uint16_t aValue = getValueOfGate("a", gates);

    //resetting with new "b" value
    std::cout << std::endl << std::endl;
    for (auto it : gates) {
        if (!isNumber(it.first)) {
            gates[it.first].value = 0;
        }
    }
    //override the b value with A as per the second problem instructions
    gates["b"].value = aValue;

    //getting "a" value
    std::cout << getValueOfGate("a", gates) << std::endl << std::endl;
}