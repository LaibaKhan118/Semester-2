/*Q2: Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent toll. Mostly they do, but
sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of
the total amount of money collected.
Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total
number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of
these to 0. A member function called payingCar() increments the car total and adds 0.50 to the cash total.
Another
function, called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a member function called
display() displays the two totals. Make appropriate member functions const.
Include a program to test this class. This program should allow the user to push one key to count a paying car, and
another to count a nonpaying car. Pushing the Esc key should cause the program to print out the total cars and
total cash and then exit.*/

#include <iostream>
#include <conio.h>
#include <cstdio>
using namespace std;

class TollBooth
{
    unsigned int totalCars;
    double moneyCollected;

public:
    TollBooth() : totalCars(0), moneyCollected(0) {}
    void payingCar()
    {
        totalCars++;
        moneyCollected += 0.50;
    }
    void nopayCar()
    {
        totalCars++;
    }
    void display() const
    {
        cout << "Total Number of Cars: " << totalCars << endl;
        printf("Total money collected: $%.2f", moneyCollected); // Using printf to display proper cash format (with 2 decimal places)
        // cout << "Total money collected: " << moneyCollected << endl;
    }
};

int main()
{
    TollBooth b1;
    char ch;
    while (true)
    {
        cout << "\nPress P for a Paying car, N for a Non-Paying car, and ESC to display the total: ";
        ch = _getche(); // getche() also displays the inputted value on the screen and moves on (no enter required)
        if (ch == 27)
        {
            cout << endl
                 << endl;
            b1.display();
            break;
        }
        else if (ch == 'P' || ch == 'p')
        {
            b1.payingCar();
        }
        else if (ch == 'N' || ch == 'n')
        {
            b1.nopayCar();
        }
    }
    return 0;
}
