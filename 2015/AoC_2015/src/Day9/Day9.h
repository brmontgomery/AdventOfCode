#pragma once
#include <iostream>
#include "AoCUtilities.h"

struct Route {
    std::string loc1;
    std::string loc2;
    int distance;
};

int getMinimumLength(std::string currentCity, std::vector<std::string> visited, std::vector<Route> routes) {
    std::vector<int> viable;
    visited.push_back(currentCity);
    //get all cities that have not been visited that are accessible from the current City
    for (int i = 0; i < routes.size(); i++) {
        if ((routes[i].loc1 == currentCity && std::find(visited.begin(), visited.end(), routes[i].loc2) == visited.end()) || (routes[i].loc2 == currentCity && std::find(visited.begin(), visited.end(), routes[i].loc1) == visited.end())) {
            viable.push_back(i);
        }
    }

    //for each route still left, recursively continue. If therare no further routes, we are at the end and begin bubbling the result back up.
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
            //if it is the shortest route so far out of all of the branches, use it.
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
}

int getMaximumLength(std::string currentCity, std::vector<std::string> visited, std::vector<Route> routes) {
    std::vector<int> viable;
    visited.push_back(currentCity);  
    //get all cities that have not been visited that are accessible from the current City
    for (int i = 0; i < routes.size(); i++) {
        if ((routes[i].loc1 == currentCity && std::find(visited.begin(), visited.end(), routes[i].loc2) == visited.end()) || (routes[i].loc2 == currentCity && std::find(visited.begin(), visited.end(), routes[i].loc1) == visited.end())) {
            viable.push_back(i);
        }
    }

    //for each route still left, recursively continue. If therare no further routes, we are at the end and begin bubbling the result back up.
    if (viable.size() > 1) {
        int distance = 0;
        int routeNum, nextDistance = 0;
        for (auto num : viable) {
            std::string nextCity;
            if (routes[num].loc1 == currentCity) {
                nextCity = routes[num].loc2;
            }
            else {
                nextCity = routes[num].loc1;
            }
            nextDistance = getMaximumLength(nextCity, visited, routes);
            //if it is the longest route so far out of all of the branches, use it.
            if (nextDistance + routes[num].distance > distance) {
                distance = nextDistance + routes[num].distance;
                routeNum = num;
            }
        }
        return distance;
    }
    else {
        return routes[viable[0]].distance;
    }
}

void AoC2015D9P1() {
    std::vector<std::string> input = getFileInput(".//src//Day9//Day9.txt");
    std::vector<Route> routes;
    
    //parse all of the difference routes in the list
    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i],' ');

        Route route;
        route.loc1 = parsed[0];
        route.loc2 = parsed[2];
        route.distance = std::stoi(parsed[4]);

        routes.push_back(route);
    }

    int minimumLength = 10000000;
    std::vector<std::string> inputsUsed;
    //starting from each route, calculate the shortest route in which all cities will be visited, then calculate which of the starting routes had the shortest shortest route.
    for (int i = 0; i < input.size(); i++) {
        if (std::find(inputsUsed.begin(), inputsUsed.end(), routes[i].loc1) == inputsUsed.end()) {
            int nextLength = getMinimumLength(routes[i].loc1, {}, routes);
            if (nextLength < minimumLength) {
                minimumLength = nextLength;
            }
            inputsUsed.push_back(routes[i].loc1);
        }
    }
    
    std::cout << minimumLength << std::endl << std::endl;
}

void AoC2015D9P2() {
    std::vector<std::string> input = getFileInput(".//src//Day9//Day9.txt");
    std::vector<Route> routes;

    //get all input routes
    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        Route route;
        route.loc1 = parsed[0];
        route.loc2 = parsed[2];
        route.distance = std::stoi(parsed[4]);

        routes.push_back(route);
    }

    //starting from each route, calculate the longest route in which all cities will be visited, then calculate which of the starting routes had the longest longest route.
    int maximumLength = 0;
    std::vector<std::string> inputsUsed;
    for (int i = 0; i < input.size(); i++) {
        if (std::find(inputsUsed.begin(), inputsUsed.end(), routes[i].loc1) == inputsUsed.end()) {
            int nextLength = getMaximumLength(routes[i].loc1, {}, routes);
            if (nextLength > maximumLength) {
                maximumLength = nextLength;
            }
            inputsUsed.push_back(routes[i].loc1);
        }
    }

    std::cout << maximumLength << std::endl << std::endl;
    
}