/*• Class Library (Optional for advanced students):
o Data Members:
▪ A collection (e.g., array/list) of Book objects.
o Member Functions:
▪ addBook(), removeBook(), searchBook(): Manage the collection.
*/

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library
{
protected:
    Book *books;
    int cap;
    int count;

public:
    Library(int maxBooks);
    ~Library();
    void addBook(const Book &book);
    void removeBook(const std::string &isbn);
    Book *searchBook(const std::string &isbn);
};

#endif
