#include <iostream>
using namespace std;

class Author
{
private:
    string name, nationality;

public:
    Author(string n, string nat) : name(n), nationality(nat) {}

    void displayAuthor() const
    {
        cout << "Author: " << name << " (" << nationality << ")" << endl;
    }
};

class Book
{
private:
    string title, ISBN;
    float price;
    Author *author; // Aggregation (Book has an Author)

public:
    Book(string t, string i, float p, Author *a) : title(t), ISBN(i), price(p), author(a) {}

    void displayBook() const
    {
        cout << "Book: " << title << " (ISBN: " << ISBN << "), Price: Rs " << price << endl;
        author->displayAuthor();
    }
};

int main()
{
    Author a1("J.K. Rowling", "British");
    Book b1("Harry Potter", "978-3-16-148410-0", 1500, &a1);

    b1.displayBook();

    return 0;
}
