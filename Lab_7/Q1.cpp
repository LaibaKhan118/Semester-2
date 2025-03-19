// Q1: Account Management
#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int num = 000, string n = "Unknown", string t = "None") : accountNumber(num), balance(0), accountHolderName(n), accountType(t) {}
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "An amount of " << amount << " deposited successfully\n";
        }
        else
        {
            cout << "Invalid Deposit Amount\n";
        }
    }
    virtual void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "An amount of " << amount << " withdrawn successfully\n";
        }
        else
        {
            cout << "Insufficient Balance\n";
        }
    }
    virtual void calculateInterest() = 0;
    virtual void printStatement()
    {
        cout << "Account Statement for Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl; // In real world, we will have a system to store previous transactions
    }
    virtual void getAccountInfo()
    {
        cout << "Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    virtual ~Account() {}
};

class SavingsAccount : public Account
{
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(double rate = 0, double min = 0, int num = 0, string n = "Unknown", string t = "None") : interestRate(rate), minimumBalance(min), Account(num, n, t) {}
    void calculateInterest() override
    {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest: " << interest << "\nNew Balance: " << balance << endl;
    }
    void withdraw(double amount) override
    {
        if (balance - amount > minimumBalance)
        {
            Account::withdraw(amount);
        }
        else
        {
            cout << "Withdrawal denied! Maintaining minimum balance is required." << endl;
        }
    }
    void printStatement() override
    {
        Account::printStatement();
        cout << "Minimum Balance: " << minimumBalance << endl;
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int num = 000, string n = "Unknown", string t = "None") : Account(num, n, t) {}
    void calculateInterest() override
    {
        cout << "There's No Interest For Current Accounts.\n";
    }
};

class FixedDepositAccount : public Account
{
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(double rate = 0, string date = 0, int num = 000, string n = "Unknown", string t = "None") : fixedInterestRate(rate), maturityDate(date), Account(num, n, t) {}
    void calculateInterest() override
    {
        double interest = balance * fixedInterestRate / 100;
        balance += interest;
        cout << "Interest: " << interest << "\nNew Balance: " << balance << endl;
    }
    void withdraw(double amount) override
    {
        cout << "Withdrawal is not allowed before maturity date." << endl;
    }
    void printStatement() override
    {
        Account::printStatement();
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Fixed Interest Rate: " << fixedInterestRate << endl;
    }
};

int main()
{
    SavingsAccount sa(2, 5000, 4546, "Laiba Khan", "Savings");
    CheckingAccount ca(1423, "Yumna Khan", "Savings");
    FixedDepositAccount fda(5, "2026-01-01", 12663, "Ayesha Khan", "Savings");

    cout << "\n--- Savings Account Info ---\n";
    sa.getAccountInfo();
    cout << "Depositing 30000:" << endl;
    sa.deposit(30000);
    cout << "Calculating Interest: " << endl;
    sa.calculateInterest();
    sa.printStatement();
    cout << "Withdrawing 40000:";
    sa.withdraw(40000);

    cout << "\n--- Checking Account Info ---\n";
    ca.getAccountInfo();
    cout << "Depositing 30000:" << endl;
    ca.deposit(30000);
    cout << "Calculating Interest: " << endl;
    ca.calculateInterest();
    ca.printStatement();
    cout << "Withdrawing 40000:";
    ca.withdraw(40000);

    cout << "\n--- Fixed Deposit Account Info ---\n";
    fda.getAccountInfo();
    cout << "Depositing 30000:" << endl;
    fda.deposit(30000);
    cout << "Calculating Interest: " << endl;
    fda.calculateInterest();
    fda.printStatement();
    cout << "Withdrawing 40000:";
    fda.withdraw(40000);

    return 0;
}
