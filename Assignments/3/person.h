#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
protected:
    string ID, name;
    double balance;
    string pickupStop, dropoffStop;

public:
    Person(string id, string n, string pickup, string dropoff);
    virtual ~Person();
    string getID() const;
    virtual void payFees(double amount) = 0;
    virtual void saveToFile(ofstream &out) const = 0;
    virtual void loadFromFile(ifstream &in) = 0;
    virtual void display() const;
    void tapCard(string stop);
    friend ostream &operator<<(ostream &os, const Person &p);
};

#endif
