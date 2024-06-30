#pragma once
#include <iostream>
#include "AoCUtilities.h"
struct Ingredient {
    std::string name;
    int capacity, durability, flavor, texture, calories;
};

void AoC2015D15P1() {
    std::vector<std::string> input = getFileInput(".//src//Day15//Day15.txt");

    //get all ingredients stats
    std::vector<Ingredient> ingredients;
    for (int i = 0; i < input.size(); i++) {
        Ingredient ingredient;
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        ingredient.name = parsed[0].substr(0, parsed[0].size() - 1);
        ingredient.capacity = std::stoi(parsed[2].substr(0, parsed[2].size() - 1));
        ingredient.durability = std::stoi(parsed[4].substr(0, parsed[4].size() - 1));
        ingredient.flavor = std::stoi(parsed[6].substr(0, parsed[6].size() - 1));
        ingredient.texture = std::stoi(parsed[8].substr(0, parsed[8].size() - 1));
        ingredient.calories = std::stoi(parsed[10]);

        ingredients.push_back(ingredient);
    }

    int max = 0;
    //go through every possible combination of ingrdients that adds up to 100 and find the highest total score
    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            for (int c = 0; c < 100; c++) {
                for (int d = 0; d < 100; d++) {
                    if (a + b + c + d == 100) {
                        int capacity = 0, durability = 0, flavor = 0, texture = 0;

                        capacity = std::max((ingredients[0].capacity * a) + (ingredients[1].capacity * b) + (ingredients[2].capacity * c) + (ingredients[3].capacity * d), 0);
                        durability = std::max((ingredients[0].durability * a) + (ingredients[1].durability * b) + (ingredients[2].durability * c) + (ingredients[3].durability * d), 0);
                        flavor = std::max((ingredients[0].flavor * a) + (ingredients[1].flavor * b) + (ingredients[2].flavor * c) + (ingredients[3].flavor * d), 0);
                        texture = std::max((ingredients[0].texture * a) + (ingredients[1].texture * b) + (ingredients[2].texture * c) + (ingredients[3].texture * d), 0);
                        
                        int score = capacity * durability * flavor * texture;
                        if (score > max) {
                            max = score;
                        }
                    }   
                }
            }
        }
    }

    std::cout << max << std::endl << std::endl;
}

void AoC2015D15P2() {
    std::vector<std::string> input = getFileInput(".//src//Day15//Day15.txt");

    //get all ingredients stats
    std::vector<Ingredient> ingredients;
    for (int i = 0; i < input.size(); i++) {
        Ingredient ingredient;
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        ingredient.name = parsed[0].substr(0, parsed[0].size() - 1);
        ingredient.capacity = std::stoi(parsed[2].substr(0, parsed[2].size() - 1));
        ingredient.durability = std::stoi(parsed[4].substr(0, parsed[4].size() - 1));
        ingredient.flavor = std::stoi(parsed[6].substr(0, parsed[6].size() - 1));
        ingredient.texture = std::stoi(parsed[8].substr(0, parsed[8].size() - 1));
        ingredient.calories = std::stoi(parsed[10]);

        ingredients.push_back(ingredient);
    }

    int max = 0;
    //go through every possible combination of ingrdients that adds up to 100 and find the highest total score with the added constraint that it can only have 500 calories
    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            for (int c = 0; c < 100; c++) {
                for (int d = 0; d < 100; d++) {
                    if (a + b + c + d == 100) {
                        int capacity = 0, durability = 0, flavor = 0, texture = 0;

                        if ((ingredients[0].calories * a) + (ingredients[1].calories * b) + (ingredients[2].calories * c) + (ingredients[3].calories * d) == 500) {
                            capacity = std::max((ingredients[0].capacity * a) + (ingredients[1].capacity * b) + (ingredients[2].capacity * c) + (ingredients[3].capacity * d), 0);
                            durability = std::max((ingredients[0].durability * a) + (ingredients[1].durability * b) + (ingredients[2].durability * c) + (ingredients[3].durability * d), 0);
                            flavor = std::max((ingredients[0].flavor * a) + (ingredients[1].flavor * b) + (ingredients[2].flavor * c) + (ingredients[3].flavor * d), 0);
                            texture = std::max((ingredients[0].texture * a) + (ingredients[1].texture * b) + (ingredients[2].texture * c) + (ingredients[3].texture * d), 0);

                            int score = capacity * durability * flavor * texture;
                            if (score > max) {
                                max = score;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << max << std::endl << std::endl;
}