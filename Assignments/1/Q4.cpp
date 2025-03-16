#include <iostream>
using namespace std;

class Route
{
private:
    const string routes[5][3] = {
        {"Hyderi", "SakhiHassan", "FiveStar"},
        {"Johar", "Continental", "Millennium"},
        {"Bahadurabad", "Gulshan", "Numaish"},
        {"Saddar", "BurnsRd", "TeenTalwar"},
        {"Defence", "Gizri", "Dolmen"}};

public:
    const string (*getRoutes() const)[3] { return routes; }
};

class Student
{
private:
    string name;
    string address;
    int id;
    bool paymentStatus;
    int pointNumber;
    Route *route;
    static int studentCount;

public:
    string getName() const { return name; }
    string getAddress() const { return address; }
    int getId() const { return id; }
    bool getPaymentStatus() const { return paymentStatus; }
    int getPointNumber() const { return pointNumber; }
    static int getStudentCount() { return studentCount; }

    void setName(const string &newName) { name = newName; }
    void setAddress(const string &newAddress) { address = newAddress; }
    void setId(int newId) { id = newId; }
    void setPaymentStatus(bool newStatus) { paymentStatus = newStatus; }
    void setPointNumber(int newPointNumber) { pointNumber = newPointNumber; }

    Student() : id(0), name(""), address(""), paymentStatus(false), pointNumber(0), route(nullptr) {}

    Student(int id, const string &name, const string &address, bool paymentStatus, Route &route)
        : id(id), name(name), address(address), paymentStatus(paymentStatus), route(&route), pointNumber(0) {}

    void registerForTransportationAndPayFee(Route &route)
    {
        bool found = false;
        const string(*routes)[3] = route.getRoutes();

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (address == routes[i][j])
                {
                    if (paymentStatus)
                    {
                        pointNumber = i + 1;
                        cout << "You are registered. Your route number is " << pointNumber << endl;
                        cout << "You will be dropped off at Fast University in the morning and picked up in the evening." << endl;
                        studentCount++;
                        found = true;
                        return;
                    }
                    else
                    {
                        cout << "Payment required for registration!" << endl;
                        found = true;
                        int choice;
                        cout << "Do you want to pay now? (1 for yes, 0 for no)" << endl;
                        cin >> choice;
                        if (choice == 1)
                        {
                            paymentStatus = true;
                            pointNumber = i + 1;
                            cout << "You are registered. Your route number is " << pointNumber << endl;
                            cout << "You will be dropped off at Fast University in the morning and picked up in the evening." << endl;
                            studentCount++;
                            return;
                        }
                        else
                        {
                            cout << "Registration failed!" << endl;
                        }
                        return;
                    }
                }
            }
        }
        if (!found)
        {
            cout << "Sorry, we do not provide transport service for " << address << endl;
        }
    }

    void studentDetails() const
    {
        cout << endl
             << "---Student Details---" << endl;
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Payment Status: " << (paymentStatus ? "Paid" : "Not Paid") << endl;
        cout << "Point Number: " << pointNumber << endl;
    }
};

class Admin
{
private:
    int id;
    string name;
    string password;
    static int adminCount;

public:
    int getId() const { return id; }
    string getName() const { return name; }
    static int getAdminCount() { return adminCount; }

    void setId(int newId) { id = newId; }
    void setName(const string &newName) { name = newName; }
    void setPassword(const string &newPassword) { password = newPassword; }

    Admin() : id(0), name(""), password("")
    {
        adminCount++;
    }

    Admin(int id, const string &name, const string &password)
        : id(id), name(name), password(password)
    {
        adminCount++;
    }

    void adminDetails() const
    {
        cout << endl
             << "---Admin Details---" << endl;
        cout << "Admin ID: " << id << endl;
        cout << "Admin Name: " << name << endl;
    }

    void attendance(Student &student) const
    {
        cout << endl
             << "---Attendance---" << endl;
        cout << student.getName() << ", show your card please." << endl;
        cout << "Choose response: " << endl
             << "    1. Here is my card" << endl
             << "    2. I don't have my card" << endl;
        int response;
        cin >> response;
        if (response == 1)
        {
            cout << "Your attendance is marked, " << student.getName() << endl;
        }
        else if (response == 2)
        {
            cout << "Your attendance will not be marked, " << student.getName() << endl;
        }
    }
};

int Student::studentCount = 0;
int Admin::adminCount = 0;

int main()
{
    Route route;
    Student student;
    Admin admin;

    int choice;
    cout << "\t---FAST Transportation System---" << endl;
    do
    {
        cout << "Enter choice:" << endl
             << "    1. Student" << endl
             << "    2. Admin" << endl
             << "    3. Exit" << endl
             << "Select an option: ";
        cin >> choice;

        if (choice == 1)
        {
            string name, address;
            int id;
            bool paymentStatus;

            cout << "----Transportation System----" << endl;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your Student ID (XXXX): ";
            cin >> id;
            cout << "Enter your Payment Status" << endl
                 << "    (0 for unpaid and 1 for paid): ";
            cin >> paymentStatus;
            cout << "We provide transport service in the following areas: " << endl;
            const string(*routes)[3] = route.getRoutes();
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << (i * 3 + j + 1) << ". " << routes[i][j] << endl;
                }
            }
            cout << "Enter your area name: ";
            cin >> address;

            student.setName(name);
            student.setAddress(address);
            student.setId(id);
            student.setPaymentStatus(paymentStatus);
            student.registerForTransportationAndPayFee(route);
            student.studentDetails();
        }
        else if (choice == 2)
        {
            string name, password;
            int id;

            cout << endl
                 << "----Admin Login----" << endl;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter password: ";
            cin >> password;

            admin.setName(name);
            admin.setId(id);
            admin.setPassword(password);
            admin.adminDetails();
            admin.attendance(student);
        }
        else if (choice == 3)
        {
            cout << "Number of registered students: " << Student::getStudentCount() << endl;
            cout << "Number of admins: " << Admin::getAdminCount() << endl;
            cout << "Exiting the system..." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
/*
Things That Were Wrong In The Previous Code:
1. No Encapsulation
2. Inflexible Data
3. Input Validation
4. No proper use of static members
*/
