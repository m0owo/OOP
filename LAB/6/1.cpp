#include <iostream>
#include <vector>
#include <array>
#include <cstring>

//1.2
void to_upper(char* s) {
    size_t i = 0;
    while(s[i]) {
        if(s[i] >= 92 && s[i] <= 122) {
            s[i] -= 32;
        }
        ++i;
    }
}

//1.3
char* rev_dup(const char* s) {
    size_t len = strlen(s);
    char* output = new char[len + 1];
    for (size_t i = 0; i < len; ++i) {
        output[i] = s[len - i - 1];
    }
    output[len] = '\0';
    return output;
}

char* read_text(std::istream& in){
    char* s = new char[1];
    int len = 0;
    char c;

    while(in.get(c)){
        if (c == '!') {
            break;
        }

        char* new_s = new char[len + 1];

        for (int i = 0; i < len; ++i) {
            new_s[i] = s[i];
        }

        new_s[len] = c;
        delete[] s;
        s = new_s;
        len++;
    }

    s[len] = '\0';
    return s;
}

int main() {
    //1.1
    double coords[3] = {};
    double* p1 = coords;

    std::array<double, 4> pt4d;
    auto arr_it = pt4d.begin();

    std::vector<double> vec;
    auto vec_it = vec.begin();

    std::cout << "1.1\nsizeof(coords): " << sizeof(coords) << std::endl;
    std::cout << "sizeof(p1): " << sizeof(p1) << std::endl;
    std::cout << "sizeof(vec): " << sizeof(vec) << std::endl;

    //1.2
    std::cout << "\n1.2" << std::endl;
    char str[] = "Hello, World!";
    std::cout << str << std::endl;
    char* s = str;
    to_upper(s);
    std::cout << str << std::endl;

    //1.3
    std::cout << "\n1.3" << std::endl;
    char str2[] = "Hello, X";
    std::cout << str2 << std::endl;
    char* s2 = str2;
    char* output = rev_dup(s2);
    std::cout << "output: " << output << std::endl;

    //1.4 
    std::cout << "\nEnter input: " << std::endl;
    char* output2 = read_text(std::cin);
    std::cout << output2 << std::endl;


}
