#include <iostream>
#include <string>

int main() {
    std::cout << "Input a Warrior Name: ";
    std::string name_w;
    std::cin >> name_w;
    std::string heading_w = " Warrior: ";

    std::cout << "Input a Mage Name: ";
    std::string name_m;
    std::cin >> name_m;
    std::string heading_m = " Mage:    ";

    std::cout << "Input a Ninja Name: ";
    std::string name_n;
    std::cin >> name_n;
    std::string heading_n = " Ninja:   ";

    std::cout << "Input a Fighter Name: ";
    std::string name_f;
    std::cin >> name_f;
    std::string heading_f = " Fighter: ";

    std::string higher_wn;
    std::string higher_mf;
    std::string width;

    if (name_w.size() > name_n.size()) {
        higher_wn = name_w;
    } else {
        higher_wn = name_n;
    }

    if (name_m.size() > name_f.size()) {
        higher_mf = name_m;
    } else {
        higher_mf = name_f;
    }

    if (higher_mf.size() > higher_wn.size()) {
        width = higher_mf;
    } else {
        width = higher_wn;
    }

    std::cout << width << std::endl;

    std::string full_border(((width.size() + heading_w.size() + 1) * 2) + 3, '*');
    std::string filler_spaces(width.size() + heading_w.size() + 1, ' ');


    std::cout << full_border << std::endl;
    std::cout << "*" << filler_spaces << "*" << filler_spaces << "*" << std::endl;
    //std::cout << "*" << heading_w << name_w << " *" << heading_m << name_m << " *" << std::endl;

    int padding_w = width.size() - name_w.size();
    int padding_m = width.size() - name_m.size();
    int padding_n = width.size() - name_n.size();
    int padding_f = width.size() - name_f.size();
    std::string paddingw(padding_w, ' ');
    std::string paddingm(padding_m, ' ');
    std::string paddingn(padding_n, ' ');
    std::string paddingf(padding_f, ' ');
    
    std::cout << "*" << heading_w << name_w << paddingw << " *" << heading_m << name_m << paddingm << " *" << std::endl;
    
    std::cout << "*" << filler_spaces << "*" << filler_spaces << "*" << std::endl;
    std::cout << full_border << std::endl;
    std::cout << "*" << filler_spaces << "*" << filler_spaces << "*" << std::endl;

    std::cout << "*" << heading_n << name_n << paddingn << " *" << heading_f << name_f << paddingf << " *" << std::endl; 

    std::cout << "*" << filler_spaces << "*" << filler_spaces << "*" << std::endl;
    std::cout << full_border << std::endl;
}

