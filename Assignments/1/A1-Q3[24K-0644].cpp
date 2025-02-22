#include <iostream>
using namespace std;

class User
{
public:
    int age;
    string licenseType;
    string contactInfo;
    int userId;

    User()
    {
        age = 0;
        licenseType = "";
        contactInfo = "";
        userId = 0;
    }

    void registerUser()
    {
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your license type: " << endl;
        cout << "(Learner, Intermediate, Full): ";
        cin >> licenseType;
        cout << "Enter your contact information: ";
        cin >> contactInfo;
        cout << "Enter your user ID: ";
        cin >> userId;
        cout << "Congratulations! You have been registered." << endl;
    }

    void updateDetails()
    {
        int choice;
        cout << "What do you want to update?\n";
        cout << "1. Age\n2. license type\n3. contact info\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter new age: ";
            cin >> age;
            break;
        case 2:
            cout << "Enter new license type: ";
            cin >> licenseType;
            break;
        case 3:
            cout << "Enter new contact info: ";
            cin >> contactInfo;
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    }

    void displayDetails()
    {
        cout << "----INFORMATION OF USER: " << userId << "----" << endl;
        cout << "Age: " << age << endl;
        cout << "License Type: " << licenseType << endl;
        cout << "Contact Info: " << contactInfo << endl;
    }
};

class Vehicle
{
public:
    string model;
    int pricePerDay;
    string eligibility;

    Vehicle()
    {
        model = "";
        pricePerDay = 0;
        eligibility = "";
    }

    Vehicle(string m, int p, string e)
    {
        model = m;
        pricePerDay = p;
        eligibility = e;
    }

    Vehicle *cars[5];
    void addCar()
    {
        cars[0] = new Vehicle("Toyota Corolla", 55, "Full");
        cars[1] = new Vehicle("Honda City", 50, "Intermediate");
        cars[2] = new Vehicle("Volkswagen Polo", 35, "Learner");
        cars[3] = new Vehicle("Ford Mustang", 85, "Full");
        cars[4] = new Vehicle("Suzuki Alto", 40, "Intermediate");
    }

    void availableCars()
    {
        cout << "\n----Available Cars----\n"
             << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Model: " << cars[i]->model << endl;
            cout << "Rental price per day (dollars): " << cars[i]->pricePerDay << endl;
            cout << "Eligibility: " << cars[i]->eligibility << endl
                 << endl;
        }
    }

    void rentCar(User &u)
    {
        int a;
        cout << "Which car do you want to rent? (Enter number 1-5): ";
        cin >> a;

        if (a < 1 || a > 5)
        {
            cout << "Invalid selection.\n";
            return;
        }

        Vehicle *selected = cars[a - 1];
        if (u.age < 18)
        {
            cout << "You are not eligible to rent a car.\n";
            return;
        }
        if (u.licenseType == selected->eligibility ||
            (u.licenseType == "Full" && selected->eligibility != "Full") ||
            (u.licenseType == "Intermediate" && selected->eligibility == "Learner"))
        {
            cout << "You have rented " << selected->model << " for $"
                 << selected->pricePerDay << " per day.\n";
        }
        else
        {
            cout << "You are not eligible to rent " << selected->model << ".\n";
        }
    }
};

int main()
{
    User u1;
    int a;

    cout << "\n--Welcome to the Car Rental System--\n"
         << endl;

    u1.registerUser();
    cout << "Do you want to update any details(1: Yes, 0: No): ";
    cin >> a;

    if (a == 1)
    {
        u1.updateDetails();
    }
    u1.displayDetails();

    Vehicle v;
    v.addCar();
    v.availableCars();
    v.rentCar(u1);

    return 0;
}