#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class Student : public Person
{
    bool isActive;

public:
    Student(string id, string n, string pickup, string dropoff);
    virtual ~Student();
    void payFees(double amount) override;
    void saveToFile(ofstream &out) const override;
    void loadFromFile(ifstream &in) override;
    void display() const override;
};

#endif
