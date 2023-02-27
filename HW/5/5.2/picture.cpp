#include "picture.hpp"

Picture::Picture(std::vector<std::string> rows_vec) {
    rows = rows_vec;
    width = get_width();
    height = get_height();
}

std::vector<std::string> Picture::get_rows() {
    return rows;
}

int Picture::get_height() {
    return rows.size();;
}

int Picture::get_width() {
    int size = 0;
    int highest = 0;
    for (std::string row: rows) {
        if (row.size() > highest) {
            highest = row.size();
        }
    }
    width = highest;
    return width;
}

void Picture::print() {
    for (std::string row: rows) {
        std::cout << row << std::endl;
    }
}

void Picture::resize(int ww, int hh) {
    int dif;
    const int w = width;
    const int h = height;
    if (ww > w) {
        for (std::string& row: rows) {
            row += std::string((ww - row.size()), ' ');
        }
    } else if (ww < w) {
        for (std::string& row: rows) {
            for (int i = row.size(); i > ww; --i) {
                row.pop_back();
            }
        }
    }
    if (h < hh) {
        dif = hh - height;
        for (int i = 0; i < dif; ++i) {
                rows.push_back(std::string(width, ' '));
        }
    } else if (height > hh) {
        dif = height - hh;
        for (int i = 0; i < dif; ++i) {
            rows.pop_back();
        }
    }
    width = get_width();
    height = get_height();
}

Picture Picture::vcat(Picture two) {
    std::vector<std::string> new_pic = rows;
    for (auto row: two.get_rows()) {
        new_pic.push_back(row);
    }
    return new_pic;
}

Picture Picture::hcat(Picture two) {
    std::vector<std::string> new_pic;
    if (height >= two.get_height()) {
        for (int i = 0; i < two.get_height(); ++i) {
            new_pic.push_back(rows[i] + std::string(width - rows[i].size(), ' ') + two.get_rows()[i]);
        }
        for (int i = two.get_height(); i < height; ++i) {
            new_pic.push_back(rows[i]);
        }
    } else if (height < two.get_height()) {
        std::string spaces(width, ' ');
        for (int i = 0; i < height; ++i) {
            new_pic.push_back(rows[i] + two.get_rows()[i]);
        }
        for (int i = height; i < two.get_height(); ++i) {
            new_pic.push_back(spaces + two.get_rows()[i]);
        }
    }
    return Picture(new_pic);
}

Picture read_picture() {
    std::cout << "Input Picture (Enter one time to end): " << std::endl;
    std::string line;
    std::string tmp;
    std::vector<std::string> input;
    while(std::cin) {
        getline(std::cin, line); 
        if (line != "") {
            input.push_back(line);
        }
        else {
            break;
        }
    }
    return Picture(input);
}
