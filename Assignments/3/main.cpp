#include "transportationsystem.h"
#include <iostream>
using namespace std;

int main()
{
    TransportationSystem system;
    int choice;

    do
    {
        cout << "\n--- FAST Transportation System Menu ---\n";
        cout << "1. Register Person\n";
        cout << "2. View All Registered Persons\n";
        cout << "3. Tap Card (Boarding/Exiting)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            system.registerPerson();
            break;
        case 2:
            system.viewAllPersons();
            break;
        case 3:
            system.tapCard();
            break;
        case 4:
            cout << "Exiting program. Saving data...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
