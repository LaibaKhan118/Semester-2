#include "transportationsystem.h"
#include <fstream>

TransportationSystem::TransportationSystem()
{
    capacity = 100;
    count = 0;
    persons = new Person *[capacity];
    loadPersonsFromFile();
}

TransportationSystem::~TransportationSystem()
{
    savePersonsToFile();
    for (int i = 0; i < count; i++)
    {
        delete persons[i];
    }
    delete[] persons;
}

bool TransportationSystem::isDuplicateID(const string &id) const
{
    for (int i = 0; i < count; i++)
    {
        if (persons[i]->getID() == id)
            return true;
    }
    return false;
}

void TransportationSystem::registerPerson()
{
    string type, id, name, pickup, dropoff;
    cout << "Enter type (Student/Teacher/Staff): ";
    cin >> type;
    cin.ignore();

    cout << "Enter ID: ";
    getline(cin, id);
    if (isDuplicateID(id))
    {
        cout << "Error: Duplicate ID.\n";
        return;
    }

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter pickup stop: ";
    getline(cin, pickup);
    cout << "Enter dropoff stop: ";
    getline(cin, dropoff);

    Person *p = nullptr;

    if (type == "Student")
        p = new Student(id, name, pickup, dropoff);
    else if (type == "Teacher")
        p = new Teacher(id, name, pickup, dropoff);
    else if (type == "Staff")
        p = new Staff(id, name, pickup, dropoff);
    else
    {
        cout << "Invalid type.\n";
        return;
    }

    double fee;
    cout << "Enter fee to pay: ";
    cin >> fee;
    p->payFees(fee);

    if (count < capacity)
        persons[count++] = p;
    else
    {
        cout << "Capacity reached.\n";
        delete p;
    }
}

void TransportationSystem::viewAllPersons() const
{
    if (count == 0)
    {
        cout << "No persons registered.\n";
        return;
    }
    for (int i = 0; i < count; i++)
    {
        cout << "-----------------------\n";
        persons[i]->display();
    }
}

void TransportationSystem::tapCard()
{
    string id, stop;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter stop name: ";
    cin.ignore();
    getline(cin, stop);

    for (int i = 0; i < count; i++)
    {
        if (persons[i]->getID() == id)
        {
            persons[i]->tapCard(stop);
            return;
        }
    }
    cout << "Person not found.\n";
}

void TransportationSystem::savePersonsToFile() const
{
    ofstream out("registered_persons.txt");
    if (!out)
    {
        cout << "Failed to open file for writing.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        persons[i]->saveToFile(out);
    }

    out.close();
}

void TransportationSystem::loadPersonsFromFile()
{
    ifstream in("registered_persons.txt");
    if (!in)
        return;

    string type;
    while (getline(in, type))
    {
        Person *p = nullptr;

        if (type == "STUDENT")
            p = new Student("", "", "", "");
        else if (type == "TEACHER")
            p = new Teacher("", "", "", "");
        else if (type == "STAFF")
            p = new Staff("", "", "", "");
        else
            continue;

        p->loadFromFile(in);
        if (count < capacity)
            persons[count++] = p;
        else
            delete p;
    }

    in.close();
}
