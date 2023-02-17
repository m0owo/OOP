#include "book.hpp"

const std::string Book::get_title() {
    return title;
}

const std::string Book::get_author() {
    return author;
}

const int Book::get_copyright_year() {
    return copyright_year;
}

const std::string Book::get_isbn() {
    return isbn;
}

Book::Book(std::string t, std::string a, int c, std::string i, Genre b) {
    title = t;
    author = a;
    copyright_year = c;
    isbn = i;
    book_genre = b;
}

void Book::checkout() {
    in_out = 0;
}

void Book::checkin() {
    in_out = 1;
}

const std::string Book::get_genre() {
    switch(book_genre) {
        case nonfiction:
            return "Nonfiction";
        case fiction:
            return "Fiction";
        case periodical:
            return "Periodical";
        case biography:
            return "Biography";
        case children:
            return "Children";
    }
    return "None";
}

bool Book::is_available() {
    if (in_out == 1) {
        return true;
    } 
    return false;
}

bool is_equal(Book a, Book b) {
    if(a.get_isbn() == b.get_isbn()) {
        return true;
    }
    return false;
}


