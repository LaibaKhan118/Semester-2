#include <iostream>
#include <string>
using namespace std;

enum DiscountType
{
    PERCENTAGE,
    FIXED,
    BOGO
};
enum UserType
{
    REGULAR,
    PREMIUM
};

class Product
{
protected:
    string productID;
    double price;
    string category;

public:
    Product(const string &id, double p, const string &cat)
        : productID(id), price(p), category(cat) {}

    virtual ~Product() {}

    virtual double calculatePrice() const
    {
        return price;
    }

    string getProductID() const { return productID; }
    double getPrice() const { return price; }
    string getCategory() const { return category; }
    void setPrice(double p) { price = p; }
};

class Electronics : public Product
{
public:
    Electronics(const string &id, double p)
        : Product(id, p, "Electronics") {}

    double calculatePrice() const override
    {
        return price * 1.15; // 15% tax
    }
};

class Clothing : public Product
{
public:
    Clothing(const string &id, double p)
        : Product(id, p, "Clothing") {}

    double calculatePrice() const override
    {
        return price * 1.05; // 5% tax
    }
};

class ShoppingCart
{
private:
    Product **items;
    int capacity;
    int count;
    UserType userType;

    void resize()
    {
        capacity *= 2;
        Product **newItems = new Product *[capacity];
        for (int i = 0; i < count; i++)
        {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }

public:
    ShoppingCart(UserType ut = REGULAR)
        : capacity(10), count(0), userType(ut)
    {
        items = new Product *[capacity];
    }

    ~ShoppingCart()
    {
        clear();
        delete[] items;
    }

    void clear()
    {
        for (int i = 0; i < count; i++)
        {
            delete items[i];
        }
        count = 0;
    }

    void addProduct(Product *product)
    {
        if (count == capacity)
            resize();
        items[count++] = product;
    }

    bool removeProduct(const string &productID)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getProductID() == productID)
            {
                delete items[i];
                for (int j = i; j < count - 1; j++)
                {
                    items[j] = items[j + 1];
                }
                count--;
                return true;
            }
        }
        return false;
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

    // Discount methods
    void applyDiscount(DiscountType type, double value)
    {
        if (type == PERCENTAGE)
        {
            for (int i = 0; i < count; i++)
            {
                items[i]->setPrice(items[i]->getPrice() * (1 - value / 100.0));
            }
        }
        else if (type == FIXED)
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

    void applyDiscount(DiscountType type)
    {
        if (type == BOGO && count >= 2)
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

    // Operator overloading
    ShoppingCart operator+(const ShoppingCart &other) const
    {
        ShoppingCart result(userType);
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getCategory() == "Electronics")
            {
                result.addProduct(new Electronics(items[i]->getProductID(),
                                                  items[i]->getPrice()));
            }
            else
            {
                result.addProduct(new Clothing(items[i]->getProductID(),
                                               items[i]->getPrice()));
            }
        }
        for (int i = 0; i < other.count; i++)
        {
            if (other.items[i]->getCategory() == "Electronics")
            {
                result.addProduct(new Electronics(other.items[i]->getProductID(),
                                                  other.items[i]->getPrice()));
            }
            else
            {
                result.addProduct(new Clothing(other.items[i]->getProductID(),
                                               other.items[i]->getPrice()));
            }
        }
        return result;
    }

    ShoppingCart operator-(const string &productID) const
    {
        ShoppingCart result(userType);
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getProductID() != productID)
            {
                if (items[i]->getCategory() == "Electronics")
                {
                    result.addProduct(new Electronics(items[i]->getProductID(),
                                                      items[i]->getPrice()));
                }
                else
                {
                    result.addProduct(new Clothing(items[i]->getProductID(),
                                                   items[i]->getPrice()));
                }
            }
        }
        return result;
    }

    ShoppingCart operator*(double discount) const
    {
        ShoppingCart result(userType);
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getCategory() == "Electronics")
            {
                result.addProduct(new Electronics(items[i]->getProductID(),
                                                  items[i]->getPrice() * (1 - discount / 100.0)));
            }
            else
            {
                result.addProduct(new Clothing(items[i]->getProductID(),
                                               items[i]->getPrice() * (1 - discount / 100.0)));
            }
        }
        return result;
    }

    pair<double, double> operator/(int users) const
    {
        double total = calculateTotal();
        return {total, total / users};
    }

    void displayCart() const
    {
        cout << "Shopping Cart (" << (userType == PREMIUM ? "Premium" : "Regular")
             << " user, " << count << " items):\n";
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
    // Create products - shopping carts will take ownership
    Electronics *laptop = new Electronics("E1001", 999.99);
    Electronics *phone = new Electronics("E1002", 699.99);
    Clothing *shirt = new Clothing("C2001", 29.99);
    Clothing *pants = new Clothing("C2002", 49.99);

    // Create and populate carts
    ShoppingCart premiumCart(PREMIUM);
    premiumCart.addProduct(laptop);
    premiumCart.addProduct(shirt);

    ShoppingCart regularCart(REGULAR);
    regularCart.addProduct(phone);
    regularCart.addProduct(pants);

    cout << "Initial Carts:\n";
    premiumCart.displayCart();
    regularCart.displayCart();

    // Apply discounts
    premiumCart.applyDiscount(PERCENTAGE, 10); // 10% off
    regularCart.applyDiscount(FIXED, 20);      // $20 off

    cout << "After Discounts:\n";
    premiumCart.displayCart();
    regularCart.displayCart();

    // Combine carts
    ShoppingCart megaCart = premiumCart + regularCart;
    cout << "Combined Mega Cart:\n";
    megaCart.displayCart();

    // BOGO discount
    megaCart.applyDiscount(BOGO);
    cout << "After BOGO Discount:\n";
    megaCart.displayCart();

    // Remove an item
    ShoppingCart reducedCart = megaCart - "E1001";
    cout << "After Removing E1001:\n";
    reducedCart.displayCart();

    // Bulk discount
    ShoppingCart bulkCart = premiumCart * 15; // 15% off
    cout << "Premium Cart with 15% bulk discount:\n";
    bulkCart.displayCart();

    // Split cart
    auto split = megaCart / 3;
    cout << "Splitting mega cart among 3 people:\n";
    cout << "Total: $" << split.first << "\n";
    cout << "Each pays: $" << split.second << "\n";

    return 0;
}
