#include <iostream>
#include <string>
#include "BookList.h"
// #include "Book.h"
 
using namespace std;

BookList::BookList() : books() {}

void BookList::addBookAt(Book b, int location) {
    if (location > books.size()) {
        books.push_back(b);
    }
    else if (location <= 0) {
        books.insert(books.begin(), b);
    }
    else {
        books.insert(books.begin()+location, b);
    }
} 

void BookList::addBook(Book b) {
    books.push_back(b);
}

Book BookList::findBook(int location) const {
    if (location > 0 && location < books.size())
        return books.at(location);
    else 
        return Book();
}

Book BookList::removeBook(int location) {
    if (location >= 0 && location < books.size()) {
        books.erase(books.begin() + location);
        return books.at(location-1);
    }
    else {
        return Book();
    }
}

void BookList::displayBooks(std::ostream  &out) const {
    out << "Books in my list:" << endl;
    for (const auto& bs : books) {
        bs.displayBook(out);
    }
}