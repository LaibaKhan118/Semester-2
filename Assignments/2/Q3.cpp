// A2-Q3[24K-0644]
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Vehicle
{
protected:
    string ID;
    static int activeDelivery;

public:
    Vehicle(string id) : ID(id) {}
    virtual ~Vehicle() {}

    virtual void estimateDeliveryTime() = 0;
    virtual void optimalDeliveryRoute() = 0;
    static int getActiveDelivery() { return activeDelivery; }
};

int Vehicle ::activeDelivery = 0;

class RamzanDrone : public Vehicle
{
protected:
public:
    RamzanDrone(string id) : Vehicle(id) {}
};

class RamzanTimeShip : public Vehicle
{
protected:
public:
    RamzanTimeShip(string id) : Vehicle(id) {}
};

class RamzanHyperPod : public Vehicle
{
protected:
public:
    RamzanHyperPod(string id) : Vehicle(id) {}
};

int main()
{

    return 0;
}
