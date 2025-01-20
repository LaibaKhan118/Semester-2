// Q1: Write a C++ program to check whether a given number is prime or not. Allow the user to input a number and display whether it's prime or not?
#include <iostream>
using namespace std;

int main() {
    int a;
    bool flag = true;
    cout << "Enter a positive number: ";
    cin >> a;

    if(a == 0 || a == 1) {
        flag = false;
    }
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0)
        {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "It is a prime number";
    }
    else {
        cout << "It is not a prime number";
    }
}
