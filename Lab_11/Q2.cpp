/*Create a template class Stack<T> with a fixed capacity.
Implement methods push() and pop(). Throw:
StackOverflowException (class) if pushing to a full stack.
StackUnderflowException (class) if popping from an empty stack.
Requirements:
Both exceptions inherit from std::exception and override what().
Include error details (e.g., "Stack is full!").
Demonstrate exceptions in main().
Sample Input/Output:
Pushing to a full stack: StackOverflowException - Stack is full!
Popping from an empty stack: StackUnderflowException - Stack is empty!*/

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class StackOverflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Pushing to a full stack: StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Popping from an empty stack: StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack
{
private:
    T *data;
    int maxCap;
    int curr;

public:
    Stack(int cap) : maxCap(cap), curr(-1)
    {
        data = new T[maxCap];
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(const T &value)
    {
        if (curr >= maxCap - 1)
        {
            throw StackOverflowException();
        }
        data[++curr] = value;
    }

    T pop()
    {
        if (curr < 0)
        {
            throw StackUnderflowException();
        }
        return data[curr--];
    }
};

int main()
{
    try
    {
        Stack<int> stack(3);
        stack.push(10);
        stack.push(110);
        stack.push(20);
        stack.push(30); // pushing past capacity
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        Stack<int> stack1(3);
        stack1.pop(); // removing an element from empty array
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
