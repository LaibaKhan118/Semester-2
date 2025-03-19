#include <iostream>
using namespace std;

class Person
{
protected:
    int id;
    string name;
    string address;
    string phone;
    string email;

public:
    Person(int i, string n, string a, string p, string e) : id(i), name(n), address(a), phone(p), email(e) {}

    virtual void display() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(int i, string n, string a, string p, string e)
    {
        id = i;
        name = n;
        address = a;
        phone = p;
        email = e;
    }

    string getName() const { return name; }
};

class Student : public Person
{
private:
    string *coursesEnrolled;
    int num;
    float GPA;
    int enrollmentYear;

public:
    Student(string *c, int no, float g, int y, int i, string n, string a, string p, string e)
        : GPA(g), num(no), enrollmentYear(y), Person(i, n, a, p, e)
    {
        coursesEnrolled = new string[num];
        for (int i = 0; i < num; i++)
        {
            coursesEnrolled[i] = c[i];
        }
    }

    void display() const override
    {
        Person::display();
        cout << "Courses Enrolled: " << endl;
        for (int i = 0; i < num; i++)
        {
            cout << "   Course " << i + 1 << ": " << coursesEnrolled[i] << endl;
        }

        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }

    float getGPA() const { return GPA; }

    ~Student()
    {
        delete[] coursesEnrolled;
    }
};

class Professor : public Person
{
private:
    string department;
    string *coursesTaught;
    int num;
    double salary;

public:
    Professor(string d, string *c, int no, double s, int i, string n, string a, string p, string e)
        : department(d), num(no), salary(s), Person(i, n, a, p, e)
    {
        coursesTaught = new string[num];
        for (int i = 0; i < num; i++)
        {
            coursesTaught[i] = c[i];
        }
    }

    void display() const override
    {
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << endl;
        for (int i = 0; i < num; i++)
        {
            cout << "   Course " << i + 1 << ": " << coursesTaught[i] << endl;
        }
        cout << "Salary: " << salary << endl;
    }

    ~Professor()
    {
        delete[] coursesTaught;
    }
};

class Staff : public Person
{
private:
    string department;
    string position;
    double salary;

public:
    Staff(string d, string pos, double s, int i, string n, string a, string p, string e)
        : department(d), position(pos), salary(s), Person(i, n, a, p, e) {}

    void display() const override
    {
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course
{
private:
    int id;
    string name;
    int credit;
    Professor *instructor;
    string schedule;
    Student **enrolledStudents;
    int max;
    int enrolled;

public:
    Course(int i, string n, int c, Professor *p, string s, int m)
        : id(i), name(n), credit(c), instructor(p), schedule(s), max(m), enrolled(0)
    {
        enrolledStudents = new Student *[max];
    }

    ~Course()
    {
        delete[] enrolledStudents;
    }

    void enrollStudent(Student *s)
    {
        if (enrolled < max)
        {
            enrolledStudents[enrolled++] = s;
            cout << s->getName() << " has been registered for " << name << "." << endl;
        }
        else
        {
            cout << "Course is full. Can't enroll " << s->getName() << "." << endl;
        }
    }

    void calculateGrade()
    {
        for (int i = 0; i < enrolled; i++)
        {
            char grade;
            float gpa = enrolledStudents[i]->getGPA();

            if (gpa >= 3.5)
                grade = 'A';
            else if (gpa >= 3.0)
                grade = 'B';
            else if (gpa >= 2.5)
                grade = 'C';
            else if (gpa >= 2.0)
                grade = 'D';
            else
                grade = 'F';

            cout << "Grade of " << enrolledStudents[i]->getName() << " is: " << grade << endl;
        }
    }

    void display() const
    {
        cout << "Course ID: " << id << "\nCourse Name: " << name
             << "\nCredits: " << credit << "\nInstructor: " << instructor->getName() << endl;
        cout << "Enrolled Students: ";
        if (enrolled == 0)
        {
            cout << "None";
        }
        else
        {
            for (int i = 0; i < enrolled; i++)
            {
                cout << enrolledStudents[i]->getName();
                if (i < enrolled - 1)
                    cout << ", ";
            }
        }
        cout << endl;
    }
};

int main()
{
    string courses[] = {"OOP", "Data Structures"};
    Student s1(courses, 2, 3.8, 2023, 1, "Faiza", "123 St", "123456", "alice@email.com");
    Student s2(courses, 2, 2.7, 2023, 2, "Ali", "456 St", "789012", "bob@email.com");

    string profCourses[] = {"OOP"};
    Professor p1("Computer Science", profCourses, 1, 80000, 3, "Sir Safique", "Uni Campus", "111111", "smith@university.com");

    Course oop(101, "Object Oriented Programming", 3, &p1, "MWF 10AM", 2);
    oop.enrollStudent(&s1);
    oop.enrollStudent(&s2);
    cout << "\nCourse Details: \n";
    oop.display();

    cout << "\nCalculating Grades...\n";
    oop.calculateGrade();

    return 0;
}
