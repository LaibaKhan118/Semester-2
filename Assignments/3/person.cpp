#include "person.h"

Person::Person(string id, string n, string pickup, string dropoff)
    : ID(id), name(n), balance(0), pickupStop(pickup), dropoffStop(dropoff) {}

Person::~Person() {}

string Person::getID() const { return ID; }

void Person::display() const
{
    cout << "ID: " << ID << ", Name: " << name << "\n"
         << "Pickup: " << pickupStop << ", Dropoff: " << dropoffStop << "\n"
         << "Balance: " << balance << "\n";
}

void Person::tapCard(string stop)
{
    if (stop == pickupStop || stop == dropoffStop)
        cout << "Attendance recorded for " << name << " at " << stop << "\n";
    else
        cout << "Invalid stop for " << name << "\n";
}

ostream &operator<<(ostream &os, const Person &p)
{
    p.display();
    return os;
}
