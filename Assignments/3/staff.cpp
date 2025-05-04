#include "staff.h"

Staff::Staff(string id, string n, string pickup, string dropoff)
    : Person(id, n, pickup, dropoff) {}

Staff::~Staff() {}

void Staff::payFees(double amount)
{
    balance += amount;
    cout << "Staff payment processed.\n";
}

void Staff::saveToFile(ofstream &out) const
{
    out << "STAFF\n"
        << ID << "\n"
        << name << "\n"
        << balance << "\n"
        << pickupStop << "\n"
        << dropoffStop << "\n";
}

void Staff::loadFromFile(ifstream &in)
{
    getline(in, ID);
    getline(in, name);
    in >> balance;
    in.ignore();
    getline(in, pickupStop);
    getline(in, dropoffStop);
}
