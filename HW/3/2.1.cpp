#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

//read input from file
std::vector<std::string> read_file(std::string file_name) {
    std::string tmp;
    std::vector<std::string> semicolon;
    std::fstream infile;
    infile.open(file_name);
    
    //check if there is file
    if (!infile) {
        std::cout << "Unable to read file";
    }
    
    //get input from file as string without semicolon
    while(getline(infile, tmp, ';')) {
        if ((tmp != " ") && (tmp != "")) {
            semicolon.push_back(tmp);
        }
    }
    return semicolon;
}

std::vector<std::string> split(std::string str, char delim) {
    std::vector<std::string> splitted;
    std::string tmp = "";
    for (int i = 0; i < str.size(); ++i) {
        if ((str[i] == delim) && (tmp != " ") && (tmp != "")) {
            splitted.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += str[i];
        }
    }
    splitted.push_back(tmp);
    return splitted;
}

//calculating avg
float calc_avg(std::vector<std::string> data) {
    float avg;
    for (int i = 0; i < data.size(); ++i) {
        float x = ::atof(data[i].c_str());
        avg += x;
    }
    avg /= data.size();
    return avg;
}

void print_vec(std::vector<float> vec) {
    std::cout << vec[0];
    for(int i = 1; i < vec.size(); ++i) {
        std::cout << " " << vec[i];
    }
    std::cout << std::endl;
}

//write output to file
void write_file(std::string file_name, std::vector<float> output) {
    std::ofstream outfile(file_name.c_str(), std::ios::app);
    outfile << std::setprecision(3) << output[0];
    for (int i = 1; i < output.size(); ++i) {
        outfile << " " << output[i];
    }
}

int main() {
    std::vector<std::string> input_data = read_file("../exampledata.txt");
    std::vector<std::vector<std::string>> split_data;
    std::vector<float> averages;
    for (std::string s: input_data) {
        split_data.push_back(split(s, ' '));
    }
    for (int i = 0; i < split_data.size(); ++i) {
        averages.push_back(calc_avg(split_data[i]));
    }
    write_file("../exampledata.txt", averages);
}
