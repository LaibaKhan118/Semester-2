/*Write a class that represents a car, and use aggregation and composition to combine different components like engine, wheels, headlights and steering to create the car object.
Hint: create the individual classes first before performing the composition. Remember that for aggregation, you will need pointers! You’ll be needing constructors and setters to set these values in case of aggregation. Same hint applies to other questions.*/

#include <iostream>
#include <string>
using namespace std;

class Engine
{
private:
    int horsepower;

public:
    Engine(int hp = 100) : horsepower(hp)
    {
        cout << "Engine Created with " << horsepower << " HP!" << endl;
    }
    ~Engine()
    {
        cout << "Engine Destroyed!" << endl;
    }

    void setHorsepower(int hp) { horsepower = hp; }
    int getHorsepower() const { return horsepower; }
};

class Wheel
{
private:
    int size;

public:
    Wheel(int s = 16) : size(s)
    {
        cout << "Wheel Created with size " << size << " inches!" << endl;
    }
    ~Wheel()
    {
        cout << "Wheel Destroyed!" << endl;
    }

    void setSize(int s) { size = s; }
    int getSize() const { return size; }
};

class Headlight
{
private:
    string type;

public:
    Headlight(string t = "LED") : type(t)
    {
        cout << "Headlight Created with type: " << type << "!" << endl;
    }
    ~Headlight()
    {
        cout << "Headlight Destroyed!" << endl;
    }

    void setType(string t) { type = t; }
    string getType() const { return type; }
};

class Steering
{
private:
    string material;

public:
    Steering(string m = "Leather") : material(m)
    {
        cout << "Steering Created with material: " << material << "!" << endl;
    }
    ~Steering()
    {
        cout << "Steering Destroyed!" << endl;
    }

    void setMaterial(string m) { material = m; }
    string getMaterial() const { return material; }
};

class Car
{
private:
    Engine engine;
    Steering steering;
    Wheel *wheels;
    Headlight *headlights;

public:
    Car(Engine e, Steering s, Wheel *w, Headlight *h) : engine(e), steering(s)
    {
        wheels = new Wheel[4];
        headlights = new Headlight[2];

        for (int i = 0; i < 4; i++)
            wheels[i] = w[i];

        for (int i = 0; i < 2; i++)
            headlights[i] = h[i];

        cout << "Car Created!" << endl;
    }

    ~Car()
    {
        delete[] wheels;
        delete[] headlights;
        cout << "Car Destroyed!" << endl;
    }

    Engine getEngine() const { return engine; }
    Steering getSteering() const { return steering; }
    Wheel *getWheels() const { return wheels; }
    Headlight *getHeadlights() const { return headlights; }
};

int main()
{
    Engine myEngine(150);
    Steering mySteering("Wooden");

    Wheel wheels[4] = {Wheel(17), Wheel(17), Wheel(17), Wheel(17)};
    Headlight headlights[2] = {Headlight("Halogen"), Headlight("Halogen")};

    Car myCar(myEngine, mySteering, wheels, headlights);

    cout << "\nCar Details:\n";
    cout << "Engine Horsepower: " << myCar.getEngine().getHorsepower() << " HP\n";
    cout << "Steering Material: " << myCar.getSteering().getMaterial() << "\n";
    cout << "Wheel Size: " << myCar.getWheels()[0].getSize() << " inches\n";
    cout << "Headlight Type: " << myCar.getHeadlights()[0].getType() << "\n";

    return 0;
}
