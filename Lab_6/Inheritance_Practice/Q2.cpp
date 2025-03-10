#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string owner;
    string id;
    float speed;

public:
    Vehicle(string n, string i, float s) : owner(n), id(i), speed(s) {}

    string getOwner() const { return owner; }
    string getID() const { return id; }
    float getSpeed() const { return speed; }

    void setOwner(string o) { owner = o; }
    void setID(string i) { id = i; }
    void setSpeed(float s) { speed = s; }

    virtual float calculateFine() = 0;
    virtual float getLimit() const = 0;
    virtual float getOver() const = 0;
    virtual float getRate() const = 0;
    virtual float getSurcharge() const = 0;
    virtual float getSurchargePercent() const = 0;
    virtual float getExtreme() const = 0;
};

class Car : public Vehicle
{
private:
    float speed_limit = 80; // km/h
    float over_speeding = 0;
    float base_fine = 5.0; // per km/h
    float surcharge_percent = 10.0 / 100.0;
    float surcharge;
    float extreme_speeding = 120; // km/h

public:
    Car(string name, string id, float speed) : Vehicle(name, id, speed) {}
    float calculateFine() override
    {
        float fine = 0;
        if (speed > speed_limit)
        {
            over_speeding = speed - speed_limit;
            fine = over_speeding * base_fine;
        }
        if (speed >= extreme_speeding)
        {
            over_speeding = speed - speed_limit;
            surcharge = fine * surcharge_percent;
            fine += surcharge;
        }
        return fine;
    }

    float getLimit() const override { return speed_limit; }
    float getOver() const override { return over_speeding; }
    float getRate() const override { return base_fine; }
    float getSurcharge() const override { return surcharge; }
    float getSurchargePercent() const override { return surcharge_percent; }
    float getExtreme() const override { return extreme_speeding; }
};

class Bike : public Vehicle
{
private:
    float speed_limit = 60; // km/h
    float over_speeding;
    float base_fine = 3.0; // per km/h
    float surcharge_percent = 15.0 / 100.0;
    float surcharge;
    float extreme_speeding = 90; // km/h

public:
    Bike(string name, string id, float speed) : Vehicle(name, id, speed) {}
    float calculateFine() override
    {
        float fine = 0;
        if (speed > speed_limit)
        {
            over_speeding = speed - speed_limit;
            fine = over_speeding * base_fine;
        }
        if (speed >= extreme_speeding)
        {
            over_speeding = speed - speed_limit;
            surcharge = fine * surcharge_percent;
            fine += surcharge;
        }
        return fine;
    }

    float getLimit() const override { return speed_limit; }
    float getOver() const override { return over_speeding; }
    float getRate() const override { return base_fine; }
    float getSurcharge() const override { return surcharge; }
    float getSurchargePercent() const override { return surcharge_percent; }
    float getExtreme() const override { return extreme_speeding; }
};

class Truck : public Vehicle
{
private:
    float speed_limit = 70; // km/h
    float over_speeding;
    float base_fine = 7.0; // per km/h
    float surcharge_percent = 20.0 / 100.0;
    float surcharge;
    float extreme_speeding = 100; // km/h

public:
    Truck(string name, string id, float speed) : Vehicle(name, id, speed) {}
    float calculateFine() override
    {
        float fine = 0;
        if (speed > speed_limit)
        {
            over_speeding = speed - speed_limit;
            fine = over_speeding * base_fine;
        }
        if (speed >= extreme_speeding)
        {
            over_speeding = speed - speed_limit;
            surcharge = fine * surcharge_percent;
            fine += surcharge;
        }
        return fine;
    }

    float getLimit() const override { return speed_limit; }
    float getOver() const override { return over_speeding; }
    float getRate() const override { return base_fine; }
    float getSurcharge() const override { return surcharge; }
    float getSurchargePercent() const override { return surcharge_percent; }
    float getExtreme() const override { return extreme_speeding; }
};

void displayDetails(Vehicle &v, const string &type)
{
    float fine = v.calculateFine();
    cout << "\n\nTraffic Violation Details:\n--------------------" << endl;
    cout << "Owner Name: " << v.getOwner() << endl;
    cout << "Vehicle ID: " << v.getID() << endl;
    cout << "Vehicle Type: " << type << endl;
    cout << "Speed Recorded: " << v.getSpeed() << endl;
    cout << "Speed Limit: " << v.getLimit() << endl;
    cout << "Over-speeding: " << v.getOver() << endl;
    cout << "Base Fine: Rs " << v.getRate() << endl;
    cout << "Surcharge: (" << v.getSurchargePercent() * 100.0 << "% for extreme speeding): Rs " << v.getSurcharge() << " applied." << endl;
    cout << "Total Fine: Rs " << fine << endl;
}

int main()
{
    string name, id, type;
    int op;
    float speed, fine;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Recorded Speed: ";
    cin >> speed;
    cout << "Select Vehicle Type (1. Car, 2. Bike, 3. Truck): ";
    cin >> op;

    Vehicle *vehicle = nullptr;
    if (op == 1)
    {
        type = "Car";
        vehicle = new Car(name, id, speed);
    }
    else if (op == 2)
    {
        type = "Bike";
        vehicle = new Bike(name, id, speed);
    }
    else if (op == 3)
    {
        type = "Truck";
        vehicle = new Truck(name, id, speed);
    }
    else
    {
        cout << "Wrong Vehicle Type option." << endl;
        return 1;
    }

    displayDetails(*vehicle, type);
    return 0;
}
