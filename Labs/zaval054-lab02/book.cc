#include <iostream>
#include <string>
#include "book.h"

using namespace std;

string Book::get_title(void) {
    return title;
}

string Book::get_ibsn(void) {
    return ibsn;
}

int Book::get_pages(void) {
    return pages;
}

Book* Book::get_next_book(void) {
    return nextBook;
}

void Book::print_all(void) {
    cout << "\nTitle: " << title << endl;
    cout << "ibsn: " << ibsn << endl;
    cout << "Pages: " << pages << endl;
    if (nextBook != NULL)
        cout << "Next Book: " << nextBook->get_title() << endl;
}

Book* Book::make_next_book(string title, string ibsn, int pages) {
    Book* newBook = new Book(title, ibsn, pages);
    nextBook = newBook;

    return newBook;
}