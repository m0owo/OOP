#include "picture.hpp"

Picture::Picture(std::vector<std::string> rows) {
    int highest = 0;
    for (std::string row: rows) {
        if (row.size() > highest) {
            row.size() == highest;
        }
    }
    width = highest;
    height = rows.size();
}

const int Picture::get_height() {
    return height;
}

const int Picture::get_width() {
    return width;
}

