#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

struct Groups {
    std::vector<std::string> with;
    std::vector<std::string> without;
};

std::vector<std::string> read_file(std::string file_name) {
    std::string str;
    std::string tmp;
    std::fstream infile;
    std::vector<std::string> input_data;
    infile.open(file_name);

    if(!infile) {
        std::cout << "Unable to read file";
    }

    getline(infile, str);
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            if (tmp != " ") {
                input_data.push_back(tmp);
            }
            tmp = "";
        } 
        else {
            tmp += str[i];
        }
    }
    input_data.push_back(tmp);
    return input_data;
}

bool with(std::string word) {
    return (!(isalpha(word.front()) || (isalpha(word.back()))) && (word.back() == word.front()));
}

void print_vec(std::vector<std::string> vec) {
    std::cout << vec[0];
    for(int i = 1; i < vec.size(); ++i) {
        std::cout << " " << vec[i];
    }
    std::cout << std::endl;
}

Groups group(std::vector<std::string> data) {
    Groups with_without;
    for (int i = 0; i < data.size(); ++i) {
        if (with(data[i])) {
            with_without.with.push_back(data[i]);
        }
        else {
            with_without.without.push_back(data[i]);
        }
    }
    return with_without;
}

std::vector<std::vector<std::string>> generate_pairs(Groups my_group) {
    std::vector<std::vector<std::string>> pairs;
    std::vector<std::string> pair;
    for (int i = 0; i < my_group.with.size(); ++i) {
        for (int j = 0; j < my_group.without.size(); ++j) {
            pair.push_back(my_group.with[i]);
            pair.push_back(my_group.without[j]);
            pairs.push_back(pair);
            pair.clear();
        }
    }
    return pairs;
}

void write_file(std::string file_name, std::vector<std::vector<std::string>> pairs) {
    std::ofstream outfile(file_name.c_str(), std::ios::app);
    outfile << "(" << pairs[0][0] << ", " << pairs[0][1] << ")";
    for (int i = 1; i < pairs.size(); ++i) {
        if(i % 2 == 0 && i != 0) {
            outfile << ",\n(" << pairs[i][0];
        } 
        else {
            outfile << ", (" << pairs[i][0];
        }
        for (int j = 1; j < pairs[i].size(); ++j) {
            outfile << ", " << pairs[i][j] << ")";
        }
    }
}

int main() {
    std::vector<std::string> input_data = read_file("../exampledata2.txt");
    // print_vec(input_data);

    Groups my_group = group(input_data);
    // print_vec(my_group.with);
    // print_vec(my_group.without);

    std::vector<std::vector<std::string>> my_pairs = generate_pairs(my_group);
    // for (int i = 0; i < my_pairs.size(); ++i) {
    //     print_vec(my_pairs[i]);
    // }
    
    write_file("../exampledata2.txt", my_pairs);

}
