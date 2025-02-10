/*A library system allows users to borrow and return books. The system should:
1. Add new books to the collection.
2. Borrow books (check availability).
3. Return books.
4. Display all available books.
Requirements:
 Implement a Book class with attributes: ID, title, author, availability.
 Implement a Library class with:
1. Method to add a book (with unique ID).
2. Method to borrow a book (updates availability).
3. Method to return a book (marks it available).
4. Method to display all available books.
 Store book records dynamically using pointers and DMA.
 Use constructor overloading to initialize books with or without availability status.*/

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    int ID;
    string title;
    string author;
    bool available;

public:
    Book(int id, string t, string a, bool avail = true)
        : ID(id), title(t), author(a), available(avail) {}

    int getID() const { return ID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }

    void setAvailability(bool avail) { available = avail; }

    void displayBook() const
    {
        cout << "ID: " << ID << ", Title: " << title
             << ", Author: " << author
             << ", Available: " << (available ? "Yes" : "No") << endl;
    }
};

class Library
{
private:
    Book **books;
    int size;
    int capacity;
    void resizeLibrary()
    {
        capacity *= 2;
        Book **newBooks = new Book *[capacity];

        for (int i = 0; i < size; i++)
        {
            newBooks[i] = books[i];
        }

        delete[] books;
        books = newBooks;
    }

public:
    Library(int cap = 5) : size(0), capacity(cap)
    {
        books = new Book *[capacity];
    }

    void addBook(int id, string title, string author, bool avail = true)
    {
        if (size == capacity)
        {
            resizeLibrary();
        }
        books[size++] = new Book(id, title, author, avail);
    }

    bool borrowBook(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (books[i]->getID() == id && books[i]->isAvailable())
            {
                books[i]->setAvailability(false);
                cout << "You have successfully borrowed: " << books[i]->getTitle() << endl;
                return true;
            }
        }
        cout << "Book not available or invalid ID!" << endl;
        return false;
    }

    bool returnBook(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (books[i]->getID() == id && !books[i]->isAvailable())
            {
                books[i]->setAvailability(true);
                cout << "You have successfully returned: " << books[i]->getTitle() << endl;
                return true;
            }
        }
        cout << "Book not borrowed or invalid ID!" << endl;
        return false;
    }

    void displayAvailableBooks() const
    {
        bool found = false;
        cout << "\nAvailable Books:\n";
        for (int i = 0; i < size; i++)
        {
            if (books[i]->isAvailable())
            {
                books[i]->displayBook();
                found = true;
            }
        }
        if (!found)
        {
            cout << "No books are currently available.\n";
        }
    }

    ~Library()
    {
        for (int i = 0; i < size; i++)
        {
            delete books[i];
        }
        delete[] books;
    }
};

int main()
{
    Library lib;

    lib.addBook(101, "C++ Programming", "Bjarne Stroustrup");
    lib.addBook(102, "The Pragmatic Programmer", "Andrew Hunt");
    lib.addBook(103, "Clean Code", "Robert C. Martin", false);

    lib.displayAvailableBooks();

    lib.borrowBook(101);

    lib.borrowBook(103);

    lib.returnBook(101);

    lib.displayAvailableBooks();

    return 0;
}
