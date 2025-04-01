// A2-Q1[24K-0644]
#include <iostream>
#include <string>
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

    bool operator==(const Route &other) const
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (routes[i][j] != other.routes[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Route &other) const
    {
        return !(*this == other);
    }
};

class UniversityMember
{
protected:
    string name;
    string address;
    int id;
    bool paymentStatus;
    int pointNumber;
    Route *route;
    static int memberCount;

public:
    UniversityMember() : id(0), name(""), address(""), paymentStatus(false), pointNumber(0), route(nullptr)
    {
        memberCount++;
    }

    UniversityMember(int id, const string &name, const string &address, bool paymentStatus, Route &route)
        : id(id), name(name), address(address), paymentStatus(paymentStatus), route(&route), pointNumber(0)
    {
        memberCount++;
    }

    virtual ~UniversityMember()
    {
        memberCount--;
    }

    string getName() const { return name; }
    string getAddress() const { return address; }
    int getId() const { return id; }
    bool getPaymentStatus() const { return paymentStatus; }
    int getPointNumber() const { return pointNumber; }
    static int getMemberCount() { return memberCount; }

    void setName(const string &newName) { name = newName; }
    void setAddress(const string &newAddress) { address = newAddress; }
    void setId(int newId) { id = newId; }
    void setPaymentStatus(bool newStatus) { paymentStatus = newStatus; }
    void setPointNumber(int newPointNumber) { pointNumber = newPointNumber; }

    virtual void registerForTransportation() = 0;
    virtual void displayDetails() const = 0;
    virtual void makePayment() = 0;
};

int UniversityMember::memberCount = 0;

class Student : public UniversityMember
{
private:
    static int studentCount;

public:
    Student() : UniversityMember()
    {
        studentCount++;
    }

    Student(int id, const string &name, const string &address, bool paymentStatus, Route &route)
        : UniversityMember(id, name, address, paymentStatus, route)
    {
        studentCount++;
    }

    ~Student()
    {
        studentCount--;
    }

    static int getStudentCount() { return studentCount; }

