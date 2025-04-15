/*• Class Library (Optional for advanced students):
o Data Members:
▪ A collection (e.g., array/list) of Book objects.
o Member Functions:
▪ addBook(), removeBook(), searchBook(): Manage the collection.
*/

#ifndef LIBRARY
#define LIBRARY

#include <string>
#include "Book.h"

class Library
{
    Book **books;
    int maxBooks;
    int bookCount;

public:
    Library(int max);

    void addBook(const Book &book);
    void removeBook();
    void searchBook();
};

#endif
