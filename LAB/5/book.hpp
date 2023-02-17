#ifndef BOOK_HPP 
#define BOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum Genre{fiction, nonfiction, periodical, biography, children};

class Book {
public:
    Book(std::string t, std::string a, int copyright_year, std::string i, Genre b);
    const std::string get_title();
    const std::string get_author();
    const int get_copyright_year();
    const std::string get_isbn();
    void checkout();
    void checkin();
    bool is_available();
    const std::string get_genre();
private:
    std::string title;
    std::string author;
    int copyright_year;
    std::string isbn;
    bool in_out;
    Genre book_genre;
};

bool is_equal(Book a, Book b);

#endif
