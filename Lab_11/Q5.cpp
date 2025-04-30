/*Create a template class BankAccount<T> where T is the currency type (e.g., double, int). Throw an Insufficient FundsException (class) if a withdrawal exceeds the balance. Include the deficit amount in the exception message.
Requirements:
withdraw(T amount) throws the exception if amount > balance.
Catch the exception and display the deficit.
Sample Input/Output:
Balance: $500.00
Withdraw $600: Insufficient FundsException - Deficit: $100.00*/

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class FundsException : public exception
{
private:
    string message;

public:
    FundsException(double deficit)
    {
        message = "Insufficient FundsException - Deficit: $" + to_string(deficit);
    }
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
class BankAccount
{
private:
    T balance;

public:
    BankAccount(T initialBalance) : balance(initialBalance) {}
    void deposit(T amount)
    {
        balance += amount;
    }
    void withdraw(T amount)
    {
        if (balance < amount)
        {
            throw FundsException(amount - balance);
        }
        balance -= amount;
    }

    T getBalance() const
    {
        return balance;
    }
};

int main()
{
    try
    {
        BankAccount<double> account(500.0);
        cout << "Balance: $" << account.getBalance() << endl;

        double withdrawAmount = 600.0;
        cout << "Depositing $" << withdrawAmount << endl;
        account.withdraw(withdrawAmount);
    }
    catch (const FundsException &e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}
