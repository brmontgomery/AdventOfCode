#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> getFileInput(std::string filePath)
{
    std::string str;
    std::vector<std::string> file_contents;

    std::fstream file;
    file.open(filePath, std::ios::in);

    while (getline(file, str))
    {
        //std::cout << str << std::endl;
        file_contents.push_back(str);
    }
    return file_contents;
}

template<typename T> 
T parseString(std::string str, char delimeter);

std::vector<std::string> parseStringToString(std::string str, char delimiter) {
    std::vector<std::string> parsed; 
    
    std::string token;
    size_t pos = 0;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);

        parsed.push_back(token);

        str.erase(0, pos + 1);
    }
    parsed.push_back(str);
    return parsed;
}
std::vector<int> parseStringToInt(std::string str, char delimiter) {
    std::vector<int> parsed;

    std::string token;
    size_t pos = 0;

    while (str[pos] == delimiter) {
        pos++;
    }
    str = str.substr(pos);

    while ((pos = str.find(delimiter)) != std::string::npos) {
        if (pos != 0) {
            token = str.substr(0, pos);

            parsed.push_back(stoi(token));

            str.erase(0, pos + 1);
        }
        else {
            str = str.substr(1);
        }
    }
    parsed.push_back(stoi(str));
    return parsed;
}

bool isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::string removeSpaces(std::string input)
{
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
    return input;
}
