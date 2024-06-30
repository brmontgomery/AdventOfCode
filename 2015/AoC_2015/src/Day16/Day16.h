#pragma once
#include <iostream>
#include "AoCUtilities.h"

struct Sue {
    int children, cats, samoyeds, pomeranians, akitas, vizslas, goldfish, trees, cars, perfumes;
};

void AoC2015D16P1() {
    std::vector<std::string> input = getFileInput(".//src//Day16//Day16.txt");
    
    //get the information for all aunts
    std::vector<Sue> aunts;
    for (int i = 0; i < input.size(); i++) {
        Sue aunt{ -10000000, -10000000, -10000000, -10000000, -10000000, -10000000, -10000000, -10000000, -10000000, -10000000 };
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        for (int j = 2; j < parsed.size(); j += 2) {
            if (parsed[j].substr(0, parsed[j].size() - 1) == "children") {
                aunt.children = std::stoi(parsed[j+1].substr(0, parsed[j].size() - 1));
            } else if (parsed[j].substr(0, parsed[j].size() - 1) == "cats") {
                aunt.cats = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            } else if (parsed[j].substr(0, parsed[j].size() - 1) == "samoyeds") {
                aunt.samoyeds = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            } else if (parsed[j].substr(0, parsed[j].size() - 1) == "pomeranians") {
                aunt.pomeranians = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            } else if (parsed[j].substr(0, parsed[j].size() - 1) == "akitas") {
                aunt.akitas = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            } else if (parsed[j].substr(0, parsed[j].size() - 1) == "vizslas") {
                aunt.vizslas = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            } else if (parsed[j].substr(0, parsed[j].size() - 1) == "goldfish") {
                aunt.goldfish = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            } else if (parsed[j].substr(0, parsed[j].size() - 1) == "trees") {
                aunt.trees = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            } else if (parsed[j].substr(0, parsed[j].size() - 1) == "cars") {
                aunt.cars = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            } else {
                aunt.perfumes = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
        }

        aunts.push_back(aunt);
    }

    //find the aunt for which none of the following apply
    for (int i = 0; i < aunts.size(); i++) {
        int goodCount = 0;
        if (aunts[i].children != -10000000 && aunts[i].children != 3) { goodCount++; }
        else if (aunts[i].cats != -10000000 && aunts[i].cats != 7) { goodCount++; }
        else if (aunts[i].samoyeds != -10000000 && aunts[i].samoyeds != 2) { goodCount++; }
        else if (aunts[i].pomeranians != -10000000 && aunts[i].pomeranians != 3) { goodCount++; }
        else if (aunts[i].akitas != -10000000 && aunts[i].akitas != 0) { goodCount++; }
        else if (aunts[i].vizslas != -10000000 && aunts[i].vizslas != 0) { goodCount++; }
        else if (aunts[i].goldfish != -10000000 && aunts[i].goldfish != 5) { goodCount++; }
        else if (aunts[i].trees != -10000000 && aunts[i].trees != 3) { goodCount++; }
        else if (aunts[i].cars != -10000000 && aunts[i].cars != 2) { goodCount++; }
        else if (aunts[i].perfumes != -10000000 && aunts[i].perfumes != 1) { goodCount++; }
    
        if (goodCount == 0) {
            std::cout << std::to_string(i+1) << std::endl << std::endl;
        }
    }
}

void AoC2015D16P2() {
    std::vector<std::string> input = getFileInput(".//src//Day16//Day16.txt");

    //get the information for all aunts
    std::vector<Sue> aunts;
    for (int i = 0; i < input.size(); i++) {
        Sue aunt{ -10000000, -10000000, -10000000, -10000000, -10000000, -10000000, -10000000, -10000000, -10000000, -10000000 };
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        for (int j = 2; j < parsed.size(); j += 2) {
            if (parsed[j].substr(0, parsed[j].size() - 1) == "children") {
                aunt.children = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else if (parsed[j].substr(0, parsed[j].size() - 1) == "cats") {
                aunt.cats = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else if (parsed[j].substr(0, parsed[j].size() - 1) == "samoyeds") {
                aunt.samoyeds = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else if (parsed[j].substr(0, parsed[j].size() - 1) == "pomeranians") {
                aunt.pomeranians = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else if (parsed[j].substr(0, parsed[j].size() - 1) == "akitas") {
                aunt.akitas = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else if (parsed[j].substr(0, parsed[j].size() - 1) == "vizslas") {
                aunt.vizslas = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else if (parsed[j].substr(0, parsed[j].size() - 1) == "goldfish") {
                aunt.goldfish = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else if (parsed[j].substr(0, parsed[j].size() - 1) == "trees") {
                aunt.trees = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else if (parsed[j].substr(0, parsed[j].size() - 1) == "cars") {
                aunt.cars = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
            else {
                aunt.perfumes = std::stoi(parsed[j + 1].substr(0, parsed[j].size() - 1));
            }
        }

        aunts.push_back(aunt);
    }

    //find the aunt for which none of the following apply
    for (int i = 0; i < aunts.size(); i++) {
        int goodCount = 0;
        if (aunts[i].children != -10000000 && aunts[i].children != 3) { goodCount++; }
        else if (aunts[i].cats != -10000000 && aunts[i].cats < 7) { goodCount++; }
        else if (aunts[i].samoyeds != -10000000 && aunts[i].samoyeds != 2) { goodCount++; }
        else if (aunts[i].pomeranians != -10000000 && aunts[i].pomeranians > 3) { goodCount++; }
        else if (aunts[i].akitas != -10000000 && aunts[i].akitas != 0) { goodCount++; }
        else if (aunts[i].vizslas != -10000000 && aunts[i].vizslas != 0) { goodCount++; }
        else if (aunts[i].goldfish != -10000000 && aunts[i].goldfish > 5) { goodCount++; }
        else if (aunts[i].trees != -10000000 && aunts[i].trees < 3) { goodCount++; }
        else if (aunts[i].cars != -10000000 && aunts[i].cars != 2) { goodCount++; }
        else if (aunts[i].perfumes != -10000000 && aunts[i].perfumes != 1) { goodCount++; }

        if (goodCount == 0) {
            std::cout << std::to_string(i + 1) << std::endl << std::endl;
            return;
        }
    }
}