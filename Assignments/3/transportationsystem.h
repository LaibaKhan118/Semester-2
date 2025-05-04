#ifndef TRANSPORTATION_SYSTEM_H
#define TRANSPORTATION_SYSTEM_H

#include "person.h"
#include "student.h"
#include "teacher.h"
#include "staff.h"
#include "route.h"

class TransportationSystem
{
    Person **persons;
    int capacity;
    int count;

public:
    TransportationSystem();
    ~TransportationSystem();

    void registerPerson();
    void viewAllPersons() const;
    void tapCard();
    void savePersonsToFile() const;
    void loadPersonsFromFile();
    bool isDuplicateID(const string &id) const;
};

#endif
