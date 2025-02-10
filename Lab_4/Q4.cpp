/*You are building a car rental system. Create a class `Car` to manage cars available for rent.
Requirements:
1. Attributes:
 `carID` (int)
 `model` (string)
 `year` (int)
 `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:

 `rentCar()`: Marks the car as rented.
 `returnCar()`: Marks the car as available.
 `isVintage()`: Returns `true` if the car's year is before 2000.

5. Create a few `Car` objects and test the methods.*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    int carID;
    string model;
    int year;
    bool isRented;

public:
    Car() : carID(0), model("Unknown"), year(0), isRented(false) {};
    Car(int ID, string m, int y, bool rent) : carID(ID), model(m), year(y), isRented(rent) {};
    void rentCar()
    {
        if (!this->isRented)
        {
            this->isRented = true;
            cout << "\nRented Car Successfully.";
        }
        else
        {
            cout << "\nCar is already Rented.";
        }
    }
    void returnCar()
    {
        this->isRented = false;
        cout << "\nCar Returned Successfully.";
    }
    bool isVintage()
    {
        return (this->year < 2000);
    }
    void display()
    {
        cout << "\nDetails:" << endl;
        cout << "\nID: " << carID;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
        if (isRented == true)
            cout << "\nAvailability: Available";
        else
        {
            cout << "\nAvailability: Not Available";
        }
    }
};

int main()
{
    Car c1(1, "city", 2014, false);
    cout << "Car 1:";
    c1.display();
    if (c1.isVintage())
    {
        cout << "\nThis is a vintage car";
    }
    else
    {
        cout << "\nThis is not a vintage car";
    }
    char op;
    cout << "\nDo you want to rent this car? (Y/N): ";
    cin >> op;
    if (op == 'Y' || op == 'y')
    {
        c1.rentCar();
    }

    cout << "\nCar 2:";
    Car c2(2, "Corolla", 1995, true);
    c2.display();
    cout << "\nDo you want to return this car? (Y/N): ";
    cin >> op;
    if (op == 'Y' || op == 'y')
    {
        c1.returnCar();
    }

    return 0;
}
