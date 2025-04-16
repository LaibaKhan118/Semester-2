/*• Class Library (Optional for advanced students):
o Data Members:
▪ A collection (e.g., array/list) of Book objects.
o Member Functions:
▪ addBook(), removeBook(), searchBook(): Manage the collection.
*/

#include "Library.h"

Library::Library(int maxBooks)
{
    cap = maxBooks;
    count = 0;
    books = new Book[cap];
}

Library::~Library()
{
    delete[] books;
}

void Library::addBook(const Book &book)
{
    if (count < cap)
    {
        books[count++] = book;
    }
}

void Library::removeBook(const std::string &isbn)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getISBN() == isbn)
        {
            for (int j = i; j < count - 1; ++j)
            {
                books[j] = books[j + 1];
            }
        }
        --count;
        break;
    }
}

Book *Library::searchBook(const std::string &isbn)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getISBN() == isbn)
        {
            return &books[i];
        }
        return nullptr;
    }
}
