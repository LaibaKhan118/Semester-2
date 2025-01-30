// Q5: Write a program that shift n characters 
// of a sring from end to start.

#include <iostream>
#include <string>
using namespace std;

void shift(string &str, int n);

int main()
{
    string str;
    int n;
    cout << "Enter a word: ";
    cin >> str;

    cout << "Number of characters you want to shift: ";
    cin >> n;

    shift(str, n);

    cout << "\nModified String: " << str << endl;

    return 0;
}

void shift(string &str, int n)
{
    int len = str.length();
    if (n <= 0 || n >= len)
    {
        cout << "Invalid shift value. No changes made.\n";
        return;
    }

    char *temp = new char[len + 1];

    char *end = &str[len - n];
    char *start = temp;

    for (int i = 0; i < n; i++)
    {
        *(start++) = *(end++);
    }

    end = &str[0];
    for (int i = 0; i < len - n; i++)
    {
        *(start++) = *(end++);
    }

    *(start++) = '\0';

    str = temp;

    delete[] temp;

    /* ==== An easier way
    string end = str.substr(len - n, n);
    string start = str.substr(0, len - n);

    str = end + start;
    */
}
