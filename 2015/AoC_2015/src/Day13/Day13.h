#pragma once
#include <iostream>
#include <map>
#include "AoCUtilities.h"

/*int getMinimumLength(std::string currentCity, std::vector<std::string> visited, std::vector<Route> routes) {
    std::vector<int> viable;
    visited.push_back(currentCity);
    for (int i = 0; i < routes.size(); i++) {
        if ((routes[i].loc1 == currentCity && std::find(visited.begin(), visited.end(), routes[i].loc2) == visited.end()) || (routes[i].loc2 == currentCity && std::find(visited.begin(), visited.end(), routes[i].loc1) == visited.end())) {
            viable.push_back(i);
        }
    }

    if (viable.size() > 1) {
        int distance = 100000000;
        int routeNum, nextDistance = 0;
        for (auto num : viable) {
            std::string nextCity;
            if (routes[num].loc1 == currentCity) {
                nextCity = routes[num].loc2;
            }
            else {
                nextCity = routes[num].loc1;
            }
            nextDistance = getMinimumLength(nextCity, visited, routes);
            if (nextDistance + routes[num].distance < distance) {
                distance = nextDistance + routes[num].distance;
                routeNum = num;
            }
        }
        return distance;
    }
    else {
        return routes[viable[0]].distance;
    }
}*/

void AoC2015D13P1() {
    std::vector<std::string> input = getFileInput(".//src//Day13//Day13.txt");

    std::map<std::string, std::map<std::string, int>> people;
    
    for (int i = 0; i < input.size(); i++) {
        int score = 0;
        std::string name = input[i].substr(0, input[i].find(' '));
        input[i] = input[i].substr(input[i].find(' ') + 1);
        input[i] = input[i].substr(0, input[i].size() - 1);
        std::string nextTo = input[i].substr(input[i].find_last_of(' ') + 1, input[i].size() - input[i].find_last_of(' ') + 1);
        if (input[i].substr(6, 4) == "gain") {
            score += std::stoi(input[i].substr(11, 2));
        } else {
            score -=std::stoi(input[i].substr(11, 2));
        }

        auto it = people.find(name);
        if (it != people.end()) {
            people[name][nextTo] = score;
        } else {
            std::map<std::string, int> tempMap = {{nextTo,score}};
            people[name] = tempMap;
        }
    }
}

void AoC2015D13P2() {
    std::vector<std::string> input = getFileInput(".//src//Day13//Day13.txt");
    
}
