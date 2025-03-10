#include <iostream>
using namespace std;

class Engine
{
private:
    string serialNumber;
    int horsepower;
    string type;

public:
    Engine(string serial, int hp, string t) : serialNumber(serial), horsepower(hp), type(t) {}

    void displayEngine() const
    {
        cout << "Engine Serial: " << serialNumber << ", HP: " << horsepower << ", Type: " << type << endl;
    }
};

class Car
{
private:
    string model, make, regNumber;
    Engine engine; // Composition (Car **owns** Engine)

public:
    Car(string m, string mk, string reg, string engSerial, int hp, string engType)
        : model(m), make(mk), regNumber(reg), engine(engSerial, hp, engType) {}

    void displayCar() const
    {
        cout << "Car: " << model << " by " << make << " (Reg#: " << regNumber << ")\n";
        engine.displayEngine();
    }
};

int main()
{
    Car c1("Corolla", "Toyota", "ABC-123", "ENG789", 130, "Petrol");

    c1.displayCar();

    return 0;
}
