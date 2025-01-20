// Q5: Design Event Management System in C++ to facilitate the organization of events. The program should empower the user to seamlessly manage event details, including the event name, date, venue, and organizer. 
// Incorporate key features such as the ability to add events, display comprehensive details of all events, and perform event searches based on specific dates. 
// To enhance flexibility and scalability, leverage dynamic memory allocation for storing event details.

#include <iostream>
using namespace std;

typedef struct {
    string name;
    string date;
    string venue;
    string organizer;
} Events_info;

int main() {
    int n, op;
    cout << "Enter the number of events: " << endl;
    cin >> n;
    Events_info *ptr = new Events_info[n];
    while(1) {
        cout << "\nMenu\n";
        cout << "1. Add Events\n2. Display All Events\n3. Search Events By Date\n4. Exit\n";
        switch(op) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                delete []ptr;
                return 0;
            default:
                cout << "Wrong Option\n";
                break;
        }
    }

    delete []ptr;
}