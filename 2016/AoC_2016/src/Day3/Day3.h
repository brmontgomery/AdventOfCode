#pragma once
#include <iostream>
#include "AoCUtilities.h"

void AoC2016D3P1() {
    std::vector<std::string> input = getFileInput(".//src//Day3//Day3.txt");
    std::vector<std::vector<int>> triangles;
    for (int i = 0; i < input.size(); i++) {
        std::vector<int> triangle = parseStringToInt(input[i], ' ');
        int temp = 0;
        if (triangle[0] < triangle[1]) {
            temp = triangle[0];
            triangle[0] = triangle[1];
            triangle[1] = temp;
        }
        if (triangle[0] < triangle[2]) {
            temp = triangle[0];
            triangle[0] = triangle[2];
            triangle[2] = temp;
        }

        triangles.push_back(triangle);
    }

    int count = triangles.size();
    for (int i = 0; i < triangles.size(); i++) {
        if (triangles[i][0] >= (triangles[i][1] + triangles[i][2])) {
            count--;
        }
    }

    std::cout << std::to_string(count) << std::endl;
}

void AoC2016D3P2() {
    std::vector<std::string> input = getFileInput(".//src//Day3//Day3.txt");
    std::vector<std::vector<int>> triangles;
    for (int i = 0; i < input.size(); i=i+3) {
        std::vector<int> triangle1 = parseStringToInt(input[i], ' ');
        std::vector<int> triangle2 = parseStringToInt(input[i + 1], ' ');
        std::vector<int> triangle3 = parseStringToInt(input[i + 2], ' ');

        std::vector<std::vector<int>> newTriangles{ {triangle1[0], triangle2[0], triangle3[0]}, {triangle1[1], triangle2[1], triangle3[1]}, {triangle1[2], triangle2[2], triangle3[2]} };
        
        for (int j = 0; j < 3; j++) {

            int temp = 0;
            if (newTriangles[j][0] < newTriangles[j][1]) {
                temp = newTriangles[j][0];
                newTriangles[j][0] = newTriangles[j][1];
                newTriangles[j][1] = temp;
            }
            if (newTriangles[j][0] < newTriangles[j][2]) {
                temp = newTriangles[j][0];
                newTriangles[j][0] = newTriangles[j][2];
                newTriangles[j][2] = temp;
            }

            triangles.push_back(newTriangles[j]);
        }
    }

    int count = triangles.size();
    for (int i = 0; i < triangles.size(); i++) {
        if (triangles[i][0] >= (triangles[i][1] + triangles[i][2])) {
            count--;
        }
    }

    std::cout << std::to_string(count) << std::endl;
}
