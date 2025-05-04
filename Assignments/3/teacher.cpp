#include "teacher.h"

Teacher::Teacher(string id, string n, string pickup, string dropoff)
    : Person(id, n, pickup, dropoff) {}

Teacher::~Teacher() {}

void Teacher::payFees(double amount)
{
    balance += amount;
    cout << "Teacher's payment processed.\n";
}

void Teacher::saveToFile(ofstream &out) const
{
    out << "TEACHER\n"
        << ID << "\n"
        << name << "\n"
        << balance << "\n"
        << pickupStop << "\n"
        << dropoffStop << "\n";
}

void Teacher::loadFromFile(ifstream &in)
{
    getline(in, ID);
    getline(in, name);
    in >> balance;
    in.ignore();
    getline(in, pickupStop);
    getline(in, dropoffStop);
}
