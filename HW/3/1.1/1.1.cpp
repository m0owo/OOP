#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

struct data_sets {
    std::vector<int> data1;
    std::vector<int> data2;
}; 

//read input from file
data_sets read_file(std::string file_name) {
    std::string tmp;
    std::vector<std::string> semicolon;
    data_sets input_data;
    std::fstream infile;
    infile.open(file_name);
    
    //check if there is file
    if (!infile) {
        std::cout << "Unable to read file";
    }
    
    //get input from file as string without semicolon
    while(getline(infile, tmp, ';')) {
        semicolon.push_back(tmp);
    }
    
    //separate input string into two vectors
    std::stringstream ss(semicolon[0]);
    while(getline(ss, tmp, ' ')) {
        if (tmp != "" && tmp != " ") {
            input_data.data1.push_back(stof(tmp));
        }
    }
    std::stringstream sss(semicolon[1]);
    while(getline(sss, tmp, ' ')) {
        if(tmp != "" && tmp != " ") {
            input_data.data2.push_back(stof(tmp));
        }
    }

    return input_data;
}

//interleaving data
std::vector<int> interleave(data_sets input_data) {
    std::vector<int> interleaved;
    if (input_data.data1.size() > input_data.data2.size()) {
        for (int i = 0; i < input_data.data2.size(); ++i) {
            interleaved.push_back(input_data.data1[i]);
            interleaved.push_back(input_data.data2[i]);
        }
        for (int i = input_data.data2.size(); i < input_data.data1.size(); ++i) {
            interleaved.push_back(input_data.data1[i]);
        }
    }
    else if (input_data.data1.size() < input_data.data2.size()) {
        for (int i = 0; i < input_data.data1.size(); ++i) {
            interleaved.push_back(input_data.data1[i]);
            interleaved.push_back(input_data.data2[i]);
        }
        for (int i = input_data.data1.size(); i < input_data.data2.size(); ++i) {
            interleaved.push_back(input_data.data1[i]);
        }
    }
    else if (input_data.data1.size() == input_data.data2.size()) {
        for (int i = 0; i < input_data.data1.size(); ++i) {
            interleaved.push_back(input_data.data1[i]);
            interleaved.push_back(input_data.data2[i]);
        }
    }
    return interleaved;
}

/* print vector
void print_vec(std::vector<int> vec) {
    std::cout << vec[0];
    for(int i = 1; i < vec.size(); ++i) {
        std::cout << " " << vec[i];
    }
    std::cout << std::endl;
}
*/

//write output to file
void write_file(std::string file_name, std::vector<int> output) {
    std::ofstream outfile(file_name.c_str(), std::ios::app);
    outfile << output[0];
    for (int i = 1; i < output.size(); ++i) {
        outfile << " " << output[i];
    }
}

int main() {
    //data1.txt
    data_sets data1_input = read_file("../data1.txt");
    std::vector<int> interleaved = interleave(data1_input);
    write_file("../data1.txt", interleaved);

    //data1.txt
    data_sets data2_input = read_file("../data2.txt");
    std::vector<int> interleaved2 = interleave(data2_input);
    write_file("../data2.txt", interleaved2);
}
