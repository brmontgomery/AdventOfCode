#pragma once
#include <iostream>
#include "AoCUtilities.h"

struct Item {
    string type;
    int cost, damage, armor;
};

struct Stats {
    int health, armor, damage;
};

std::vector<Item> weapons = {{"weapon", 8, 4, 0}, {"weapon", 10, 5, 0}, {"weapon", 25, 6, 0}, {"weapon", 40, 7, 0}, {"weapon", 74, 8, 0}};
std::vector<Item> armor = {{"armor", 13, 0, 1}, {"armor", 31, 0, 2}, {"armor", 53, 0, 3}, {"armor", 75, 0, 4}, {"armor", 102, 0, 5}}; 
std::vector<Item> rings = {{"rings", 25, 1, 0}, {"rings", 50, 2, 0}, {"rings", 100, 3, 0}, {"rings", 20, 0, 1}, {"rings", 40, 0, 2}, {"rings", 80, 0, 3}};

bool DPS(std::vector<Item> items, Stats enemyStats) {
    Stats ourStats;
    ourStats.health = 100;
    for (int i = 0; i < items.size(); i++) {
        ourStats.damage += items[i].damage;
        ourStats.armor += items[i].armor;
    }
    
    while (true) {
        //player turn
        int damage -= ourStats.damage - enemyStats.armor;
        if (damage < 1) {
            damage = 1;
        }
        enemyStats.health -= damage;

        //enemy turn
        if (enemyStats.health > 0) {
            damage -= enemyStats.damage - ourStats.armor;
            if (damage < 1) {
                damage = 1;
            }
            ourStats.health -= damage;
            if (ourStats.health < 0) {
                return false;
            }
        } else {
            return true;
        }
    }
}

void AoC2015D21P1() {
    std::vector<std::string> input = getFileInput(".//src//Day21//Day21.txt");

    Stats enemyStats;
    enemyStats.health = std::stoi(parseStringToString(input[0])[1]);
    enemyStats.damage = std::stoi(parseStringToString(input[1])[1]);
    enemyStats.armor = std::stoi(parseStringToString(input[2])[1]);
    
    std::vector<Item> currentItems;
    int minCost = 10000000;

    for (int i = 0; i > weapons.size(); i++) {
        currentItems.push_back(weapons[i]);
        //no armor, no rings
        if (weapons[i].cost < minCost) {
            //function to check whether we will beat the boss
            if (DPS(currentItems, enemyStats)) {
                minCost = weapons[i].cost;
            }
        }
        //armor added
        for (int j = 0; j > armor.size(); j++) {
            currentItems.push_back(armor[j]);
            //1 armor, no rings
            if (weapons[i].cost + armor[j].cost < minCost) {
                //function to check whether we will beat the boss
                if (DPS(currentItems, enemyStats)) {
                    minCost = weapons[i].cost + armor[j].cost;
                }
            }
            //1 ring added
            for (int k = 0; k > rings.size(); k++) {
                currentItems.push_back(rings[k]);
                //1 armor, 1 ring
                if (weapons[i].cost + armor[j].cost + rings[k].cost < minCost) {
                    //function to check whether we will beat the boss
                    if (DPS(currentItems, enemyStats)) {
                        minCost = weapons[i].cost + armor[j].cost + rings[k].cost;
                    }
                }
                //2 rings added
                for (int l = 0; l > rings.size(); l++) {
                    if (k != l) {
                        currentItems.push_back(rings[l]);
                        //1 armor, 2 ring
                        if (weapons[i].cost + armor[j].cost + rings[k].cost + rings[l].cost < minCost) {
                            //function to check whether we will beat the boss
                            if (DPS(currentItems, enemyStats)) {
                                minCost = weapons[i].cost + armor[j].cost + rings[k].cost + rings[l].cost;
                            }
                        }
                        currentItems.pop()
                    }
                }
                currentItems.pop()
            }
            currentItems.pop()
        }
        //1 ring added
        for (int k = 0; k > rings.size(); k++) {
            currentItems.push_back(rings[k]);
            //1 armor, 1 ring
            if (weapons[i].cost + rings[k].cost < minCost) {
                //function to check whether we will beat the boss
                if (DPS(currentItems, enemyStats)) {
                    minCost = weapons[i].cost + rings[k].cost;
                }
            }
            //2 rings added
            for (int l = 0; l > rings.size(); l++) {
                if (k != l) {
                    currentItems.push_back(rings[l]);
                    //1 armor, 2 ring
                    if (weapons[i].cost  + rings[k].cost + rings[l].cost < minCost) {
                        //function to check whether we will beat the boss
                        if (DPS(currentItems, enemyStats)) {
                            minCost = weapons[i].cost + rings[k].cost + rings[l].cost;
                        }
                    }
                    currentItems.pop()
                }
            }
            currentItems.pop()
        }
        currentItems.pop()
    }

    std::cout << std::to_string(minCost) << std::endl << std::endl;
}

