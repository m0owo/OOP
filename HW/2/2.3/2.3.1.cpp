#include "header.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

int main() 
{
    int n;
    float x;
    float y;
    std::string line;
    std::vector<std::string> lines;
    std::cout << "Number of Points: ";
    std::cin >> n;
    //n = 100;
    std::ifstream infile("../2.3/2.3.svg");

    if (!infile) {
        std::cout << "Unable to read file!";
        return 1;
    }

    while (std::getline(infile, line))
    {
        lines.push_back(line);
    }
    lines.pop_back();

    std::ofstream circle_file;
    // circle_file.open("2.3.svg", std::ios::app);
    circle_file.open("../2.3/2.3.svg");
    for (std::string line: lines)
    {
        circle_file << line << std::endl;
    }

    for (int i = 0; i < n; ++i) 
    {
        while (true)
        {
            x = random_n();
            y = random_n();
            if (in_circle(x, y))
            {
                break;
            }
        }
        circle_file << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"10\" fill=\"00FFFF\" />" << std::endl;
    }
    circle_file << "</svg>" << std::endl;
    circle_file.close();

    return 0;
    //<circle cx="250" cy="250" r="10" fill="#00FFFF" />
}
