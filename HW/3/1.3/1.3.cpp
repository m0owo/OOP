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

struct cartesian_product {
    std::vector<std::vector<int>> prod;
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

//calculating cartesian product
cartesian_product calc_cart_prod(data_sets input_data) {
    cartesian_product cart_prod;
    std::vector<int> inside;
    for(auto data1: input_data.data1) {
        for (auto data2: input_data.data2) {
            inside.push_back(data1);
            inside.push_back(data2);
            cart_prod.prod.push_back(inside);
            inside.clear();
        }
    }
    return cart_prod;
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
void write_file(std::string file_name, cartesian_product cart_prod) {
    std::ofstream outfile(file_name.c_str(), std::ios::app);
    outfile << "(" << cart_prod.prod[0][0] << ", " << cart_prod.prod[0][1] << ")";
    for (int i = 1; i < cart_prod.prod.size(); ++i) {
        if(i % 4 == 0 && i != 0) {
            outfile << ",\n(" << cart_prod.prod[i][0];
        } 
        else {
            outfile << ", (" << cart_prod.prod[i][0];
        }
        for (int j = 1; j < cart_prod.prod[i].size(); ++j) {
            outfile << ", " << cart_prod.prod[i][j] << ")";
        }
    }
}

int main() {
    //data1.txt
    data_sets data1_input = read_file("../data1.txt");
    cartesian_product cart_prod1 = calc_cart_prod(data1_input);
    write_file("../data1.txt", cart_prod1);

    //data1.txt
    data_sets data2_input = read_file("../data2.txt");
    cartesian_product cart_prod2 = calc_cart_prod(data2_input);
    write_file("../data2.txt", cart_prod2);
}
