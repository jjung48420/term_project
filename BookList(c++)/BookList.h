#ifndef BOOKLIST_H_
#define BOOKLIST_H_
#include "Book.h"
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class BookList {
private:
    vector<Book> books;
public:
    BookList();
    void addBookAt(Book b, int location);
    void addBook(Book b);
    Book findBook(int location) const;
    Book removeBook(int location);
    void displayBooks(std::ostream  &out) const;
};


#endif // _BOOKLIST_H_