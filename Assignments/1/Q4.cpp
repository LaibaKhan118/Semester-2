#include <iostream>
using namespace std;

class Route
{
public:
    const string routes[5][3] = {
        {"Hyderi", "Sakhi", "Five"},
        {"Johar", "Continental", "Millennium"},
        {"Bahadurabad", "Char", "Numaish"},
        {"Saddar", "Burns", "Teen"},
        {"Defence", "Gizri", "Dolmen"}};
};

class Student
{
private:
    string name;
    string address;

public:
    Route *r;
    int id;
    bool paymentStatus;
    int pointNumber;
    static int studentCount;

    void setname(string name)
    {
        this->name = name;
    }
    string getname()
    {
        return name;
    }
    void setadd(string address)
    {
        this->address = address;
    }
    string getadd()
    {
        return address;
    }

    Student()
    {
        id = 0;
        name = "";
        address = "";
        paymentStatus = false;
    }

    Student(int id, string name, string address, bool paymentStatus, Route &r)
        : id(id), name(name), address(address), paymentStatus(paymentStatus), r(&r) {}

    void registerForTransportationAndPayFee(Route &r)
    {
        int choice;
        bool found = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (address == r.routes[i][j])
                {
                    if (paymentStatus)
                    {
                        pointNumber = i + 1;
                        cout << "You are registered. Your route number is " << pointNumber << endl;
                        cout << "You will be dropped off at Fast University in the morning and picked up in the evening." << endl;
                        studentCount++;
                        found = 1;
                        return;
                    }
                    else
                    {
                        cout << "Payment required for registration!" << endl;
                        found = 1;
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

    void studentDetails()
    {
        cout << endl
             << "---Student Details---" << endl;
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Payment Status: " << (paymentStatus ? "Paid" : "Not Paid");
        cout << "Point Number: " << pointNumber << endl;
    }
};

class Admin
{
public:
    int id;
    string name;
    string password;
    int response;
    static int adminCount;

    Admin()
    {
        id = 0;
        name = "";
        password = "";
    }

    Admin(int id, string name, string password)
        : id(id), name(name), password(password)
    {
        adminCount++;
    }

    void adminDetails()
    {
        cout << endl
             << "---Admin Details---" << endl;
        cout << "Admin ID: " << id << endl;
        cout << "Admin Name: " << name << endl;
    }

    void attendance(Student &s)
    {
        cout << endl
             << "---Attendance---" << endl;
        cout << s.getname() << " show you card please." << endl;
        cout << "Choose response: " << endl
             << "    1. Here is my card" << endl
             << "    2. I don't have my card" << endl;
        cin >> response;
        if (response == 1)
        {
            cout << "Your attendance is marked " << s.getname() << endl;
        }
        else if (response == 2)
        {
            cout << "Your attendance will not be marked " << s.getname() << endl;
        }
    }
};

int Student::studentCount = 0;
int Admin::adminCount = 0;

int main()
{
    Route r;
    Student s;
    Admin a;

    int x;
    cout << "\t---FAST Transportation System---" << endl;
    do
    {
        cout << "Enter choice:" << endl
             << "    1. Student" << endl
             << "    2. Admin" << endl
             << "    3. Exit" << endl
             << "Select an option: ";
        cin >> x;

        string address;
        string name;
        bool paymentStatus;
        int id;

        if (x == 1)
        {
            cout << "----Transportation System----" << endl;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your Student ID (XXXX): ";
            cin >> id;
            cout << "Enter your Payment Status" << endl
                 << "    (0 for unpaid and 1 for paid): ";
            cin >> paymentStatus;
            cout << "We provide transport service in the following areas: " << endl;
            int num = 1;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << num << ". " << r.routes[i][j] << endl;
                    num++;
                }
            }
            cout << "Enter your area name: ";
            cin >> address;
            s.setname(name);
            s.setadd(address);
            s = Student(id, name, address, paymentStatus, r);
            s.registerForTransportationAndPayFee(r);
        }

        else if (x == 2)
        {
            string password;
            cout << endl
                 << "----Admin Login----" << endl;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter password: ";
            cin >> password;
            a = Admin(id, name, password);
            a.adminDetails();
            a.attendance(s);
        }
        else if (x == 3)
        {
            cout << "Number of registered students: " << Student::studentCount << endl;
            cout << "Number of admins: " << Admin::adminCount << endl;
            cout << "Exiting the system..." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (x != 3);

    return 0;
}