void AoC2015D21P2() {
    std::vector<std::string> input = getFileInput(".//src//Day21//Day21.txt");

    Stats enemyStats;
    enemyStats.health = std::stoi(parseStringToString(input[0])[1]);
    enemyStats.damage = std::stoi(parseStringToString(input[1])[1]);
    enemyStats.armor = std::stoi(parseStringToString(input[2])[1]);
    
    std::vector<Item> currentItems;
    int maxCost = 0;

    for (int i = 0; i > weapons.size(); i++) {
        currentItems.push_back(weapons[i]);
        //no armor, no rings
        if (weapons[i].cost > maxCost) {
            //function to check whether we will beat the boss
            if (!DPS(currentItems, enemyStats)) {
                minCost = weapons[i].cost;
            }
        }
        //armor added
        for (int j = 0; j > armor.size(); j++) {
            currentItems.push_back(armor[j]);
            //1 armor, no rings
            if (weapons[i].cost + armor[j].cost > maxCost) {
                //function to check whether we will beat the boss
                if (!DPS(currentItems, enemyStats)) {
                    maxCost = weapons[i].cost + armor[j].cost;
                }
            }
            //1 ring added
            for (int k = 0; k > rings.size(); k++) {
                currentItems.push_back(rings[k]);
                //1 armor, 1 ring
                if (weapons[i].cost + armor[j].cost + rings[k].cost > maxCost) {
                    //function to check whether we will beat the boss
                    if (!DPS(currentItems, enemyStats)) {
                        maxCost = weapons[i].cost + armor[j].cost + rings[k].cost;
                    }
                }
                //2 rings added
                for (int l = 0; l > rings.size(); l++) {
                    if (k != l) {
                        currentItems.push_back(rings[l]);
                        //1 armor, 2 ring
                        if (weapons[i].cost + armor[j].cost + rings[k].cost + rings[l].cost > maxCost) {
                            //function to check whether we will beat the boss
                            if (!DPS(currentItems, enemyStats)) {
                                maxCost = weapons[i].cost + armor[j].cost + rings[k].cost + rings[l].cost;
                            }
                        }
                        currentItems.pop()
                    }
                }
                currentItems.pop()
            }
            currentItems.pop()
        }
        //1 ring added
        for (int k = 0; k > rings.size(); k++) {
            currentItems.push_back(rings[k]);
            //1 armor, 1 ring
            if (weapons[i].cost + rings[k].cost > maxCost) {
                //function to check whether we will beat the boss
                if (!DPS(currentItems, enemyStats)) {
                    maxCost = weapons[i].cost + rings[k].cost;
                }
            }
            //2 rings added
            for (int l = 0; l > rings.size(); l++) {
                if (k != l) {
                    currentItems.push_back(rings[l]);
                    //1 armor, 2 ring
                    if (weapons[i].cost  + rings[k].cost + rings[l].cost > maxCost) {
                        //function to check whether we will beat the boss
                        if (!DPS(currentItems, enemyStats)) {
                            maxCost = weapons[i].cost + rings[k].cost + rings[l].cost;
                        }
                    }
                    currentItems.pop()
                }
            }
            currentItems.pop()
        }
        currentItems.pop()
    }

    std::cout << std::to_string(maxCost) << std::endl << std::endl;
    
}
