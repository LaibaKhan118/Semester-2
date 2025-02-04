//[24K-0644]
/*Q5: Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that
stores information about the current year. The user is allowed to store their tasks to do against each day. Assume
only one entry is needed per day.
Create the following methods for your class:
1. Add a task. Thisfunction accepts three parameters: task details, date and month. It should add
2. a task on the day specified.
3. Remove a task. Accepts the date and month as a parameter to remove the task from.
4. Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how
you’ll remove a task, and display the updated task list.*/

#include <iostream>
#include <string>
using namespace std;

class Calendar {
private:
    string tasks[12][31];
    int year;
public:
    Calendar(int year) {
        this->year = year;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 31; j++) {
                tasks[i][j] = "No Task";
            }
        }
    }

    void addTask(int day, int month, string details) {
        if(month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Wrong date!";
            return;
        }
        if ((month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
            cout << "Wrong date!";
            return;
        }
        tasks[month-1][day - 1] = details;
    }

    void removeTask(int day, int month) {
        if(month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Wrong date!";
            return;
        }
        if ((month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
            cout << "Wrong date!";
            return;
        }
        tasks[month-1][day - 1] = "No Task";
    }

    void showTasks() {
        for (int i = 0; i < 12; i++) {
            cout << "\nMonth " << i + 1 << ":" << endl;
            for (int j = 0; j < 31; j++) {
                if(tasks[i][j] != "No Task") {
                    cout << "  Day " << j + 1 << ": " << tasks[i][j] << endl;
                }
            }
        }
    }
};

int main()
{
    Calendar toDo(2025);
    
    toDo.addTask(5, 1, "Doctor's Appointment");
    toDo.addTask(12, 2, "Project Submission");
    toDo.addTask(23, 3, "Birthday Party");
    toDo.addTask(15, 4, "Meeting with Yumna");
    toDo.addTask(7, 5, "Buy Groceries");
    toDo.addTask(30, 6, "Vacation Trip");

    cout << "Initial List:" << endl;
    toDo.showTasks();

    toDo.removeTask(7, 5);

    cout << "\nUpdated List:" << endl;
    toDo.showTasks();
    return 0;
}
