#pragma once
#include <iostream>
#include <vector>
#include "AoCUtilities.h"

void AoC2015D11P1() {
    std::vector<std::string> input = getFileInput(".//src//Day11//Day11.txt");
    
    bool done = false;
    //returns a valid  password based on the below rules
    while (!done) {
        //if a letter is 'z', bring it back to 'a',otherwise increment itdown the alphabet
        if (input[0][7] == 122) {
            input[0][7] = static_cast<char>(97);
            if (input[0][6] == 122) {
                input[0][6] = static_cast<char>(97);
                if (input[0][5] == 122) {
                    input[0][5] = static_cast<char>(97);
                    if (input[0][4] == 122) {
                        input[0][4] = static_cast<char>(97);
                        if (input[0][3] == 122) {
                            input[0][3] = static_cast<char>(97);
                            if (input[0][2] == 122) {
                                input[0][2] = static_cast<char>(97);
                                if (input[0][1] == 122) {
                                    input[0][1] = static_cast<char>(97);
                                    if (input[0][0] == 122) {
                                        input[0][0] = static_cast<char>(97);
                                    }
                                    else {
                                        input[0][0] = static_cast<char>(input[0][0] + 1);
                                    }
                                }
                                else {
                                    input[0][1] = static_cast<char>(input[0][1] + 1);
                                }
                            }
                            else {
                                input[0][2] = static_cast<char>(input[0][2] + 1);
                            }
                        }
                        else {
                            input[0][3] = static_cast<char>(input[0][3] + 1);
                        }
                    }
                    else {
                        input[0][4] = static_cast<char>(input[0][4] + 1);
                    }
                }
                else {
                    input[0][5] = static_cast<char>(input[0][5] + 1);
                }
            }
            else {
                input[0][6] = static_cast<char>(input[0][6] + 1);
            }
        }
        else {
            input[0][7] = static_cast<char>(input[0][7] + 1);
        }

        bool consecutive = false, dubdub = false;
        std::string nextPassword = input[0];
        //passwords cannot contain i, o, or l
        if (input[0].find("i") == std::string::npos && input[0].find("o") == std::string::npos && input[0].find("l") == std::string::npos) {
            //we must find at least one set of three consecutive letters
            for (int i = 0; i < input[0].size() - 2; i++) {
                if (input[0][i+1] == input[0][i] + 1 && input[0][i + 2] == input[0][i] + 2) {
                    consecutive = true;
                }
            }

            //must contain two different pairs of non overlapping letters (aa and bb)
            std::vector<char> doubles = {};
            for (int i = 0; i < input[0].size() - 1; i++) {
                if (input[0][i] == input[0][i + 1]) {
                    doubles.push_back(input[0][i]);
                    i++;
                    if (doubles.size() >= 2) {
                        dubdub = true;
                    }
                }
            }
        }

        if (dubdub && consecutive) {
            done = true;
        }
    }

    std::cout << input[0] << std::endl << std::endl;
}

void AoC2015D11P2() {
    std::vector<std::string> input = getFileInput(".//src//Day11//Day11.txt");

    bool done = false, done2 = false;
    //returns a valid  password based on the below rules
    while (!done || !done2) {
        //if a letter is 'z', bring it back to 'a',otherwise increment itdown the alphabet
        if (input[0][7] == 122) {
            input[0][7] = static_cast<char>(97);
            if (input[0][6] == 122) {
                input[0][6] = static_cast<char>(97);
                if (input[0][5] == 122) {
                    input[0][5] = static_cast<char>(97);
                    if (input[0][4] == 122) {
                        input[0][4] = static_cast<char>(97);
                        if (input[0][3] == 122) {
                            input[0][3] = static_cast<char>(97);
                            if (input[0][2] == 122) {
                                input[0][2] = static_cast<char>(97);
                                if (input[0][1] == 122) {
                                    input[0][1] = static_cast<char>(97);
                                    if (input[0][0] == 122) {
                                        input[0][0] = static_cast<char>(97);
                                    }
                                    else {
                                        input[0][0] = static_cast<char>(input[0][0] + 1);
                                    }
                                }
                                else {
                                    input[0][1] = static_cast<char>(input[0][1] + 1);
                                }
                            }
                            else {
                                input[0][2] = static_cast<char>(input[0][2] + 1);
                            }
                        }
                        else {
                            input[0][3] = static_cast<char>(input[0][3] + 1);
                        }
                    }
                    else {
                        input[0][4] = static_cast<char>(input[0][4] + 1);
                    }
                }
                else {
                    input[0][5] = static_cast<char>(input[0][5] + 1);
                }
            }
            else {
                input[0][6] = static_cast<char>(input[0][6] + 1);
            }
        }
        else {
            input[0][7] = static_cast<char>(input[0][7] + 1);
        }

        bool consecutive = false, dubdub = false;
        std::string nextPassword = input[0];
        //passwords cannot contain i, o, or l
        if (input[0].find("i") == std::string::npos && input[0].find("o") == std::string::npos && input[0].find("l") == std::string::npos) {
            //we must find at least one set of three consecutive letters
            for (int i = 0; i < input[0].size() - 2; i++) {
                if (input[0][i + 1] == input[0][i] + 1 && input[0][i + 2] == input[0][i] + 2) {
                    consecutive = true;
                }
            }

            //must contain two different pairs of non overlapping letters (aa and bb)
            std::vector<char> doubles = {};
            for (int i = 0; i < input[0].size() - 1; i++) {
                if (input[0][i] == input[0][i + 1]) {
                    doubles.push_back(input[0][i]);
                    i++;
                    if (doubles.size() >= 2) {
                        dubdub = true;
                    }
                }
            }
        }

        //we want only the second valid answer
        if (dubdub && consecutive) {
            if (done) {
                done2 = true;
            }
            else {
                done = true;
            }
        }
    }

    std::cout << input[0] << std::endl << std::endl;
}