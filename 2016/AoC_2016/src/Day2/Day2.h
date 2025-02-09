#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2016D2P1() {
    std::vector<std::string> input = getFileInput(".//src//Day2//Day2.txt");
    //set up a pseudo grid
    int X = 1;
    int Y = 1;

    //set the keypad
    std::vector<std::vector<int>>numpad { {1, 4, 7}, {2, 5, 8}, {3, 6, 9} };

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            //for each direction move where we need to go
            switch (input[i][j]) {
            case 'U':
                if (Y != 0) {
                    Y--;
                }
                break;
            case 'D':
                if (Y != 2) {
                    Y++;
                }
                break;
            case 'L':
                if (X != 0) {
                    X--;
                }
                break;
            case 'R':
                if (X != 2) {
                    X++;
                }
                break;
            }
        }
        //output final positionat the end of each line
        std::cout << std::to_string(numpad[X][Y]);
    }
    std::cout << std::endl;
}

void AoC2016D2P2() {
    std::vector<std::string> input = getFileInput(".//src//Day2//Day2.txt");

    //set the initial position on the keypad
    int X = 0;
    int Y = 2;

    //set keypad
    std::vector<std::vector<char>>numpad{ {'-', '-', '5', '-', '-'}, {'-', '2', '6', 'A', '-'}, {'1', '3', '7', 'B', 'D'}, {'-', '4', '8', 'C', '-'}, {'-', '-', '9', '-', '-'}};

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            //for each direction move where we need to go, ignoring any moves to spaces with '-'
            switch (input[i][j]) {
            case 'U':
                if (Y != 0) {
                    if (numpad[X][Y - 1] != '-') {
                        Y--;
                    }
                }
                break;
            case 'D':
                if (Y != 4) {
                    if (numpad[X][Y + 1] != '-') {
                        Y++;
                    }
                }
                break;
            case 'L':
                if (X != 0) {
                    if (numpad[X - 1][Y] != '-') {
                        X--;
                    }
                }
                break;
            case 'R':
                if (X != 4) {
                    if (numpad[X + 1][Y] != '-') {
                        X++;
                    }
                }
                break;
            }
        }
        //output  the position at the end of each line.
        std::cout << numpad[X][Y];
    }
    std::cout << std::endl;
}