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

void Book::print_isbn(isbn ISBN, std::ostream& out) {
    out << ISBN.one << ISBN.two << ISBN.three << ISBN.four << std::endl;
}

const isbn Book::get_isbn() {
    return ISBN;
}

Book::Book(std::string t, std::string a, int c, isbn i, Genre b) {
    title = t;
    author = a;
    copyright_year = c;
    ISBN = i;
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

Genre Book::get_book_genre() {
    return book_genre;
}

bool Book::is_available() {
    if (in_out == 1) {
        return true;
    } 
    return false;
}

bool is_equal(Book a, Book b) {
    return ((a.get_isbn().one == b.get_isbn().one) &&
            (a.get_isbn().two == b.get_isbn().two) &&
            (a.get_isbn().three == b.get_isbn().three) &&
            (a.get_isbn().four == b.get_isbn().four));
}

Book read() {
    std::cout << "\nEnter Book Data: " << std::endl;
    std::string line;
    std::string tmp;
    std::vector<std::string> input;
    for(int i = 0; i < 5; ++i) {
        getline(std::cin, line); 
        input.push_back(line);
    }
    //isbn
    int one = int(input[0][0] - '0');
    int two = int(input[0][1] - '0');
    int three = int(input[0][2] - '0');
    std::string four(1, input[0][3]);
    isbn i = {one, two, three, four};

    //genre
    Genre g;
    std::string genre = input[4];
    if (genre == "fiction") {
        g = fiction;
    } else if (genre == "nonfiction") {
        g = nonfiction;
    } else if (genre == "periodical") {
        g = periodical;
    } else if (genre == "biography") {
        g = biography;
    } else if (genre == "children") {
        g = children;
    }

    return Book(input[1], input[2], std::stoi(input[3]), i, g);

}

std::string Book::find_title(std::vector<Book> book_col) {
    for (Book b: book_col) {
        if (b.get_title() == title) {
            return "Title matched with " + b.get_title();
        }
    }
    return "None";
}

std::string Book::find_isbn(std::vector<Book> book_col) {
    for (Book b: book_col) {
        if ((ISBN.one == b.get_isbn().one) &&
            (ISBN.two == b.get_isbn().two) &&
            (ISBN.three == b.get_isbn().three) &&
            (ISBN.four == b.get_isbn().four)) {
            return "ISBN matched with " + b.get_title();
        }
    }
    return "None";
}

std::list<Book> get_list(Genre g, std::vector<Book> book_col) {
    std::list<Book> list;
    for (Book b: book_col) {
        if (b.get_book_genre() == g) {
            list.push_back(b);
        } 
    }
    return list;
}

void sort_title(std::vector<Book>& book_col) {
    std::map<std::string, std::vector<Book>> titles;
    for (auto b: book_col) {
        if (titles.find(b.get_title()) == titles.end()) {
            titles[b.get_title()] = {b};
        } else {
            titles[b.get_title()].push_back(b);
        }
    }
    book_col.clear();
    std::map<std::string, std::vector<Book>>::iterator it;
    for (it = titles.begin(); it != titles.end(); ++it) {
        for (int j = 0; j != it->second.size(); ++j) {
            book_col.push_back(it->second[j]);
        }
    }
}

void sort_isbn(std::vector<Book>& book_col) {
    std::string isbn_str;
    std::map<std::string, std::vector<Book>> titles;
    for (auto b: book_col) {
        isbn_str = (b.get_isbn().one + b.get_isbn().two + b.get_isbn().three + stoi(b.get_isbn().four));
        if (titles.find(isbn_str) == titles.end()) {
            titles[isbn_str] = {b};
        } else {
            titles[isbn_str].push_back(b);
        }
        isbn_str.clear();
    }
    book_col.clear();
    std::map<std::string, std::vector<Book>>::iterator it;
    for (it = titles.begin(); it != titles.end(); ++it) {
        for (int j = 0; j != it->second.size(); ++j) {
            book_col.push_back(it->second[j]);
        }
    }
}

