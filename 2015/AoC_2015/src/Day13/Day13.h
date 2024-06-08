#pragma once
#include <iostream>
#include <map>
#include "AoCUtilities.h"

struct Person {
    std::string name;
    std::vector<std::pair<std::string, int>> relationships;
};

int getMaximumHappiness(Person currentPerson, std::vector<std::string> alreadySat, std::vector<Person> people) {
    alreadySat.push_back(currentPerson.name);
    std::vector<Person> viable;

    for (auto person : people) {
        if ((std::find(alreadySat.begin(), alreadySat.end(), person.name) == alreadySat.end())) {
            viable.push_back(person);
        }
    }

    if (viable.size() > 1) {
        int happiness = -100000000;
        int nextHappiness = 0;

        
        for (auto person : viable) {
            std::string message1;

            int happiness;
            happiness = getMaximumHappiness(person, alreadySat, people);
            for (int i = 0; i < currentPerson.relationships.size(); i++) {
                if (currentPerson.relationships[i].first == person.name) {
                    happiness += currentPerson.relationships[i].second;
                }
                if (person.relationships[i].first == currentPerson.name) {
                    happiness += person.relationships[i].second;
                }
            }
            if (happiness > nextHappiness) {
                nextHappiness = happiness;
            }
        }
        //std::cout << std::endl << "Depth: " << std::to_string(alreadySat.size()) << " - Running Total : " << std::to_string(nextHappiness);
        return nextHappiness;
    }
    else {
        int happiness = 0;
        for (int i = 0; i < currentPerson.relationships.size(); i++) {
            if (viable[0].relationships[i].first == currentPerson.name) {
                happiness += viable[0].relationships[i].second;
            }
            if (currentPerson.relationships[i].first == viable[0].name) {
                happiness += currentPerson.relationships[i].second;
            }
            if (viable[0].relationships[i].first == alreadySat[0]) {
                happiness += viable[0].relationships[i].second;
                for (int j = 0; j < people[0].relationships.size(); j++) {
                    if (people[0].relationships[j].first == viable[0].name) {
                        happiness += people[0].relationships[j].second;
                    }
                }
            }
        }
        return happiness;
    }
}

void AoC2015D13P1() {
    std::vector<std::string> input = getFileInput(".//src//Day13//Day13.txt");

    std::vector<Person> people;
    
    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        int happiness = 0;
        if (parsed[2] == "lose") {
            happiness = -1 * std::stoi(parsed[3]);
        }
        else {
            happiness = std::stoi(parsed[3]);
        }

        bool found = false;
        for (int j = 0; j < people.size(); j++) {
            if (people[j].name == parsed[0]) {
                found = true;
                people[j].relationships.push_back(std::pair<std::string, int>(parsed[10].substr(0, parsed[10].size() -1), happiness));
                break;
            }
        }
        if (!found) {
            Person newPerson;
            newPerson.name = parsed[0];
            newPerson.relationships.push_back(std::pair<std::string, int>(parsed[10].substr(0, parsed[10].size() - 1), happiness));
            people.push_back(newPerson);
        }
    }

    std::cout << getMaximumHappiness(people[0], {}, people) << std::endl << std::endl;
}

void AoC2015D13P2() {
    std::vector<std::string> input = getFileInput(".//src//Day13//Day13.txt");

    Person me;
    me.name = "me";

    std::vector<Person> people;

    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> parsed = parseStringToString(input[i], ' ');

        int happiness = 0;
        if (parsed[2] == "lose") {
            happiness = -1 * std::stoi(parsed[3]);
        }
        else {
            happiness = std::stoi(parsed[3]);
        }

        bool found = false;
        for (int j = 0; j < people.size(); j++) {
            if (people[j].name == parsed[0]) {
                found = true;
                people[j].relationships.push_back(std::pair<std::string, int>(parsed[10].substr(0, parsed[10].size() - 1), happiness));
                break;
            }
        }
        if (!found) {
            Person newPerson;
            newPerson.name = parsed[0];
            newPerson.relationships.push_back(std::pair<std::string, int>(parsed[10].substr(0, parsed[10].size() - 1), happiness));
            newPerson.relationships.push_back(std::pair<std::string, int>("me", 0));
            me.relationships.push_back(std::pair<std::string, int>(newPerson.name, 0));
            people.push_back(newPerson);
        }
    }
    people.push_back(me);

    std::cout << getMaximumHappiness(people[0], {}, people) << std::endl << std::endl;
}
