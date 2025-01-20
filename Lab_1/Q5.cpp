// Q5: Design Event Management System in C++ to facilitate the organization of events. The program should empower the user to seamlessly manage event details, including the event name, date, venue, and organizer.
// Incorporate key features such as the ability to add events, display comprehensive details of all events, and perform event searches based on specific dates.
// To enhance flexibility and scalability, leverage dynamic memory allocation for storing event details.

#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    string name;
    string date;
    string venue;
    string organizer;
} Events_info;

int main()
{
    int n;
    char op;
    string inputDate;

    cout << "Enter the number of events: " << endl;
    cin >> n;
    cin.ignore();

    Events_info *event_ptr = new Events_info[n];
    if (event_ptr == NULL)
    {
        cout << "Memory Allocation failed." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nEvent " << i + 1 << ": " << endl;
        cout << "Enter Name: ";
        getline(cin, event_ptr[i].name);
        cout << "Enter Date (DD-MM-YYYY): ";
        getline(cin, event_ptr[i].date);
        cout << "Enter Venue: ";
        getline(cin, event_ptr[i].venue);
        cout << "Enter Organizer: ";
        getline(cin, event_ptr[i].organizer);
    }

    cout << "\nDisplaying All Events: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEvent " << i + 1 << ": " << endl;
        cout << "Name: " << event_ptr[i].name << endl;
        cout << "Date: " << event_ptr[i].date << endl;
        cout << "Venue: " << event_ptr[i].venue << endl;
        cout << "Organizer: " << event_ptr[i].organizer << endl;
    }
    while (true)
    {
        bool found = false;

        cout << "Do you want to search a specific event by Date? (Y/N): " << endl;
        cin >> op;

        while (op != 'Y' && op != 'y' && op != 'N' && op != 'n')
        {
            cout << "Please choose Y/y for Yes and N/n for No: ";
            cin >> op;
        }

        if (op == 'Y' || op == 'y')
        {
            cout << "Enter the Date in DD-MM-YYYY format: ";
            cin.ignore();
            getline(cin, inputDate);

            for (int i = 0; i < n; i++)
            {
                if (event_ptr[i].date == inputDate)
                {
                    found = true;
                    cout << "\nEvent on Date " << inputDate << ": \n";
                    cout << "Name: " << event_ptr[i].name << endl;
                    cout << "Date: " << event_ptr[i].date << endl;
                    cout << "Venue: " << event_ptr[i].venue << endl;
                    cout << "Organizer: " << event_ptr[i].organizer << endl;
                }
            }
            if (!found)
            {
                cout << "No Event on the given date. Check the date and its format and try again." << endl;
            }
        }
        else
        {
            cout << "\nExiting the Program.";
            delete[] event_ptr;
            return 0;
        }
    }
}
