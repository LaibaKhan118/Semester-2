#include <iostream>
using namespace std;

class Product
{
protected:
    string productID;
    double price;
    string category;

public:
    Product(string id, double p, string c) : productID(id), price(p), category(c) {}
    virtual ~Product() {}
    virtual double calculatePrice()
    {
        return price;
    };
    void display() const
    {
        cout << "Product ID: " << productID << "\n Price: Rs " << price << endl;
    }
    string getProductID() const { return productID; }
    double getPrice() const { return price; }
    void setPrice(double p) { price = p; }
};

class Electronics : public Product
{
public:
    Electronics(string id, double p, string c) : Product(id, p, c) {}
    double calculatePrice() override
    {
        price *= 1.15;
    }
};

class Clothing : public Product
{
public:
    Clothing(string id, double p, string c) : Product(id, p, c) {}
    double calculatePrice() override
    {
        price *= 1.05;
    }
};

class ShoppingCart
{
private:
    Product **items;
    int capacity;
    int count;
    string userType; // 0 for regular, 1 for premium
    void resize()
    {
        capacity *= 2;
        Product **newItems = new Product *[capacity];
        for (int i = 0; i < count; i++)
        {
            newItems[i] = items[i];
        }
        delete items;
        items = newItems;
    }

public:
    ShoppingCart(int type) : capacity(10), count(0)
    {
        if (type == 1)
        {
            userType = "PREMIUM";
        }
        else
        {
            userType = "REGULAR";
        }
        items = new Product *[capacity];
    }

    ~ShoppingCart()
    {
        for (int i = 0; i < count; i++)
        {
            delete items[i];
        }
        delete items;
    }
};

int main()
{

    return 0;
}
