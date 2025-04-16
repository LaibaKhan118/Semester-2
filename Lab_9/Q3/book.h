/*Task 03
Problem: A public library is transitioning from manual record-keeping to a digital system.
Staff need secure access to book details (title, author, ISBN) but must not modify records
directly. The system should separate public interfaces (e.g., searching books) from internal
data handling to prevent accidental data corruption.
Classes and Structure:
• Class Book (Header: Book.h, Implementation: Book.cpp):
o Data Members:
▪ title, author, ISBN (strings): Store book metadata.
o Member Functions:
▪ Constructor to initialize book details.
▪ getTitle(), getAuthor(), getISBN(): Return book properties.
*/

#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
protected:
    std::string title;
    std::string author;
    std::string ISBN;

public:
    Book();
    Book(const std::string &t, const std::string &a, const std::string &i);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
};

#endif
