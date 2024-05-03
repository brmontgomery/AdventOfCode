#include <iostream>
#include "AoCUtilities.h"

void AoC2015D1P1() {
	std::vector<std::string> input = getFileInput(".//src//Day1//Day1.txt");
	int countUp = std::count(input[0].begin(), input[0].end(), '(');

	int countDown = std::count(input[0].begin(), input[0].end(), ')');

	std::cout << countUp - countDown << "\n";
}

void AoC2015D1P2() {
	std::vector<std::string> input = getFileInput(".//src//Day1//Day1.txt");
    int floor = 0;

    for (int i = 0; i < input[0].size(); i++) {
        if (input[0][i] == '(') {
            floor++;
        }
        else {
            floor--;
        }

        if (floor < 0) {
            std::cout << i + 1 << "\n";
            return;
        }
    }
}