#include <iostream>
using namespace std;

class Course
{
private:
    string courseCode, title;
    int creditHours;

public:
    Course(string code, string t, int credits) : courseCode(code), title(t), creditHours(credits) {}

    void displayCourse() const
    {
        cout << "Course: " << title << " (" << courseCode << "), Credits: " << creditHours << endl;
    }

    string getCourseCode() const { return courseCode; }
};

class Student
{
private:
    string studentID, name;
    Course *enrolledCourse; // Association (Student knows about Course)

public:
    Student(string id, string n) : studentID(id), name(n), enrolledCourse(nullptr) {}

    void enroll(Course *c) { enrolledCourse = c; } // Linking student to a course

    void displayStudent() const
    {
        cout << "Student: " << name << " (ID: " << studentID << ")\n";
        if (enrolledCourse)
            enrolledCourse->displayCourse();
        else
            cout << "No course enrolled yet.\n";
    }
};

int main()
{
    Course c1("CS101", "Object-Oriented Programming", 3);
    Student s1("S123", "Ali Khan");

    s1.enroll(&c1);
    s1.displayStudent();

    return 0;
}
