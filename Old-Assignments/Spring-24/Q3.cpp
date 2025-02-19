#include <iostream>
#include <vector>

using namespace std;

// Base Class: Product
class Product
{
protected:
    string name;
    double price;

public:
    Product(string n, double p) : name(n), price(p) {}

    virtual void getInfo()
    {
        cout << "Product Name: " << name << ", Price: $" << price << endl;
    }

    virtual void purchase()
    {
        cout << "Purchased: " << name << " for $" << price << endl;
    }

    double getPrice() { return price; }
};

// Derived Class: Book
class Book : public Product
{
private:
    string author;

public:
    Book(string n, double p, string a) : Product(n, p), author(a) {}

    void getInfo() override
    {
        Product::getInfo();
        cout << "Author: " << author << endl;
    }

    void purchase() override
    {
        cout << "Purchased Book: " << name << " by " << author << " for $" << price << endl;
    }
};

// Derived Class: Electronics
class Electronics : public Product
{
private:
    int warranty; // Warranty in months

public:
    Electronics(string n, double p, int w) : Product(n, p), warranty(w) {}

    void getInfo() override
    {
        Product::getInfo();
        cout << "Warranty: " << warranty << " months" << endl;
    }

    void purchase() override
    {
        cout << "Purchased Electronics: " << name << " with " << warranty << " months warranty for $" << price << endl;
    }
};

// Derived Class: Clothing
class Clothing : public Product
{
private:
    string size;

public:
    Clothing(string n, double p, string s) : Product(n, p), size(s) {}

    void getInfo() override
    {
        Product::getInfo();
        cout << "Size: " << size << endl;
    }

    void purchase() override
    {
        cout << "Purchased Clothing: " << name << " (Size: " << size << ") for $" << price << endl;
    }
};

// Customer Class
class Customer
{
protected:
    string name;
    string contactNumber;

public:
    Customer(string n, string c) : name(n), contactNumber(c) {}

    virtual void buyProduct(Product &p)
    {
        cout << name << " is buying a product..." << endl;
        p.purchase();
    }
};

// VIP Customer (inherits from Customer)
class VIPCustomer : public Customer
{
public:
    VIPCustomer(string n, string c) : Customer(n, c) {}

    void buyProduct(Product &p) override
    {
        double discountedPrice = p.getPrice() * 0.9; // 10% discount
        cout << name << " (VIP) is buying a product with discount..." << endl;
        cout << "Final Price after 10% discount: $" << discountedPrice << endl;
    }
};

// Stock and Sales Calculation
class Store
{
private:
    vector<Product *> inventory;
    int totalSales;
    double revenue;

public:
    Store() : totalSales(0), revenue(0.0) {}

    void addProduct(Product *p)
    {
        inventory.push_back(p);
    }

    void sellProduct(Customer &c, int index)
    {
        if (index >= 0 && index < inventory.size())
        {
            c.buyProduct(*inventory[index]);
            revenue += inventory[index]->getPrice();
            totalSales++;
        }
        else
        {
            cout << "Invalid product selection!\n";
        }
    }

    void calculateTotalSales()
    {
        cout << "Total Products Sold: " << totalSales << endl;
        cout << "Total Revenue: $" << revenue << endl;
    }
};

// Main Function
int main()
{
    Store retailStore;

    // Adding Products
    Book b1("The Alchemist", 15.99, "Paulo Coelho");
    Electronics e1("Smartphone", 699.99, 24);
    Clothing c1("T-Shirt", 19.99, "M");

    // Adding to store
    retailStore.addProduct(&b1);
    retailStore.addProduct(&e1);
    retailStore.addProduct(&c1);

    // Creating customers
    Customer cust1("Alice", "123-456-7890");
    VIPCustomer vip1("Bob", "987-654-3210");

    // Simulating Purchases
    retailStore.sellProduct(cust1, 0); // Alice buys The Alchemist
    retailStore.sellProduct(vip1, 1);  // Bob (VIP) buys Smartphone

    // Display Sales Summary
    retailStore.calculateTotalSales();

    return 0;
}
