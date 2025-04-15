/*
Flow:
• Define Book in header and source files to separate interface and implementation.
• In main(), create a Book object and display its metadata.*/

#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main() {
    Book book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    cout << "Book Title: " << book.getTitle() << endl;
    cout << "Book Author: " << book.getAuthor() << endl;
    cout << "Book ISBN: " << book.getISBN() << endl;

    return 0;
}
