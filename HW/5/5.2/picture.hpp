#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Picture {
public:
    Picture(std::vector<std::string> rows);
    int get_height();
    int get_width();
    Picture hcat(Picture);
    Picture vcat(Picture);
    std::vector<std::string> get_rows();
    void print();
    void resize(int ww, int hh);
private:
    int width;
    int height;
    std::vector<std::string> rows;
};

Picture read_picture();
