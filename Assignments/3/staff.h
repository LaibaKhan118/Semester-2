#ifndef STAFF_H
#define STAFF_H
#include "person.h"

class Staff : public Person
{
public:
    Staff(string id, string n, string pickup, string dropoff);
    virtual ~Staff();
    void payFees(double amount) override;
    void saveToFile(ofstream &out) const override;
    void loadFromFile(ifstream &in) override;
};

#endif
