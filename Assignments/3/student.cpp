#include "student.h"

Student::Student(string id, string n, string pickup, string dropoff)
    : Person(id, n, pickup, dropoff), isActive(false) {}

Student::~Student() {}

void Student::payFees(double amount)
{
    balance += amount;
    isActive = true;
    cout << "Student payment received. Card activated.\n";
}

void Student::saveToFile(ofstream &out) const
{
    out << "STUDENT\n"
        << ID << "\n"
        << name << "\n"
        << balance << "\n"
        << pickupStop << "\n"
        << dropoffStop << "\n"
        << isActive << "\n";
}

void Student::loadFromFile(ifstream &in)
{
    getline(in, ID);
    getline(in, name);
    in >> balance >> isActive;
    in.ignore();
    getline(in, pickupStop);
    getline(in, dropoffStop);
}

void Student::display() const
{
    Person::display();
    cout << "Status: " << (isActive ? "Active" : "Inactive") << "\n";
}
