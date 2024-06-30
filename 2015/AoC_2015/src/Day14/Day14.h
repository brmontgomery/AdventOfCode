#pragma once
#include <iostream>
#include "AoCUtilities.h"

struct Reindeer {
    std::string name;
    int flyTime, restTime, flySpeed, timeAtState, distance, leadBonus;
    bool state;
};

void AoC2015D14P1() {
    std::vector<Reindeer> racers;
    int raceTime = 2503;
    
    //get the reindeer stats
    std::vector<std::string> input = getFileInput(".//src//Day14//Day14.txt");
    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');
        Reindeer deer;
        deer.name = parsed[0];
        deer.flySpeed = std::stoi(parsed[3]);
        deer.flyTime = std::stoi(parsed[6]);
        deer.restTime = std::stoi(parsed[13]);
        deer.state = true;
        deer.distance = 0;
        deer.timeAtState = 0;
        deer.leadBonus = 0;
        racers.push_back(deer);
    }

    //algorithmically find out how far each reindeer would fly in the specified time given that for each step they are either flying at speed or resting,
    for (int i = 0; i < raceTime; i++) {
        for (int j = 0; j < racers.size(); j++) {
            if (racers[j].state == true) {
                racers[j].distance += racers[j].flySpeed;
                racers[j].timeAtState += 1;
                if (racers[j].timeAtState == racers[j].flyTime) {
                    racers[j].timeAtState = 0;
                    racers[j].state = false;
                }
            } else {
                racers[j].timeAtState += 1;
                if (racers[j].timeAtState == racers[j].restTime) {
                    racers[j].timeAtState = 0;
                    racers[j].state = true;
                }
            }
        }
    }

    //find the furthest reindeer after the specified time
    Reindeer maxDistance = racers[0];
    for (int i = 1; i < racers.size(); i++) {
        if (racers[i].distance > maxDistance.distance) {
            maxDistance = racers[i];
        }
    }

    std::cout << std::to_string(maxDistance.distance) << std::endl << std::endl;
}

void AoC2015D14P2() {
    std::vector<Reindeer> racers;
    int raceTime = 2503;

    //get the reindeer stats
    std::vector<std::string> input = getFileInput(".//src//Day14//Day14.txt");
    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');
        Reindeer deer;
        deer.name = parsed[0];
        deer.flySpeed = std::stoi(parsed[3]);
        deer.flyTime = std::stoi(parsed[6]);
        deer.restTime = std::stoi(parsed[13]);
        deer.state = true;
        deer.distance = 0;
        deer.leadBonus = 0;
        deer.timeAtState = 0;
        racers.push_back(deer);
    }

    //same as above, except assign a point to each reindeer that is winning at that step.
    for (int i = 0; i < raceTime; i++) {
        for (int j = 0; j < racers.size(); j++) {
            if (racers[j].state == true) {
                racers[j].distance += racers[j].flySpeed;
                racers[j].timeAtState += 1;
                if (racers[j].timeAtState == racers[j].flyTime) {
                    racers[j].timeAtState = 0;
                    racers[j].state = false;
                }
            }
            else {
                racers[j].timeAtState += 1;
                if (racers[j].timeAtState == racers[j].restTime) {
                    racers[j].timeAtState = 0;
                    racers[j].state = true;
                }
            }
        }
        int maxDistance = 0;
        for (int j = 0; j < racers.size(); j++) {
            if (racers[j].distance > maxDistance) {
                maxDistance = racers[j].distance;
            }
        }
        for (int j = 0; j < racers.size(); j++) {
            if (racers[j].distance == maxDistance) {
                racers[j].leadBonus++;
            }
        }
    }

    //find the reindeer with the most points
    Reindeer maxDistance = racers[0];
    for (int i = 1; i < racers.size(); i++) {
        if (racers[i].leadBonus > maxDistance.leadBonus) {
            maxDistance = racers[i];
        }
    }

    std::cout << std::to_string(maxDistance.leadBonus) << std::endl << std::endl;
}
