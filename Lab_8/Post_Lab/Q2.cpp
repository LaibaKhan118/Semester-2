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
    string getCategory() const { return category; }
    double getPrice() const { return price; }
    void setPrice(double p) { price = p; }
};

class Electronics : public Product
{
public:
    Electronics(string id, double p) : Product(id, p, "ELECTRONICS") {}
    double calculatePrice() override
    {
        return price *= 1.15;
    }
};

class Clothing : public Product
{
public:
    Clothing(string id, double p) : Product(id, p, "CLOTHING") {}
    double calculatePrice() override
    {
        return price *= 1.05;
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
    ShoppingCart(int type = 0) : capacity(10), count(0)
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
        count = 0;
        delete items;
    }

    void addProduct(Product *product)
    {
        if (capacity == count)
        {
            resize();
        }
        items[count++] = product;
        cout << "Product Add Successfully!" << endl;
    }

    void removeProduct(const string &ID)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getProductID() == ID)
            {
                delete items[i];
                for (int j = i; j < count; j++)
                {
                    items[j] = items[j + 1];
                }
                count--;
                cout << "Product Deleted Successfully!" << endl;
            }
            else
            {
                cout << "Can't find a product with the given ID." << endl;
            }
        }
    }

    double calculateTotal() const
    {
        double total = 0;
        for (int i = 0; i < count; i++)
        {
            total += items[i]->calculatePrice();
        }
        return total;
    }

    void applyDiscount(string type, double value)
    {
        if (type == "PERCENTAGE")
        {
            for (int i = 0; i < count; i++)
            {
                items[i]->setPrice(items[i]->getPrice() * (1 - value / 100.0));
            }
        }
        else if (type == "FIXED")
        {
            for (int i = 0; i < count; i++)
            {
                double newPrice = items[i]->getPrice() - value;
                if (newPrice < 0)
                    newPrice = 0;
                items[i]->setPrice(newPrice);
            }
        }
    }

    void applyDiscount(string type)
    {
        if (type == "BOGO" && count >= 2)
        {
            for (int i = 0; i < count - 1; i += 2)
            {
                if (items[i]->getPrice() > items[i + 1]->getPrice())
                {
                    items[i + 1]->setPrice(0);
                }
                else
                {
                    items[i]->setPrice(0);
                }
            }
        }
    }

    ShoppingCart operator+(const ShoppingCart &other) const
    {
        int type = (userType == "PREMIUM") ? 1 : 0;
        ShoppingCart result(type);
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getCategory() == "ELECTRONICS")
            {
                result.addProduct(new Electronics(items[i]->getProductID(), items[i]->getPrice()));
            }
            else
            {
                result.addProduct(new Clothing(items[i]->getProductID(), items[i]->getPrice()));
            }
        }
        for (int i = 0; i < other.count; i++)
        {
            if (other.items[i]->getCategory() == "ELECTRONICS")
            {
                result.addProduct(new Electronics(other.items[i]->getProductID(), other.items[i]->getPrice()));
            }
            else
            {
                result.addProduct(new Clothing(other.items[i]->getProductID(), other.items[i]->getPrice()));
            }
        }
        return result;
    }

    ShoppingCart operator-(const string &ID) const
    {
        int type = (userType == "PREMIUM") ? 1 : 0;
        ShoppingCart result(type);
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getProductID() != ID)
            {
                if (items[i]->getCategory() == "ELECTRONICS")
                {
                    result.addProduct(new Electronics(items[i]->getProductID(), items[i]->getPrice()));
                }
                else
                {
                    result.addProduct(new Clothing(items[i]->getProductID(), items[i]->getPrice()));
                }
            }
        }
        return result;
    }

    ShoppingCart operator*(double discount) const
    {
        int type = (userType == "PREMIUM") ? 1 : 0;
        ShoppingCart result(type);
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getCategory() == "ELECTRONICS")
            {
                result.addProduct(new Electronics(items[i]->getProductID(), items[i]->getPrice() * (1 - discount / 100.0)));
            }
            else
            {
                result.addProduct(new Clothing(items[i]->getProductID(), items[i]->getPrice() * (1 - discount / 100.0)));
            }
        }
        return result;
    }

    double operator/(int users) const
    {
        if (users <= 0)
        {
            cout << "Number of users must be greater than zero." << endl;
            return 0;
        }
        return calculateTotal() / users;
    }

    void displayCart() const
    {
        cout << "Shopping Cart (" << userType << " user, " << count << " items):\n";
        for (int i = 0; i < count; i++)
        {
            cout << " - " << items[i]->getProductID() << " (" << items[i]->getCategory()
                 << "): $" << items[i]->getPrice() << " -> $"
                 << items[i]->calculatePrice() << " after tax\n";
        }
        cout << "TOTAL: $" << calculateTotal() << "\n\n";
    }
};

int main()
{
    ShoppingCart cart1(0);
    cart1.addProduct(new Electronics("E001", 1000));
    cart1.addProduct(new Clothing("C001", 500));
    cart1.addProduct(new Electronics("E002", 2000));
    cart1.displayCart();

    cart1.applyDiscount("PERCENTAGE", 10);
    cout << "After applying 10% discount:\n";
    cart1.displayCart();

    cart1.applyDiscount("FIXED", 100);
    cout << "After applying fixed discount of $100:\n";
    cart1.displayCart();

    cart1.applyDiscount("BOGO");
    cout << "After applying BOGO discount:\n";
    cart1.displayCart();

    cart1.removeProduct("C001");
    cout << "After removing product C001:\n";
    cart1.displayCart();

    ShoppingCart cart2(1);
    cart2.addProduct(new Electronics("E003", 1500));
    cart2.addProduct(new Clothing("C002", 800));
    cart2.displayCart();

    ShoppingCart combinedCart = cart1 + cart2;
    cout << "Combined cart:\n";
    combinedCart.displayCart();

    ShoppingCart updatedCart = combinedCart - "E002";
    cout << "Updated cart after removing E002:\n";
    updatedCart.displayCart();

    ShoppingCart discountedCart = combinedCart * 20; // 20% discount
    cout << "Discounted cart after applying 20% discount:\n";
    discountedCart.displayCart();

    double splitCost = combinedCart / 3;
    cout << "Split cost among 3 users: $" << splitCost << endl;

    return 0;
}
