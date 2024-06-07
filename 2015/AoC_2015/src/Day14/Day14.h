#pragma once
#include <iostream>
#include "AoCUtilities.h"

struct Reindeer {
    std::string name;
    int flyTime, restTime, flySpeed, timeAtState, distance;
    bool state;
}

void AoC2015D14P1() {
    std::vector<Reindeer> racers;
    int raceTime = 2503;
    
    std::vector<std::string> input = getFileInput(".//src//Day14//Day14.txt");
    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');
        Reindeer deer;
        deer.name = parsed[0];
        deer.flySpeed = std::stoi(parsed[3]);
        deer.flyTime = std::stoi(parsed[6]);
        deer.restTime = std::stoi(parsed[13]);
        deer.state = 1;
        deer.timeAtState = true;
        racers.push_back(deer);
    }

    for (int i = 0; i < raceTime; i++) {
        for int j = 0; j < racers.size(); j++) {
            if (racers[j].state == 1) {
                distance += flySpeed;
                timeAtState += 1;
                if (timeAtState == flyTime) {
                    timeAtState = 0;
                    state = false;
                }
            } else {
                timeAtState += 1;
                if (timeAtState == restTime) {
                    timeAtState = 0;
                    state = true;
                }
            }
        }
    }

    Reindeer maxDistance = racers[0];
    for (int i = 1; i < racers.size(); i++) {
        if (racers[i].distance > maxDistance.distance) {
            maxDistance = racers[i];
        }
    }

    std::cout << std::to_string(maxDistance.distance) << std::endl << std::endl;
}

void AoC2015D14P2() {
    std::vector<std::string> input = getFileInput(".//src//Day14//Day14.txt");
    
}
