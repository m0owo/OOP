#include <iostream>
#include <vector>
#include <string>

class Picture {
public:
    Picture(std::vector<std::string> rows);
    const int get_height();
    const int get_width();
private:
    int width;
    int height;
};
