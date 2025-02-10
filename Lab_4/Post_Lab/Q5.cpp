/*You are building an employee management system. Create a class `Employee` to manage employee
records.
Requirements:
1. Attributes:
 `employeeID` (int)
 `name` (string)
 `department` (string)
 `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
 `isManager()`: Returns `true` if the employee's department is "Management".
 `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods.*/

#include <iostream>
using namespace std;

class Employee
{
private:
    int employeeID;
    string name;
    string department;
    double salary;

public:
    Employee() : employeeID(0), name("Unknown"), department("Unknown"), salary(0.0) {}
    Employee(int ID, string n, string dep, double s) : employeeID(ID), name(n), department(dep), salary(s) {}

    void giveBonus(double amount)
    {
        salary += amount;
        cout << "\nAdded bonus successfully.";
    }
    bool isManager()
    {
        return (this->department == "Management");
    }
    void displayDetails()
    {
        cout << "\nID: " << employeeID;
        cout << "\nName: " << name;
        cout << "\ndepartment: " << department;
        cout << "\nsalary: " << salary;
    }
};

int main()
{
    Employee e1;
    e1.displayDetails();

    Employee e2(123, "Laiba Khan", "IT", 50000);
    e2.displayDetails();
    e2.giveBonus(20000);
    e2.displayDetails();

    Employee e3(123, "Yumna Saleem", "Management", 50000);
    if (e3.isManager())
    {
        cout << "\nManager Details:";
        e3.displayDetails();
    }

    return 0;
}
