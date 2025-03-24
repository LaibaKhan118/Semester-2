/*Device management*/
#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    string id;
    string type;
    double powerRating;
    bool status;

public:
    Device(string i, string t, double p) : id(i), type(t), powerRating(p), status(false) {}
    virtual void turnOn()
    {
        status = true;
    }
    virtual void turnOff()
    {
        status = false;
    }
    virtual double calculatePowerUsage(int hours)
    {
        return powerRating * hours;
    }
    string getDeviceType() { return type; }
};

class Light : public Device
{
public:
    Light(string i, string t, double p) : Device(i, t, p) {}
};

class AC : public Device
{
    float currTemp;
    float desiredTemp;

public:
    AC(string i, string t, double p, float cT, float dT) : currTemp(cT), desiredTemp(dT), Device(i, t, p) {}
    virtual double calculatePowerUsage(int hours)
    {
        return powerRating * hours * (1 - (currTemp - desiredTemp) / 100);
    }
};

class securitySystem : public Device
{
private:
public:
    securitySystem(string i, string t, double p) : Device(i, t, p) {}
};

class Fan : public Device
{
    float speedFactor;

public:
    Fan(string i, string t, double p, float s) : speedFactor(s), Device(i, t, p) {}
    virtual double calculatePowerUsage(int hours)
    {
        return powerRating * hours * speedFactor;
    }
};

class User
{
protected:
    string id;
    string role;
    int access_Level;

public:
    User(string i, string r, int level) : id(i), role(r), access_Level(level) {}
    virtual void viewAccessibleDevices()
    {
        cout << "This user can access standard devices." << endl;
    }
};

int main()
{

    return 0;
}
