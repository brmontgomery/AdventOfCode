#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2015D8P1() {
    std::vector<std::string> input = getFileInput(".//src//Day8//Day8.txt");
    int codeCharCount = 0;
    int memCharCount = 0;

    for (int i = 0; i < input.size(); i++) {
        //get the number of chars in the input string
        codeCharCount += input[i].size();

        //use the rules " by themselves do not count as characters, escpaed apostraphes do though (\"), escaped hexadecimal codes count as 1 character
        input[i] = input[i].substr(1, input[i].size() - 2);
        for (int j = 0; j < input[i].size(); j++) {
            //check for escape characters
            if (input[i][j] == '\\') {
                //if hexadecimal, the next 4 characters of input are condensed to one mem character
                if (input[i][j + 1] == 'x') {
                    j += 3;
                }
                //otherwise itsonly the next two condensed to 1
                else {
                    j += 1;
                }
            }
            memCharCount += 1;
        }
    }

    std::cout << codeCharCount - memCharCount;
}

void AoC2015D8P2() {
    std::vector<std::string> input = getFileInput(".//src//Day8//Day8.txt");
    int codeCharCount = 0;
    int newCodeCharCount = 0;

    //now we use these rules to go backwards: add two apostraphes at either end for the new char count, any input apostraphes or backslahes now count as two characters when you add the new escape character to them.
    for (int i = 0; i < input.size(); i++) {
        codeCharCount += input[i].size();
        newCodeCharCount += 2;
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == '\\') {
                newCodeCharCount += 2;
            }
            else if (input[i][j] == '\"') {
                newCodeCharCount += 2;
            }
            else {
                newCodeCharCount += 1;
            }
        }
    }

    std::cout << newCodeCharCount - codeCharCount;
}