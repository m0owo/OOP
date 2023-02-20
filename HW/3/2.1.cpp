#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <cstring>

//read input from file
std::vector<std::vector<float>> read_file(std::string file_name) {
    std::string tmp;
    std::vector<std::string> semicolon;
    std::vector<std::vector<float>> input_data;
    std::fstream infile;
    infile.open(file_name.c_str());
    
    //check if there is file
    if (!infile) {
        std::cout << "Unable to read file";
    }
    
    //get input from file as string without semicolon
    while(getline(infile, tmp, ';')) {
        semicolon.push_back(tmp);
    }

    infile.close();
    //separate input string into vectors
    for (int i = 0; i < semicolon.size(); ++i) {
        int len = semicolon[i].length();
        char * str = new char[len + 1];
        strcpy(str, semicolon[i].c_str());
        std::cout << str;
        char * pch;
        pch = strtok(str, " ");
        input_data.push_back(atof(pch));
        while (pch != NULL)
        {
            pch = strtok (NULL, " ");
            std::cout << pch;
        }
    }
    
    for(auto x : input_data) {
        for (auto y : x){
            std::cout << y << " ";
        } 
    }
    return input_data;
}

std::vector<float> split(std::string str, char delim) {
    std::stringstream ss(str);
    std::string tmp;
    std::vector<float> result;
    while(getline(ss, tmp, delim)) {
        result.push_back(stof(tmp));
    }
    return result;
}

//averaging data
std::vector<float> average(std::vector<std::vector<float>> input_data) {
    std::vector<float> averages;
    float avg;
    for (int i = 0; i < input_data.size(); ++i) {
        avg = 0;
        for (int j = 0; j < input_data[i].size(); ++j) {
            avg += input_data[i][j];
        }
        avg /= input_data[i].size();
        averages.push_back(avg);
    }
    return averages;
}

// print vector
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
    outfile << output[0];
    for (int i = 1; i < output.size(); ++i) {
        outfile << " " << output[i];
    }
}

int main() {
    std::vector<std::vector<float>> input = read_file("../exampledata.txt");
    std::vector<float> avgs = average(input);
    // write_file("exampledata.txt", avgs);
    for(int i = 0; i < input.size(); ++i) {
        print_vec(input[i]);
    }
}
