#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Grade Point Equivalents
map<char, double> gradePoints = {{'A', 4.0}, {'B', 3.0}, {'C', 2.0}, {'D', 1.0}, {'F', 0.0}};

// Course Class
class Course
{
private:
    string courseName, courseCode;
    int creditHours;

public:
    Course(string name, string code, int credits) : courseName(name), courseCode(code), creditHours(credits) {}

    void showCourseInfo()
    {
        cout << "Course Name: " << courseName << ", Course Code: " << courseCode << ", Credit Hours: " << creditHours << endl;
    }

    int getCreditHours() { return creditHours; }
    string getCourseCode() { return courseCode; }
};

// Student Class
class Student
{
private:
    string studentID, studentName;
    int numCourses;
    vector<Course> courses;
    vector<char> grades;
    double tuitionFee;

public:
    Student(string id, string name, int num) : studentID(id), studentName(name), numCourses(num), tuitionFee(0) {}

    void addCourse(Course c, char grade)
    {
        courses.push_back(c);
        grades.push_back(grade);
    }

    void displayStudentInfo()
    {
        cout << "\nStudent Name: " << studentName << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Number of Courses: " << numCourses << endl;
    }

    void displayCourses()
    {
        cout << "Courses Enrolled:\n";
        for (size_t i = 0; i < courses.size(); i++)
        {
            courses[i].showCourseInfo();
            cout << "Grade: " << grades[i] << endl;
        }
    }

    bool isEnrolledIn(string courseCode)
    {
        for (Course c : courses)
        {
            if (c.getCourseCode() == courseCode)
            {
                return true;
            }
        }
        return false;
    }

    double calculateGPA()
    {
        double totalPoints = 0;
        int totalCredits = 0;
        int failCount = 0;

        for (size_t i = 0; i < courses.size(); i++)
        {
            totalPoints += gradePoints[grades[i]] * courses[i].getCreditHours();
            totalCredits += courses[i].getCreditHours();
            if (grades[i] == 'F')
            {
                failCount++;
            }
        }

        if (failCount >= 2)
        {
            cout << "LOCKED GRADE (Too many failed courses)\n";
            return -1;
        }

        return (totalCredits == 0) ? 0 : totalPoints / totalCredits;
    }

    void calculateTuitionFee()
    {
        int totalCredits = 0;
        for (Course c : courses)
        {
            totalCredits += c.getCreditHours();
        }

        tuitionFee = (totalCredits * 85) * 1.05; // Adding 5% tax
    }

    void displayTuitionFee()
    {
        cout << "Total Tuition Fee (including 5% tax): $" << tuitionFee << endl;
    }
};

// Main Function
int main()
{
    string studentName, studentID;
    int numCourses;

    cout << "Enter Student Name: ";
    cin >> studentName;
    cout << "Enter Student ID: ";
    cin >> studentID;
    cout << "Enter Number of Courses Enrolled: ";
    cin >> numCourses;

    Student student(studentID, studentName, numCourses);

    // Adding Courses
    for (int i = 0; i < numCourses; i++)
    {
        string cName, cCode;
        int cCredits;
        char grade;

        cout << "\nEnter Course " << i + 1 << " Name: ";
        cin >> cName;
        cout << "Enter Course Code: ";
        cin >> cCode;
        cout << "Enter Credit Hours: ";
        cin >> cCredits;
        cout << "Enter Grade (A-F): ";
        cin >> grade;

        Course course(cName, cCode, cCredits);
        student.addCourse(course, grade);
    }

    // Display Student and Course Info
    student.displayStudentInfo();
    student.displayCourses();

    // GPA Calculation
    double gpa = student.calculateGPA();
    if (gpa != -1)
    {
        cout << "Calculated GPA: " << gpa << endl;
    }

    // Tuition Fee Calculation
    student.calculateTuitionFee();
    student.displayTuitionFee();

    return 0;
}
