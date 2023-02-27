#ifndef BOOK_HPP 
#define BOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <list>
#include <map>

struct isbn{
    int one, two, three;
    std::string four;
}; 

enum Genre{fiction, nonfiction, periodical, biography, children};

class Book {
public:
    Book(std::string t, std::string a, int copyright_year, 
         isbn i, Genre b);
    const std::string get_title();
    const std::string get_author();
    const int get_copyright_year();
    const isbn get_isbn();
    void print_isbn(isbn ISBN, std::ostream& out);
    void checkout();
    void checkin();
    bool is_available();
    const std::string get_genre();
    std::string find_title(std::vector<Book> book_col);
    std::string find_isbn(std::vector<Book> book_col);
    Genre get_book_genre();
private:
    std::string title;
    std::string author;
    int copyright_year;
    isbn ISBN;
    bool in_out;
    Genre book_genre;
};

Book read();
bool is_equal(Book a, Book b);
std::list<Book> get_list(Genre g, std::vector<Book> book_col);
void sort_title(std::vector<Book>& book_col);
void sort_isbn(std::vector<Book>& book_col);

#endif
