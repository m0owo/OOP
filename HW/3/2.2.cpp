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

void print_vec(std::vector<float> vec) {
    std::cout << vec[0];
    for(int i = 1; i < vec.size(); ++i) {
        std::cout << " " << vec[i];
    }
    std::cout << std::endl;
}

std::vector<std::vector<float>> calc_cart_prod(std::vector<std::vector<std::string>> vec) {
    std::vector<std::vector<float>> prod;
    std::vector<std::string> prod;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            prod.push_back(strof(vec[i][j]));
            prod.push_back(my_group.without[][j]);
            pairs.push_back(pair);
            pair.clear();
        }
    }
    return pairs;
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
    for (std::string s: input_data) {
        split_data.push_back(split(s, ' '));
    }

    //write_file("../exampledata.txt", );
}
