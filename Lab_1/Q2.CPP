// Design a C++ program to manage student marks. Allow the user to input marks for students in three subjects (Mathematics, English, and Science). 
// The program should calculate the total marks, average marks, and display the grade for each student. 
// The user can specify the number of students and then input the marks for each subject for each student. 
// Finally, display the marks, total, average, and grade for each student. Assume a grading system with the following criteria:
// 90 or above: Grade A
// 80-89: Grade B
// 70-79: Grade C
// 60-69: Grade D
// Below 60: Grade F

#include <iostream>
using namespace std;

int main() {
    int n;
    float math, sci, eng, total = 0, avg, percentage;
    char grade;

    cout << "Enter the number of students: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        // Assuming each subject has total of 100 marks
        cout << "Enter Math marks of student " << i+1 << ": ";
        cin >> math;
        cout << "Enter Eng marks of student " << i+1 << ": ";
        cin >> eng;
        cout << "Enter Sci marks of student " << i+1 << ": ";
        cin >> sci;
        total = math + eng + sci;
        avg = total / 3;
        percentage = (total / 300) * 100;
        if (percentage < 60) {
            grade = 'F';
        }
        else if (percentage >= 60 && percentage < 70) {
            grade = 'D';
        }
        else if (percentage >= 70 && percentage < 80) {
            grade = 'C';
        }
        else if (percentage >= 80 && percentage < 90) {
            grade = 'B';
        }
        else if (percentage >= 80 && percentage < 90) {
            grade = 'A';
        }
        cout << "\nThe total marks of student " << i+1 << ": " << total;
        cout << "\nThe avg marks of student " << i+1 << ": " << avg;
        cout << "\nThe grade of student " << i+1 << ": " << grade << endl;
    }
}