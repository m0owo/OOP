#include "picture.hpp"

int main() {
    std::cout << "Picture 1" << std::endl;
    Picture pic1 = read_picture();
    pic1.print();
    std::cout << "Height: " << pic1.get_height() << std::endl;
    std::cout << "Width: " << pic1.get_width() << std::endl;

    std::cout << "\nPicture 2" << std::endl;
    Picture pic2 = read_picture();
    pic2.print();
    std::cout << "Height: " << pic2.get_height() << std::endl;
    std::cout << "Width: " << pic2.get_width() << std::endl;

    std::cout << "\nHCAT" << std::endl;
    Picture hcat_pic = pic1.hcat(pic2);
    hcat_pic.print();

    std::cout << "\nVCAT" << std::endl;
    Picture vcat_pic = pic2.vcat(pic1);
    vcat_pic.print();

    std::cout << "\nResize Pic1 size to 50x50" << std::endl;
    pic1.resize(50, 50);
    pic1.print();
    std::cout << "Height: " << pic1.get_height() << std::endl;
    std::cout << "Width: " << pic1.get_width() << std::endl;

    std::cout << "\nResize Pic1 size to 10x10" << std::endl;
    pic1.resize(10, 10);
    pic1.print();
    std::cout << "Height: " << pic1.get_height() << std::endl;
    std::cout << "Width: " << pic1.get_width() << std::endl;

    std::cout << "\nResize Pic 2 size to 5x5" << std::endl;
    pic2.resize(5, 5);
    pic2.print();
    std::cout << "Height: " << pic2.get_height() << std::endl;
    std::cout << "Width: " << pic2.get_width() << std::endl;



}
