#include <iostream>
#include <map>
#include "AoCUtilities.h"

void AoC2016D1P1() {
	//get individual instructions from the single line of instructions
	std::vector <std::string > directions; 
	directions = parseStringToString(getFileInput(".//src//Day1//Day1.txt")[0], ' ');

	int direction = 1;
	int x = 0;
	int y = 0;

	//pick a direction
	for (int i = 0; i < directions.size(); i++) {
		if (directions[i][0] == 'R') {
			direction += 1;
			if (direction == 5) {
				direction = 1;
			}
		}
		else {
			direction -= 1;
			if (direction == 0) {
				direction = 4;
			}
		}

		//get the distance in that direction
		int distance = std::stoi(directions[i].substr(1));

		switch (direction) {
		case 1:
			y += distance;
			break;
		case 2:
			x += distance;
			break;
		case 3:
			y -= distance;
			break;
		case 4:
			x -= distance;
			break;
		}
	}

	//get sum
	std::cout << std::to_string(abs(x) + abs(y)) << std::endl;
}

void AoC2016D1P2() {
	//get individual instructions from the single line of instructions
	std::vector <std::string > directions;
	directions = parseStringToString(getFileInput(".//src//Day1//Day1.txt")[0], ' ');
	std::map<int, std::vector<int>> locations;

	int direction = 1;
	int x = 0;
	int y = 0;
	int lastX = 0;
	int lastY = 0;

	//pick a distance
	for (int i = 0; i < directions.size(); i++) {
		if (directions[i][0] == 'R') {
			direction += 1;
			if (direction == 5) {
				direction = 1;
			}
		}
		else {
			direction -= 1;
			if (direction == 0) {
				direction = 4;
			}
		}

		//get a distance, also mark any blocks in between origin and endpoint of the step
		int distance = std::stoi(directions[i].substr(1));
		std::vector<int> numbersCrossed;

		switch (direction) {
		case 1:
			lastY = y;
			y += distance;
			for (int j = lastY + 1; j <= y; j++) {
				numbersCrossed.push_back(j);
			}
			break;
		case 2:
			lastX = x;
			x += distance;
			for (int j = lastX + 1; j <= x; j++) {
				numbersCrossed.push_back(j);
			}
			break;
		case 3:
			lastY = y;
			y -= distance;
			for (int j = lastY - 1; j >= y; j--) {
				numbersCrossed.push_back(j);
			}
			break;
		case 4:
			lastX = x;
			x -= distance;
			for (int j = lastX - 1; j >= x; j--) {
				numbersCrossed.push_back(j);
			}
			break;
		}
		
		//if north or south
		if (direction % 2 == 0) {
			for (int j = 0; j < numbersCrossed.size(); j++) {
				//detect whether we have seen the X coord before
				auto search = locations.find(numbersCrossed[j]);
				if (search != locations.end()) {
					//if we have determine if we have seen the Y coordinate before
					for (int k = 0; k < search->second.size(); k++) {
						//finish the program if both are found
						if (y == search->second[k]) {
							std::cout << std::to_string(abs(numbersCrossed[j]) + abs(y)) << std::endl;
							return;
						}
					}
					//if not, mark the coords
					search->second.push_back(y);
				}
				//if not, mark the coords
				else {
					std::pair<int, std::vector<int>> newPair(numbersCrossed[j], { y });
					locations.insert(newPair);
				}
			}
		}
		else {
			//detect whether we have seen the X coord before
			auto search = locations.find(x);
			if (search != locations.end()) {
				for (int k = 0; k < numbersCrossed.size(); k++) {
					//if we have determine if we have seen the Y coordinate before
					for (int j = 0; j < search->second.size(); j++) {
						//finish the program if both are found
						if (numbersCrossed[k] == search->second[j]) {
							std::cout << std::to_string(abs(x) + abs(numbersCrossed[k])) << std::endl;
							return;
						}
					}
					//if not, mark the coords
					search->second.push_back(numbersCrossed[k]);
				}
			}
			//if not, mark the coords
			else {
				std::pair<int, std::vector<int>> newPair(x, numbersCrossed);
				locations.insert(newPair);
			}
		}
	}
}