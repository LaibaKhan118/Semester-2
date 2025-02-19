#include <iostream>
#include <string>

using namespace std;

class Movie
{
private:
    string movieName;
    string showTime;

public:
    // Constructor
    Movie(string name, string time) : movieName(name), showTime(time) {}

    // Display movie details
    void displayMovie() const
    {
        cout << "Movie: " << movieName << " | Show Time: " << showTime << endl;
    }
};

class Ticket
{
private:
    int rowNumber;
    int seatNumber;
    int ticketID; // First two digits of student ID
    bool isSold;  // Private flag to track if the ticket is sold

public:
    // Constructor
    Ticket(int row, int seat, int id)
        : rowNumber(row), seatNumber(seat), ticketID(id), isSold(false) {}

    // Function to check if the ticket is sold
    bool checkAvailability() const
    {
        return !isSold;
    }

    // Function to purchase the ticket
    void purchaseTicket()
    {
        if (!isSold)
        {
            isSold = true;
            cout << "Ticket Purchased Successfully!\n";
        }
        else
        {
            cout << "Sorry, this seat is already sold!\n";
        }
    }

    // Display ticket details (only if sold)
    void displayTicket() const
    {
        if (isSold)
        {
            cout << "Ticket Details:\n";
            cout << "Row: " << rowNumber << " | Seat: " << seatNumber
                 << " | Ticket ID: " << ticketID << " | Status: Sold\n";
        }
        else
        {
            cout << "This ticket has not been sold yet.\n";
        }
    }
};

// Function to extract ticket ID from student ID (First two digits)
int generateTicketID(string studentID)
{
    return stoi(studentID.substr(4, 2)); // Convert first two digits to integer
}

int main()
{
    string studentID, movieChoice;
    int row, seat;

    // Ask for student ID
    cout << "Enter your student ID (format: 24K-1234): ";
    cin >> studentID;

    // Generate unique Ticket ID from first two digits
    int ticketID = generateTicketID(studentID);

    // Create Movie objects
    Movie movie1("Inception", "07:30 PM");
    Movie movie2("Interstellar", "09:00 PM");

    // Display available movies
    cout << "\n--- Available Movies ---\n";
    movie1.displayMovie();
    movie2.displayMovie();

    // Ask user to select a movie
    cout << "\nEnter the movie you want to watch: ";
    cin.ignore(); // Clear newline character
    getline(cin, movieChoice);

    // Ask for seat details
    cout << "Enter Row Number: ";
    cin >> row;
    cout << "Enter Seat Number: ";
    cin >> seat;

    // Create Ticket object
    Ticket ticket(row, seat, ticketID);

    // Purchase ticket
    ticket.purchaseTicket();

    // Display ticket details
    ticket.displayTicket();

    return 0;
}
