/*
Task 03
Problem: A public library is transitioning from manual record-keeping to a digital system. Staff need secure access to book details (title, author, ISBN) but must not modify records directly. The system should separate public interfaces (e.g., searching books) from internal data handling to prevent accidental data corruption.
Classes and Structure:
• Class Book (Header: Book.h, Implementation: Book.cpp):
o Data Members:
▪ title, author, ISBN (strings): Store book metadata.
o Member Functions:
▪ Constructor to initialize book details.
▪ getTitle(), getAuthor(), getISBN(): Return book properties.

• Class Library:
o Data Members:
▪ A collection (e.g., array/list) of Book objects.
o Member Functions:
▪ addBook(), removeBook(), searchBook(): Manage the collection.

Flow:
• Define Book in header and source files to separate interface and implementation.
• In main(), create a Book object and display its metadata.*/

#include <iostream>
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
    Book book1("To Kill A Mockingbird", "Harper Lee", "9780451524935");

    cout << "Book information:" << endl;
    cout << "Title : " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "ISBN  : " << book1.getISBN() << endl;

    cout << "\nCreating a library, adding this book to the library, and searching for it using the search feature:" << endl;

    Library library(10);

    library.addBook(book1);

    string searchISBN = "9780451524935";

    Book *found = library.searchBook(searchISBN);

    if (found != nullptr)
    {
        cout << "Book found in the library!" << endl;
        cout << "Title: " << found->getTitle() << endl;
        cout << "Author: " << found->getAuthor() << endl;
    }
    else
    {
        cout << "Book with ISBN: " << searchISBN << " not found in the library!" << endl;
    }

    return 0;
}
