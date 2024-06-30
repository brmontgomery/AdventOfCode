#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D19P1() {
    std::vector<std::string> input = getFileInput(".//src//Day19//Day19.txt");
    std::string initialMolecule;
    std::vector <std::pair<std::string, std::string>> substitutions;
    int count = 0;
    std::vector<std::string> distinctMolecules;

    //get all possible substitutions from the input
    for (int i = 0; i < input.size(); i++) {
        if (i == input.size() - 1) {
            initialMolecule = input[i];
        }
        else if (input[i] != "") {
            std::vector <std::string> inputStrings = parseStringToString(input[i], ' ');
            substitutions.push_back(std::make_pair(inputStrings[0], inputStrings[2]));
        }
    }

    //figure out how many possible substitutions there might be for the input molecule
    for (int i = 0; i < initialMolecule.size(); i++) {
        std::string element;
        bool twoLetterElement = false;

        if (initialMolecule[i] == 'A' || initialMolecule[i] == 'C' || initialMolecule[i] == 'M' || initialMolecule[i] == 'S' || initialMolecule[i] == 'T') {
            //two letter molecule
            element = initialMolecule.substr(i, 2);
            twoLetterElement = true;
        }
        else {
            //single Letter Molecule
            element = initialMolecule.substr(i, 1);
        }

        for (int j = 0; j < substitutions.size(); j++) {
            if (substitutions[j].first == element) {
                std::string newMolecule = initialMolecule.substr(0, i) + substitutions[j].second;
                if (twoLetterElement) {
                    newMolecule += initialMolecule.substr(i + 2);
                }
                else {
                    newMolecule += initialMolecule.substr(i + 1);
                }

                if (std::find(distinctMolecules.begin(), distinctMolecules.end(), newMolecule) == distinctMolecules.end())
                {
                    distinctMolecules.push_back(newMolecule);
                    count++;
                }
            }
        }
    }

    std::cout << count << std::endl << std::endl;
}

void AoC2015D19P2() {
    std::vector<std::string> input = getFileInput(".//src//Day19//Day19.txt");
    std::string goalMolecule;
    std::vector <std::pair<std::string, std::string>> substitutions;
    int count = 0;
    std::vector<std::string> distinctNewMolecules, oldMolecules;

    //we're startign from e and attempting to get to the input molecule
    oldMolecules.push_back("e");

    //get all substitutions
    for (int i = 0; i < input.size(); i++) {
        if (i == input.size() - 1) {
            goalMolecule = input[i];
        }
        else if (input[i] != "") {
            std::vector <std::string> inputStrings = parseStringToString(input[i], ' ');
            substitutions.push_back(std::make_pair(inputStrings[0], inputStrings[2]));
        }
    }

    bool found = false;
    int maxMatch = 0;
    //for each step perform possible substitutions
    //there are multiple constraints to make sure this does not take forever
    //find the least number of steps it takes to get to the end molecul recursively
    while (!found) {
        if (oldMolecules.size() > 1000) {
            std::cout << "wait" << std::endl << std::endl;
        }
        int goBackAmount = 64;
        //the offset allows it to go back and correct mistakes if the algorithm makes one.
        int offSet = 0;
        count++;
        if (oldMolecules[0].size() > goBackAmount) {
            offSet = oldMolecules[0].size() - goBackAmount;
        }
        else {
            offSet = 0;
        }
        //go through the last molecules and check for possible substitutions
        for (int m = 0; m < oldMolecules.size(); m++) {
            if (m % 1000 == 0) {
                std::cout << m << std::endl;
            }
            std::string initialMolecule = oldMolecules[m];
            for (int i = offSet; i < initialMolecule.size(); i++) {
                std::string element;
                bool twoLetterElement = false;

                if (initialMolecule[i] == 'A' || initialMolecule[i] == 'C' || initialMolecule[i] == 'M' || initialMolecule[i] == 'S' || initialMolecule[i] == 'T') {
                    //two letter molecule
                    element = initialMolecule.substr(i, 2);
                    twoLetterElement = true;
                }
                else {
                    //single Letter Molecule
                    element = initialMolecule.substr(i, 1);
                }

                for (int j = 0; j < substitutions.size(); j++) {
                    if (substitutions[j].first == element) {
                        std::string newMolecule = initialMolecule.substr(0, i) + substitutions[j].second;
                        if (twoLetterElement) {
                            newMolecule += initialMolecule.substr(i + 2);
                        }
                        else {
                            newMolecule += initialMolecule.substr(i + 1);
                        }

                        if (std::find(distinctNewMolecules.begin(), distinctNewMolecules.end(), newMolecule) == distinctNewMolecules.end())
                        {
                            int matchAmount = 0;
                            int min = 0;
                            if (newMolecule.size() < goalMolecule.size()) {
                                min = newMolecule.size();
                            }
                            else {
                                min = goalMolecule.size();
                            }
                            for (int n = 0; n < min; n++) {
                                if (newMolecule[n] == goalMolecule[n]) {
                                    matchAmount++;
                                }
                                else {
                                    n = 10000000;
                                }
                            }
                            if (matchAmount >= maxMatch-2) {
                                if (matchAmount > maxMatch) {
                                    maxMatch = matchAmount;
                                }
                                distinctNewMolecules.push_back(newMolecule);
                                if (newMolecule == goalMolecule) {
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        oldMolecules = distinctNewMolecules;
        distinctNewMolecules = {};
    }

    std::cout << count << std::endl << std::endl;
}