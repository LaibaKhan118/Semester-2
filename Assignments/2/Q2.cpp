// A2-Q2[24K-0644]
#include <iostream>
#include <string>
using namespace std;

class Ghost
{
protected:
    string workerName;
    int scareLevel;

public:
    Ghost(string name, int level) : workerName(name), scareLevel(level)
    {
        if (level < 1)
            scareLevel = 1;
        if (level > 10)
            scareLevel = 10;
    }
    virtual void haunting()
    {
        cout << workerName << " is haunting generically!" << endl;
    }
    friend ostream &operator<<(ostream &out, const Ghost &g);
    Ghost operator+(const Ghost &g)
    {
        string name = name + " & " + g.workerName;
        int level = scareLevel + g.scareLevel;
        if (level > 10)
            level = 10;
        return Ghost(name, level);
    }

    int getScareLevel() const { return scareLevel; }
    string getName() const { return workerName; }

    virtual ~Ghost() {}
};

ostream &operator<<(ostream &out, const Ghost &g)
{
    out << "Ghost: " << g.workerName << "\nScare Level: " << g.scareLevel;
    return out;
}

class Poltergeist : virtual public Ghost
{
public:
    Poltergeist(string name, int level) : Ghost(name, level) {}
    void haunting() override
    {
        cout << workerName << " is moving objects around!" << endl;
    }
};

class Banshee : virtual public Ghost
{
public:
    Banshee(string name, int level) : Ghost(name, level) {}
    void haunting() override
    {
        cout << workerName << " is screaming loudly!" << endl;
    }
};

class ShadowGhost : virtual public Ghost
{
public:
    ShadowGhost(string name, int level) : Ghost(name, level) {}
    void haunting() override
    {
        cout << workerName << " is whispering creepily!" << endl;
    }
};

class ShadowPoltergeist : public ShadowGhost, public Poltergeist
{
public:
    ShadowPoltergeist(string name, int level) : Ghost(name, level), ShadowGhost(name, level), Poltergeist(name, level) {}
    void haunting() override
    {
        cout << workerName << " is whispering creepily AND moving objects!" << endl;
    }
};

class Visitor
{
protected:
    string name;
    int braveryLevel;
    string braveryStatus;

public:
    Visitor(string n, int l) : name(n), braveryLevel(l)
    {
        if (l < 1)
            braveryLevel = 1;
        if (l > 10)
            braveryLevel = 10;

        if (braveryLevel <= 4)
            braveryStatus = "Cowardly";
        else if (braveryLevel <= 7)
            braveryStatus = "Average";
        else
            braveryStatus = "Fearless";
    }

    string getName() const { return name; }
    int getBravery() const { return braveryLevel; }
    string getBraveryStatus() const { return braveryStatus; }

    void reactToScare(int scareLevel)
    {
        if (scareLevel < braveryLevel)
        {
            cout << name << " laughs at the ghost! (" << braveryStatus << ")" << endl;
        }
        else if (scareLevel > braveryLevel)
        {
            cout << name << " screams and runs away! (" << braveryStatus << ")" << endl;
        }
        else
        {
            cout << name << " gets a shaky voice! (" << braveryStatus << ")" << endl;
        }
    }
};

class HauntedHouse
{
private:
    string name;
    Ghost **ghosts;
    int max;
    int count;

public:
    HauntedHouse(string n, int m) : name(n), max(m), count(0)
    {
        ghosts = new Ghost *[max];
        for (int i = 0; i < max; i++)
        {
            ghosts[i] = nullptr;
        }
    }
    ~HauntedHouse()
    {
        for (int i = 0; i < count; i++)
        {
            delete ghosts[i];
        }
        delete[] ghosts;
    }

    void addGhost(Ghost *g)
    {
        if (count < max)
        {
            ghosts[count++] = g;
        }
        else
        {
            cout << "The Haunted House is Full of Ghosts!" << endl;
        }
    }

    void simulateHaunting(Visitor **visitors, int visitorCount)
    {
        cout << "Welcome to " << name << ". Prepare to be scared!" << endl;

        for (int i = 0; i < visitorCount; i++)
        {
            cout << visitors[i]->getName() << " enters (" << visitors[i]->getBraveryStatus() << ")..." << endl;

            for (int j = 0; j < count; j++)
            {
                cout << "\nGhost encounter: ";
                ghosts[j]->haunting();
                cout << *ghosts[j] << endl;
                visitors[i]->reactToScare(ghosts[j]->getScareLevel());
            }
        }
    }
    string getName() const { return name; }
};

void visitHauntedHouse(Visitor **visitors, int count, HauntedHouse *house)
{
    house->simulateHaunting(visitors, count);
}

int main()
{
    HauntedHouse *house1 = new HauntedHouse("Creepy Manor", 5);
    HauntedHouse *house2 = new HauntedHouse("Screaming Asylum", 5);
    HauntedHouse *house3 = new HauntedHouse("Whispering Shadows", 5);

    house1->addGhost(new Poltergeist("Pesky Pete", 3));
    house1->addGhost(new Banshee("Screaming Sally", 6));
    house1->addGhost(new ShadowGhost("Dark Danny", 8));

    house2->addGhost(new ShadowPoltergeist("Phantom Phil", 5));
    house2->addGhost(new Banshee("Howling Henry", 4));

    house3->addGhost(new Poltergeist("Mischievous Mike", 7));
    house3->addGhost(new ShadowGhost("Gloomy Gwen", 2));
    house3->addGhost(new ShadowPoltergeist("Terrifying Terry", 10));

    int visitorCount = 3;
    Visitor **visitors = new Visitor *[visitorCount];
    visitors[0] = new Visitor("Tanya", 3);
    visitors[1] = new Visitor("Balaaj", 6);
    visitors[2] = new Visitor("Aaina", 9);

    visitHauntedHouse(visitors, visitorCount, house1);
    visitHauntedHouse(visitors, visitorCount, house2);
    visitHauntedHouse(visitors, visitorCount, house3);

    for (int i = 0; i < visitorCount; i++)
    {
        delete visitors[i];
    }
    delete[] visitors;

    delete house1;
    delete house2;
    delete house3;
    return 0;
}
