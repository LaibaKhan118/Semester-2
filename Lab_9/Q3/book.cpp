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

#include "BOOK.h"
#include <iostream>

using namespace std;

Book::Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return ISBN; }
