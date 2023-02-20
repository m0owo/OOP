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

struct sum_of_products {
    int sum;
    std::string calculations;
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

//calculating SOP
sum_of_products sop_function(data_sets input_data) {
    sum_of_products sop;
    std::vector<int> big;
    std::vector<int> smol;

    if (input_data.data1.size() > input_data.data2.size()) {
        big = input_data.data1;
        smol = input_data.data2;
    }
    else if (input_data.data1.size() <= input_data.data2.size()) {
        big = input_data.data2;
        smol = input_data.data1;
    }

    for (int i = 0; i < smol.size(); ++i) {
        sop.sum += (big[i] * smol[i]);
        sop.calculations += ("(" + std::to_string(input_data.data1[i]) 
                         + " * " + std::to_string(input_data.data2[i]) + ")");
        if (i != (smol.size() - 1)) {
            sop.calculations += " + ";
        }
    }
    return sop;
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
void write_file(std::string file_name, sum_of_products sop_to_write) {
    std::ofstream outfile(file_name.c_str(), std::ios::app);
    outfile << sop_to_write.calculations << "\n= " << sop_to_write.sum;
}

int main() {
    //data1.txt
    data_sets data1_input = read_file("../data1.txt");
    sum_of_products sop1 = sop_function(data1_input);
    write_file("../data1.txt", sop1);

    //data1.txt
    data_sets data2_input = read_file("../data2.txt");
    sum_of_products sop2 = sop_function(data2_input);
    write_file("../data2.txt", sop2);
}
