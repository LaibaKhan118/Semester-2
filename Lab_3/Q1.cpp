/*Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor
should initialize this data to 0, and another should initialize it to fixed values. Another member function should
display it, in 11:59:59 format. The final member function should add two objects of type time passed as
arguments.
A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized.
Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should
display the value of this third variable. Make appropriate member functions const.*/

#include <iostream>
using namespace std;

class Time
{
    int hour;
    int mint;
    int sec;

public:
    Time() : hour(0), mint(0), sec(0) {}
    Time(int h, int m, int s) : hour(h), mint(m), sec(s) {}
    void display() const
    {
        if (hour <= 9)
        {
            cout << "0";
        }
        cout << hour << ":";
        if (mint <= 9)
        {
            cout << "0";
        }
        cout << mint << ":";
        if (sec <= 9)
        {
            cout << "0";
        }
        cout << sec;
    }
    void addTime(const Time &t1, const Time &t2)
    {
        sec = t1.sec + t2.sec;
        mint = t1.mint + t2.mint + (sec / 60);
        hour = t1.hour + t2.hour + (mint / 60);

        sec %= 60;
        mint %= 60;
        hour %= 24;
    }
};
int main()
{
    const Time t1(2, 45, 50);
    const Time t2(1, 20, 30);
    Time t3;
    t3.addTime(t1, t2);

    cout << "Time 1: ";
    t1.display();
    cout << "\nTime 2: ";
    t2.display();

    cout << "\nSum of time 1 and time 2: ";
    t3.display();
    return 0;
}
