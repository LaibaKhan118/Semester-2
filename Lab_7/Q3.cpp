#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Currency
{
protected:
    double amount;
    string code;
    string symbol;
    float exchangeRate;

public:
    Currency(double a, string c, string s, float e) : amount(a), code(c), symbol(s), exchangeRate(e) {}
    virtual double convertToBase()
    {
        return amount / exchangeRate;
    }
    virtual double convertTo(const Currency &targetCurrency)
    {
        double base = convertToBase();
        return base * targetCurrency.exchangeRate;
    }
    virtual void display() const
    {
        cout << fixed << setprecision(2);
        cout << "Amount: " << symbol << amount << " (" << code << ")\n";
    }
};

class Dollar : public Currency
{
public:
    Dollar(double a) : Currency(a, "USD", "$", 0.0036) {}
    void display() const override
    {
        cout << fixed << setprecision(2);
        cout << "Dollar Amount: " << symbol << amount << " (" << code << ")\n";
    }
};

class Euro : public Currency
{
public:
    Euro(double a) : Currency(a, "EUR", "E", 0.0033) {} // using E instead of the symbol because the terminal failed to represent it properly
    void display() const override
    {
        cout << fixed << setprecision(2);
        cout << "Euro Amount: " << symbol << amount << " (" << code << ")\n";
    }
};

class Rupee : public Currency
{
public:
    Rupee(double a) : Currency(a, "PKR", "Rs", 1.0) {}
    void display() const override
    {
        cout << fixed << setprecision(2);
        cout << "Rupee Amount: " << symbol << amount << " (" << code << ")\n";
    }
};

int main()
{
    Currency *c[3];
    c[0] = new Dollar(100);
    c[1] = new Euro(100);
    c[2] = new Rupee(100);

    cout << "Original Currencies: " << endl;
    for (int i = 0; i < 3; i++)
    {
        c[i]->display();
    }

    cout << "\n100 USD to PKR: " << c[0]->convertTo(*c[2]) << " Rs\n";
    cout << "100 Euro to PKR: " << c[1]->convertTo(*c[2]) << " Rs\n";
    cout << "100 PKR to PKR: " << c[2]->convertTo(*c[2]) << " Rs\n";

    return 0;
}
