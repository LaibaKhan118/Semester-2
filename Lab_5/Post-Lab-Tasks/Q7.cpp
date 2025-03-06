/*Q: Implement a restaurant ordering system that holds information about the restaurant's menus, menu items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and
remove items, or display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. The order class
consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay. This is
generated when the order is placed.*/

#include <iostream>
#include <string>
using namespace std;

class MenuItem
{
private:
    string name;
    float price;

public:
    MenuItem() : name(""), price(0.0) {}
    MenuItem(string n, float p) : name(n), price(p) {}

    string getName() const { return name; }
    float getPrice() const { return price; }
};

class Menu
{
private:
    MenuItem *items;
    int num;

public:
    Menu() : items(nullptr), num(0) {}
    Menu(MenuItem *ptr, int n) : num(n)
    {
        items = new MenuItem[num];
        for (int i = 0; i < num; i++)
        {
            items[i] = ptr[i];
        }
    }

    ~Menu()
    {
        delete[] items;
    }

    void display() const
    {
        cout << "\n====== Menu ======" << endl;
        for (int i = 0; i < num; i++)
        {
            cout << i << ". " << items[i].getName() << " : Rs " << items[i].getPrice() << " /-" << endl;
        }
    }

    MenuItem getItem(int i) const
    {
        if (i < 0 || i >= num)
        {
            cout << "Invalid index! Selecting empty item.\n";
            return MenuItem("", 0.0);
        }
        return items[i];
    }
};

class Payment
{
private:
    float payment;

public:
    Payment() : payment(0.0) {}
    Payment(float p) : payment(p) {}
    void setPayment(float p) { payment = p; }
    float getPayment() const { return payment; }
    void processPayment() const
    {
        cout << "Payment of Rs " << payment << " processed successfully!" << endl;
    }
};

class Order
{
private:
    MenuItem *orderedItems;
    int num;
    Payment payment;

public:
    Order() : orderedItems(nullptr), num(0), payment(0.0) {}
    Order(MenuItem *ptr, int n) : num(n), payment(0.0)
    {
        orderedItems = new MenuItem[num];
        for (int i = 0; i < num; i++)
        {
            orderedItems[i] = ptr[i];
        }
        calculatePayment();
    }

    ~Order()
    {
        delete[] orderedItems;
    }

    void calculatePayment()
    {
        float total = 0.0;
        for (int i = 0; i < num; i++)
        {
            total += orderedItems[i].getPrice();
        }
        payment.setPayment(total);
    }

    void placeOrder()
    {
        if (num == 0)
        {
            cout << "Order cannot be placed. No valid items selected.\n";
            return;
        }
        calculatePayment();
        cout << "Order Placed of Rs " << payment.getPayment() << " /-" << endl;
        payment.processPayment();
    }

    void display() const
    {
        cout << "====== Order Details ======" << endl;
        for (int i = 0; i < num; i++)
        {
            cout << i + 1 << ". " << orderedItems[i].getName() << " : Rs " << orderedItems[i].getPrice() << " /-" << endl;
        }
    }
};

class Restaurant
{
private:
    Menu menu;

public:
    Restaurant(Menu m) : menu(m) {}

    void showMenu() const
    {
        menu.display();
    }

    Order takeOrder(int *index, int n)
    {
        MenuItem *items = new MenuItem[n];
        for (int i = 0; i < n; i++)
        {
            items[i] = menu.getItem(index[i]);
        }
        Order newOrder(items, n);
        delete[] items;
        return newOrder;
    }
};

int main()
{
    MenuItem items[] = {
        MenuItem("Burger", 250),
        MenuItem("Pizza", 500),
        MenuItem("Fries", 150)};

    Menu menu(items, 3);
    Restaurant restaurant(menu);

    restaurant.showMenu();

    int choices[] = {1, 2};
    Order myOrder = restaurant.takeOrder(choices, 2);
    myOrder.display();
    myOrder.placeOrder();

    return 0;
}
