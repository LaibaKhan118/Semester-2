#include <iostream>
using namespace std;

class Media
{
protected:
    string title;
    int publicationYear; // just year
    int id;
    string publisher;
    bool available;

public:
    Media(string t, int p, int i, string pub) : title(t), publicationYear(p), id(i), publisher(pub), available(true) {}
    virtual void display() const
    {
        cout << "ID: " << id << endl;
        cout << "Title:" << title << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "Publisher: " << publisher << endl;
    }
    void checkout()
    {
        if (available)
        {
            available = false;
            cout << "Item Checked out successfully." << endl;
        }
        else
            cout << "Item is already checked out." << endl;
    }
    void returnItem()
    {
        if (!available)
        {
            available = true;
            cout << "Item returned successfully." << endl;
        }
        else
            cout << "Item hasn't been checked out." << endl;
    }
    string getTitle() const { return title; }
    int getPublicationYear() const { return publicationYear; }
    virtual ~Media() {}
};

class Book : public Media
{
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string aut, string isbn, int num, string t, int p, int i, string pub) : author(aut), ISBN(isbn), numberOfPages(num), Media(t, p, i, pub) {}

    void display() const override
    {
        Media::display();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }

    string getAuthor() const { return author; }
};

class DVD : public Media
{
private:
    string director;
    float duration;
    float rating;

public:
    DVD(string dir, float dur, float rat, string t, int p, int i, string pub) : director(dir), duration(dur), rating(rat), Media(t, p, i, pub) {}

    void display() const override
    {
        Media::display();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media
{
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string art, int num, string gen, string t, int p, int i, string pub) : artist(art), numberOfTracks(num), genre(gen), Media(t, p, i, pub) {}

    void display() const override
    {
        Media::display();
        cout << "Artist: " << artist << endl;
        cout << "Number Of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media
{
private:
    int issueNumber;

public:
    Magazine(string t, int p, int id, string pub, int issue)
        : Media(t, p, id, pub), issueNumber(issue) {}

    void display() const override
    {
        Media::display();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

void searchMedia(Media **mediaList, int size, string title)
{
    for (int i = 0; i < size; i++)
    {
        if (mediaList[i]->getTitle() == title)
        {
            cout << "Media Found!" << endl;
            mediaList[i]->display();
            return;
        }
    }
    cout << "No media found with title: " << title << endl;
}

void searchMedia(Book **bookList, int size, string author)
{
    for (int i = 0; i < size; i++)
    {
        if (bookList[i]->getAuthor() == author)
        {
            cout << "Book Found!" << endl;
            bookList[i]->display();
            return;
        }
    }
    cout << "No Book found of author: " << author << endl;
}

void searchMedia(Media **mediaList, int size, int year)
{
    for (int i = 0; i < size; i++)
    {
        if (mediaList[i]->getPublicationYear() == year)
        {
            cout << "Book Found!" << endl;
            mediaList[i]->display();
            return;
        }
    }
    cout << "No Media found of year: " << year << endl;
}

int main()
{
    Media *mediaItems[5];
    mediaItems[0] = new Book("Bjarne Stroustrup", "1234567890", 350, "C++ Programming", 2020, 101, "Tech Publishers");
    mediaItems[1] = new DVD("Christopher Nolan", 148, 8.8, "Inception", 2010, 102, "Warner Bros");
    mediaItems[2] = new CD("Michael Jackson", 9, "Pop", "Thriller", 1982, 103, "Epic Records");
    mediaItems[3] = new Magazine("National Geographic", 2023, 104, "NatGeo", 150);

    cout << "\nSearching for media by title 'C++ Programming':\n";
    searchMedia(mediaItems, 4, "C++ Programming");

    cout << "\nSearching for books by author 'Bjarne Stroustrup':\n";
    Book *books[2] = {
        new Book("Bjarne Stroustrup", "1234567890", 350, "C++ Programming", 2020, 101, "Tech Publishers"),
        new Book("ABC", "1234567890", 290, "XYZ", 1920, 105, "JKL Publishers")};

    searchMedia(books, 2, "Bjarne Stroustrup");

    cout << "\nSearching for media published in 2010:\n";
    searchMedia(mediaItems, 4, 2010);

    for (int i = 0; i < 5; i++)
    {
        delete mediaItems[i];
    }

    return 0;
}
