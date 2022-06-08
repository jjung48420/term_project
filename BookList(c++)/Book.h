#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <string> 

using namespace std;

class Book {
private: 
    std::string title;
    std::string author;
    int year;
    std::string genre;
public:
    Book();
    void setTitle(std::string newTitle);
    void setAuthor(std::string newAuthor);
    void setYear(int newYear);
    void setGenre(std::string newGenre);
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getGenre() const;
    void displayBook(std::ostream &out) const;
};

#endif // _BOOK_H_