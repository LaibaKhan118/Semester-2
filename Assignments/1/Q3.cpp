#include <iostream>
using namespace std;

class User
{
private:
    int age;
    string licenseType;
    string contactInfo;
    int userId;

public:
    User() : age(0), licenseType(""), contactInfo(""), userId(0) {}

    int getAge() const { return age; }
    string getLicenseType() const { return licenseType; }
    string getContactInfo() const { return contactInfo; }
    int getUserId() const { return userId; }

    void setAge(int newAge) { age = newAge; }
    void setLicenseType(const string &newLicenseType) { licenseType = newLicenseType; }
    void setContactInfo(const string &newContactInfo) { contactInfo = newContactInfo; }
    void setUserId(int newUserId) { userId = newUserId; }

    void registerUser()
    {
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your license type (Learner, Intermediate, Full): ";
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
        cout << "1. Age\n2. License type\n3. Contact info\nEnter choice: ";
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

    void displayDetails() const
    {
        cout << "----INFORMATION OF USER: " << userId << "----" << endl;
        cout << "Age: " << age << endl;
        cout << "License Type: " << licenseType << endl;
        cout << "Contact Info: " << contactInfo << endl;
    }
};

class Vehicle
{
private:
    string model;
    int pricePerDay;
    string eligibility;

public:
    Vehicle() : model(""), pricePerDay(0), eligibility("") {}

    Vehicle(const string &m, int p, const string &e)
        : model(m), pricePerDay(p), eligibility(e) {}

    string getModel() const { return model; }
    int getPricePerDay() const { return pricePerDay; }
    string getEligibility() const { return eligibility; }

    void setModel(const string &newModel) { model = newModel; }
    void setPricePerDay(int newPrice) { pricePerDay = newPrice; }
    void setEligibility(const string &newEligibility) { eligibility = newEligibility; }
};

class RentalSystem
{
private:
    Vehicle *cars[5]; // Fixed-size array of pointers to Vehicle objects
    int carCount;

public:
    RentalSystem() : carCount(0)
    {
        cars[carCount++] = new Vehicle("Toyota Corolla", 55, "Full");
        cars[carCount++] = new Vehicle("Honda City", 50, "Intermediate");
        cars[carCount++] = new Vehicle("Volkswagen Polo", 35, "Learner");
        cars[carCount++] = new Vehicle("Ford Mustang", 85, "Full");
        cars[carCount++] = new Vehicle("Suzuki Alto", 40, "Intermediate");
    }

    ~RentalSystem()
    {
        for (int i = 0; i < carCount; i++)
        {
            delete cars[i];
        }
    }

    void displayAvailableCars() const
    {
        cout << "\n----Available Cars----\n"
             << endl;
        for (int i = 0; i < carCount; i++)
        {
            cout << "Car " << i + 1 << ":\n";
            cout << "Model: " << cars[i]->getModel() << endl;
            cout << "Rental price per day (dollars): " << cars[i]->getPricePerDay() << endl;
            cout << "Eligibility: " << cars[i]->getEligibility() << endl
                 << endl;
        }
    }

    void rentCar(const User &user)
    {
        int choice;
        cout << "Which car do you want to rent? (Enter number 1-" << carCount << "): ";
        cin >> choice;

        if (choice < 1 || choice > carCount)
        {
            cout << "Invalid selection.\n";
            return;
        }

        Vehicle *selectedCar = cars[choice - 1];

        if (user.getAge() < 18)
        {
            cout << "You are not eligible to rent a car.\n";
            return;
        }

        if (user.getLicenseType() == selectedCar->getEligibility() ||
            (user.getLicenseType() == "Full" && selectedCar->getEligibility() != "Full") ||
            (user.getLicenseType() == "Intermediate" && selectedCar->getEligibility() == "Learner"))
        {
            cout << "You have rented " << selectedCar->getModel() << " for $"
                 << selectedCar->getPricePerDay() << " per day.\n";
        }
        else
        {
            cout << "You are not eligible to rent " << selectedCar->getModel() << ".\n";
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
    cout << "Do you want to update any details (1: Yes, 0: No): ";
    cin >> a;

    if (a == 1)
    {
        u1.updateDetails();
    }
    u1.displayDetails();

    RentalSystem rentalSystem;
    rentalSystem.displayAvailableCars();
    rentalSystem.rentCar(u1);

    return 0;
}
/*
Mistakes In the Previous Code:
1. No Encapsulation
2. It didn't have a proper class to handle the cars list
3. Inflexible Array
4. No input Validation
5. Incomplete Eligibility Logic
*/
