#include <iostream>
#include <string>
using namespace std;

class Consumer
{
protected:
    string name;
    int id;
    float units;

public:
    Consumer(string n, int i, float u) : name(n), id(i), units(u) {}

    string getName() const { return name; }
    int getID() const { return id; }
    float getUnits() const { return units; }

    void setName(string n) { name = n; }
    void setID(int i) { id = i; }
    void setUnits(float u) { units = u; }
};

class Residential : public Consumer
{
private:
    float surcharge = 5.0 / 100.0;
    float price = 0.12;

public:
    Residential(string n, int i, float u) : Consumer(n, i, u) {}
    float calculateBill()
    {
        float bill = units * price;
        if (units > 500)
        {
            bill += (bill * surcharge);
        }
        return bill;
    }
};

class Commercial : public Consumer
{
private:
    float surcharge = 10.0 / 100.0;
    float price = 0.20;

public:
    Commercial(string n, int i, float u) : Consumer(n, i, u) {}
    float calculateBill()
    {
        float bill = units * price;
        if (units > 1000)
        {
            bill += (bill * surcharge);
        }
        return bill;
    }
};

class Industrial : public Consumer
{
private:
    float surcharge = 15.0 / 100.0;
    float price = 0.30;

public:
    Industrial(string n, int i, float u) : Consumer(n, i, u) {}
    float calculateBill()
    {
        float bill = units * price;
        if (units > 2000)
        {
            bill += (bill * surcharge);
        }
        return bill;
    }
};

int main()
{
    int op;
    string name;
    int id;
    float units, bill;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter units Consumed: ";
    cin >> units;
    cout << "Enter Consumer Type: (1. Residential, 2. Commercial, 3. Industrial): ";
    cin >> op;

    if (op == 1)
    {
        Residential r(name, id, units);
        bill = r.calculateBill();
    }
    else if (op == 2)
    {
        Commercial c(name, id, units);
        bill = c.calculateBill();
    }
    else if (op == 3)
    {
        Industrial i(name, id, units);
        bill = i.calculateBill();
    }
    else
    {
        cout << "Wrong Option!" << endl;
        return 1;
    }

    cout << "Total Bill is: Rs " << bill << " /-" << endl;
    return 0;
}
