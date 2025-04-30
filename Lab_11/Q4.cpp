/*Write a template function sqrt(T num) that computes the square root. Throw:
NegativeNumberException (class) if num is negative (for integers/doubles).
InvalidTypeException (class) if T is not numeric (e.g., string).
Requirements:
Use typeid or template specialization for type checks.
Handle both exceptions in main().
Sample Input/Output:
sqrt(-4): NegativeNumberException - Input must be non-negative!
sqrt("hello"): InvalidTypeException - Non-numeric type detected!*/

#include <iostream>
#include <cmath>
#include <string>
#include <type_traits>
#include <exception>
using namespace std;

class NegativeNumberException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "NegativeNumberException - Can't calculate the square root of a negative number.";
    }
};

class InvalidTypeException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "InvalidTypeException - Can't calculate the square root of a non-numeric value.";
    }
};

template <typename T>
T calc_sqrt(T num)
{
    if (!is_arithmetic<T>::value)
    {
        throw InvalidTypeException();
    }

    if (num < 0)
    {
        throw NegativeNumberException();
    }
    return sqrt(num);
}

template <>
string calc_sqrt<string>(string num)
{
    throw InvalidTypeException();
}

int main()
{
    try
    {
        cout << "sqrt(9): " << calc_sqrt(9) << endl;
        cout << "sqrt(-4): " << calc_sqrt(-4) << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        cout << "sqrt(hello): " << calc_sqrt(string("hello"));
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}
