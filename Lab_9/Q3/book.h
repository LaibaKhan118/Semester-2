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

#ifndef BOOK
#define BOOK

class Book
{
protected:
    string title;
    string author;
    string ISBN;

public:
    Book(string t, string a, string i);
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
};

#endif
