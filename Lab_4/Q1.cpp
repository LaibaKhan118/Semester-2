#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int studentID;
    string name;
    int age;
    char grade;

public:
    Student() : studentID(0), name("Unknown"), age(0), grade('N') {}
    Student(int studentID, string name, int age, char grade)
    {
        this->studentID = studentID;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }
    void promoteStudent()
    {
        if (this->grade == 'N')
        {
            cout << "Cannot be promoted from grade N. Assign a grade first." << endl;
        }
        else if (this->grade == 'A')
        {
            cout << "This student already has the highest grade." << endl;
        }
        else if (this->grade == 'B')
        {
            this->grade = 'A';
        }
        else if (this->grade == 'C')
        {
            this->grade = 'B';
        }
        else if (this->grade == 'D')
        {
            this->grade = 'C';
        }
        else
        {
            cout << "Invalid grade!" << endl;
        }
    }

    bool isEligibleForScholarship()
    {
        return (this->grade == 'A');
    }

    void displayDetails()
    {
        cout << "\nStudent Details: " << endl;
        cout << "ID: " << this->studentID << endl;
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Grade: " << this->grade << endl;
    }
};

int main()
{
    Student s1;
    s1.displayDetails();

    Student s2(001, "Laiba", 19, 'B');
    s2.displayDetails();
    cout << "Eligibility for Scholarship: ";
    if (s2.isEligibleForScholarship())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    char op;
    cout << "Do you want to promote this student? (Y/N): ";
    cin >> op;
    if (op == 'Y' || op == 'y')
    {
        s2.promoteStudent();
    }
    s2.displayDetails();

    return 0;
}
