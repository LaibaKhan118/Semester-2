#ifndef TEACHER_H
#define TEACHER_H
#include "person.h"

class Teacher : public Person
{
public:
    Teacher(string id, string n, string pickup, string dropoff);
    virtual ~Teacher();
    void payFees(double amount) override;
    void saveToFile(ofstream &out) const override;
    void loadFromFile(ifstream &in) override;
};

#endif
