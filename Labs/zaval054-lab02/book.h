#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

class Book {
    private:
        string title;
        string ibsn;
        int pages;
        Book* nextBook;
        
    public:
        // Default Constructor
        Book() : title(""), ibsn(""), pages(0), nextBook(NULL) {}
        
        // Constructor with 3 arguemnts
        Book(string title, string ibsn, int pages) {
            this->title = title;
            this->ibsn = ibsn;
            this->pages = pages;
        }

        // Constructor with 4 arguemnts
        Book(string title, string ibsn, int pages, Book* nextBook) {
            this->title = title;
            this->ibsn = ibsn;
            this->pages = pages;
            this->nextBook = nextBook;
        }

        string get_title(void);
        string get_ibsn(void);
        int get_pages(void);
        Book* get_next_book(void);
        void print_all(void);
        Book* make_next_book(string title, string ibsn, int pages);
};
#endif  // BOOK_H_