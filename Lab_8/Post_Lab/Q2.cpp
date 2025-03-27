#include <iostream>
using namespace std;

class Product
{
protected:
    string productID;
    double price;

public:
    Product(string id, double p) : productID(id), price(p) {}
    virtual void calculatePrice() = 0;
    void display() const
    {
        cout << "Product ID: " << productID << "\n Price: Rs " << price << endl;
    }
};

class Electronics : public Product
{
public:
    Electronics(string id, double p) : Product(id, p) {}
    void calculatePrice() override
    {
        price *= 0.15;
    }
};

class Clothing : public Product
{
public:
    Clothing(string id, double p) : Product(id, p) {}
    void calculatePrice() override
    {
        price *= 0.05;
    }
};

int main()
{

    return 0;
}
