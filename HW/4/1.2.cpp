#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string tmp;
    std::string s;
    std::vector<std::string> input;
    std::unordered_map<std::string, float> registers;
    
    while (getline(std::cin, s)) {
        std::stringstream ss(s);
        while (getline(ss, tmp, ' ')) {
            input.push_back(tmp);
        }

        if (input[0] == "set") {
            registers[input[1]] = stof(input[2]);
        }
        else if (input[0] == "get") {
            if(!registers[input[1]]) {
                std::cout << "<N/A>" << std::endl;
            }
            else {
                std::cout << input[1] << ": " << registers[input[1]] << std::endl;
            }
        }
        else if (input[0] == "subtract") {
            std::cout << input[1] << " - " << input[2] << ": ";
            if(!registers[input[1]] || !registers[input[2]]) {
                std::cout << "<N/A>" << std::endl;
            }
            else {
                std::cout << (registers[input[1]] - registers[input[2]]) << std::endl;
            }
        }
        else if (input[0] == "add") {
            std::cout << input[1] << " + " << input[2] << ": ";
            if(!(registers[input[1]] && registers[input[2]])) {
                std::cout << "<N/A>" << std::endl;
            }
            else {
                std::cout << (registers[input[1]] + registers[input[2]]) << std::endl;
            }
        }
        else {
            std::cout << "Command doesn't exist." << std::endl;
        }
        input.clear();
    }
}
