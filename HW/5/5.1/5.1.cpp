#include "book.hpp"

int main() {
    //1.1
    Book test1("t1", "a1", 2004, (isbn){1, 2, 3, "4"}, fiction);
    Book test2("t2", "a2", 2003, (isbn){5, 6, 7, "8"}, nonfiction);

    std::cout << "Title: " << test1.get_title() << std::endl;
    std::cout << "Author: " << test1.get_author() << std::endl;
    std::cout << "Copyright Year: " << test1.get_copyright_year() << std::endl;
    std::cout << "ISBN: ";
    test1.print_isbn(test1.get_isbn(), std::cout);
    std::cout << "Genre: " << test1.get_genre() << std::endl;

    //1.2
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

    //1.3
    if (is_equal(test1, test2)) {
        std::cout << "\nSame ISBN." << std::endl;
    } else {
        std::cout << "\nDifferent ISBN" << std::endl;
    }

    //HW 1.1
    Book in = read();
    std::cout << "Title: " << in.get_title() << std::endl;
    std::cout << "Author: " << in.get_author() << std::endl;
    std::cout << "Copyright Year: " << in.get_copyright_year() << std::endl;
    std::cout << "ISBN: ";
    test1.print_isbn(in.get_isbn(), std::cout);
    std::cout << "Genre: " << in.get_genre() << std::endl;
    
    std::vector<Book> collection {test1, test2};
    std::cout << "\n" << in.find_isbn(collection) << std::endl;
    std::cout << in.find_title(collection) << std::endl;
    collection.push_back(in);

    //HW 1.2
    std::list<Book> genre_list = get_list(fiction, collection);
    std::cout << "\nFiction books: " << std::endl;
    for (auto b: genre_list) {
        std::cout << b.get_title() << std::endl;
    }

    //HW 1.3
    std::cout << "\nBooks sorted by title: " << std::endl;
    sort_title(collection);
    for (auto b: collection) {
        std::cout << b.get_title() << std::endl;
    }
    std::cout << "\nBooks sorted by isbn: " << std::endl;
    sort_isbn(collection);
    for (auto b: collection) {
        b.print_isbn(b.get_isbn(), std::cout);
    }
}
