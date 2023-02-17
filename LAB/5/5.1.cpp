#include "book.hpp"

int main() {
    Book test1("t1", "a1", 2004, "1234", fiction);
    Book test2("t2", "a2", 2003, "1234", nonfiction);

    std::cout << "Title: " << test1.get_title() << std::endl;
    std::cout << "Author: " << test1.get_author() << std::endl;
    std::cout << "Copyright Year: " << test1.get_copyright_year() << std::endl;
    std::cout << "ISBN: " << test1.get_isbn() << std::endl; 
    std::cout << "Genre: " << test1.get_genre() << std::endl;

    test1.checkout();
    std::cout << "\nAvailable? ";
    if(test1.is_available()) {
        std::cout << "Yes." << std::endl;
    } else {
        std::cout << "No." << std::endl;
    }
    
    test1.checkin();
    std::cout << "\nAvailable? ";
    if(test1.is_available()) {
        std::cout << "Yes." << std::endl;
    } else {
        std::cout << "No." << std::endl;
    }

    if (is_equal(test1, test2)) {
        std::cout << "\nSame ISBN." << std::endl;
    } else {
        std::cout << "\nDifferent ISBN" << std::endl;
    }
    

}