    void registerForTransportation() override
    {
        bool found = false;
        const string(*routes)[3] = route->getRoutes();

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
                            makePayment();
                            pointNumber = i + 1;
                            cout << "You are registered. Your route number is " << pointNumber << endl;
                            cout << "You will be dropped off at Fast University in the morning and picked up in the evening." << endl;
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

    void makePayment() override
    {
        paymentStatus = true;
        cout << "Semester fee paid successfully!" << endl;
    }

    void displayDetails() const override
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

int Student::studentCount = 0;

class Teacher : public UniversityMember
{
private:
    string department;
    static int teacherCount;

public:
    Teacher() : UniversityMember(), department("")
    {
        teacherCount++;
    }

    Teacher(int id, const string &name, const string &address, bool paymentStatus, Route &route, const string &department)
        : UniversityMember(id, name, address, paymentStatus, route), department(department)
    {
        teacherCount++;
    }

    ~Teacher()
    {
        teacherCount--;
    }

    static int getTeacherCount() { return teacherCount; }

    string getDepartment() const { return department; }
    void setDepartment(const string &newDepartment) { department = newDepartment; }

    void registerForTransportation() override
    {
        bool found = false;
        const string(*routes)[3] = route->getRoutes();

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
                            makePayment();
                            pointNumber = i + 1;
                            cout << "You are registered. Your route number is " << pointNumber << endl;
                            cout << "You will be dropped off at Fast University in the morning and picked up in the evening." << endl;
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

    void makePayment() override
    {
        paymentStatus = true;
        cout << "Monthly fee paid successfully!" << endl;
    }

    void displayDetails() const override
    {
        cout << endl
             << "---Teacher Details---" << endl;
        cout << "Teacher ID: " << id << endl;
        cout << "Teacher Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Address: " << address << endl;
        cout << "Payment Status: " << (paymentStatus ? "Paid" : "Not Paid") << endl;
        cout << "Point Number: " << pointNumber << endl;
    }
};

int Teacher::teacherCount = 0;

class Staff : public UniversityMember
{
private:
    string position;
    static int staffCount;

public:
    Staff() : UniversityMember(), position("")
    {
        staffCount++;
    }

    Staff(int id, const string &name, const string &address, bool paymentStatus, Route &route, const string &position)
        : UniversityMember(id, name, address, paymentStatus, route), position(position)
    {
        staffCount++;
    }

    ~Staff()
    {
        staffCount--;
    }

    static int getStaffCount() { return staffCount; }

    string getPosition() const { return position; }
    void setPosition(const string &newPosition) { position = newPosition; }

    void registerForTransportation() override
    {
        bool found = false;
        const string(*routes)[3] = route->getRoutes();

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
                            makePayment();
                            pointNumber = i + 1;
                            cout << "You are registered. Your route number is " << pointNumber << endl;
                            cout << "You will be dropped off at Fast University in the morning and picked up in the evening." << endl;
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

    void makePayment() override
    {
        paymentStatus = true;
        cout << "Monthly fee paid successfully!" << endl;
    }

    void displayDetails() const override
    {
        cout << endl
             << "---Staff Details---" << endl;
        cout << "Staff ID: " << id << endl;
        cout << "Staff Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Address: " << address << endl;
        cout << "Payment Status: " << (paymentStatus ? "Paid" : "Not Paid") << endl;
        cout << "Point Number: " << pointNumber << endl;
    }
};

int Staff::staffCount = 0;

class Admin
{
private:
    int id;
    string name;
    string password;
    static int adminCount;
    UniversityMember **members;
    int maxMembers;
    int currentMembers;

public:
    Admin() : id(0), name(""), password(""), members(nullptr), maxMembers(0), currentMembers(0)
    {
        adminCount++;
    }

    Admin(int id, const string &name, const string &password, int maxMembers)
        : id(id), name(name), password(password), maxMembers(maxMembers), currentMembers(0)
    {
        adminCount++;
        members = new UniversityMember *[maxMembers];
        for (int i = 0; i < maxMembers; i++)
        {
            members[i] = nullptr;
        }
    }

    ~Admin()
    {
        for (int i = 0; i < currentMembers; i++)
        {
            delete members[i];
        }
        delete[] members;
        adminCount--;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    static int getAdminCount() { return adminCount; }

    void setId(int newId) { id = newId; }
    void setName(const string &newName) { name = newName; }
    void setPassword(const string &newPassword) { password = newPassword; }

    void addMember(UniversityMember *member)
    {
        if (currentMembers < maxMembers)
        {
            members[currentMembers++] = member;
        }
        else
        {
            cout << "Maximum member capacity reached!" << endl;
        }
    }

    void displayAllMembers() const
    {
        cout << endl
             << "---All Registered Members---" << endl;
        for (int i = 0; i < currentMembers; i++)
        {
            members[i]->displayDetails();
        }
    }

    void adminDetails() const
    {
        cout << endl
             << "---Admin Details---" << endl;
        cout << "Admin ID: " << id << endl;
        cout << "Admin Name: " << name << endl;
    }

    UniversityMember *findMemberById(int searchId) const
    {
        for (int i = 0; i < currentMembers; i++)
        {
            if (members[i]->getId() == searchId)
            {
                return members[i];
            }
        }
        return nullptr;
    }

    void attendance(UniversityMember &member) const
    {
        cout << endl
             << "---Attendance---" << endl;
        cout << member.getName() << ", show your card please." << endl;
        cout << "Choose response: " << endl
             << "    1. Here is my card" << endl
             << "    2. I don't have my card" << endl;
        int response;
        cin >> response;
        if (response == 1)
        {
            cout << "Your attendance is marked, " << member.getName() << endl;
        }
        else if (response == 2)
        {
            cout << "Your attendance will not be marked, " << member.getName() << endl;
        }
    }
};

int Admin::adminCount = 0;

int main()
{
    Route route;
    Admin *admin = new Admin(1, "Admin1", "password123", 100); // Maximum 100 members

    int choice;
    cout << "\t---FAST Transportation System---" << endl;
    do
    {
        cout << "Enter choice:" << endl
             << "    1. Student Registration" << endl
             << "    2. Teacher Registration" << endl
             << "    3. Staff Registration" << endl
             << "    4. Admin Login" << endl
             << "    5. Display All Members" << endl
             << "    6. Exit" << endl
             << "Select an option: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3)
        {
            string name, address, extraInfo;
            int id;
            bool paymentStatus;

            cout << "----Transportation System----" << endl;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your ID (XXXX): ";
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

            if (choice == 1)
            {
                Student *student = new Student(id, name, address, paymentStatus, route);
                student->registerForTransportation();
                admin->addMember(student);
                student->displayDetails();
            }
            else if (choice == 2)
            {
                cout << "Enter your department: ";
                cin >> extraInfo;
                Teacher *teacher = new Teacher(id, name, address, paymentStatus, route, extraInfo);
                teacher->registerForTransportation();
                admin->addMember(teacher);
                teacher->displayDetails();
            }
            else if (choice == 3)
            {
                cout << "Enter your position: ";
                cin >> extraInfo;
                Staff *staff = new Staff(id, name, address, paymentStatus, route, extraInfo);
                staff->registerForTransportation();
                admin->addMember(staff);
                staff->displayDetails();
            }
        }
        else if (choice == 4)
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

            if (admin->getName() == name && admin->getId() == id && password == "password123")
            {
                admin->adminDetails();

                cout << "Enter member ID to mark attendance: ";
                int memberId;
                cin >> memberId;

                UniversityMember *member = admin->findMemberById(memberId);
                if (member)
                {
                    admin->attendance(*member);
                }
                else
                {
                    cout << "Member with ID " << memberId << " not found!" << endl;
                }
            }
            else
            {
                cout << "Invalid admin credentials!" << endl;
            }
        }
        else if (choice == 5)
        {
            admin->displayAllMembers();
        }
        else if (choice == 6)
        {
            cout << "Number of registered students: " << Student::getStudentCount() << endl;
            cout << "Number of registered teachers: " << Teacher::getTeacherCount() << endl;
            cout << "Number of registered staff: " << Staff::getStaffCount() << endl;
            cout << "Total university members: " << UniversityMember::getMemberCount() << endl;
            cout << "Number of admins: " << Admin::getAdminCount() << endl;
            cout << "Exiting the system..." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    delete admin;
    return 0;
}
