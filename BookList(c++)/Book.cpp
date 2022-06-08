#include <iostream>
#include <string> 
#include "Book.h" 

using namespace std;

Book::Book() : title{""}, author{""}, year{2016}, genre{""} {}

void Book::setTitle(string newTitle) {
    title = newTitle;
}
void Book::setAuthor(string newAuthor) {
    author = newAuthor;
}
void Book::setYear(int newYear) {
    year = newYear;
}
void Book::setGenre(string newGenre) {
    genre = newGenre;
}
string Book::getTitle() const {
    return title;
}
string Book::getAuthor() const {
    return author;
}
int Book::getYear() const {
    return year;
}
string Book::getGenre() const {
    return genre;
}
void Book::displayBook(std::ostream &out) const {
    out << "Title: " << getTitle() << endl;
    out << "Author: " << getAuthor() << endl;
    out << "Year: " << getYear() << endl;
    out << "Genre: " << getGenre() << endl;
}