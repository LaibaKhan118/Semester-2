#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    string name;
    float price;
    int quantity;
} ProductInfo;

int getID(ProductInfo *Products, int n);
void displayProduct(int id, ProductInfo *Products, int n);
ProductInfo *addProduct(ProductInfo *Products, int &n);
void updateProduct(int id, ProductInfo *Products, int n);
ProductInfo *removeProduct(int id, ProductInfo *Products, int &n);

int main()
{
    int n = 5, op, id; // Initially there are 5 products
    ProductInfo *Products = new ProductInfo[n];
    Products[0] = {"Laptop", 2000, 10};
    Products[1] = {"Mobile", 5000, 15};
    Products[2] = {"Headset", 400, 6};
    Products[3] = {"Wireless Keyboard", 800, 12};
    Products[4] = {"Wireless Mouse", 200, 20};

    while (true)
    {
        cout << "\n\nMenu" << endl;
        cout << "1. Display a product's Details\n2. Add a new product\n3. update a product\n4. Remove a product\n5. Exit\n Choose an option: ";
        cin >> op;
        cin.ignore();
        switch (op)
        {
        case 1:
            id = getID(Products, n);
            displayProduct(id, Products, n);
            break;
        case 2:
            Products = addProduct(Products, n);
            break;
        case 3:
            id = getID(Products, n);
            cin.ignore();
            updateProduct(id, Products, n);
            break;
        case 4:
            id = getID(Products, n);
            cin.ignore();
            Products = removeProduct(id, Products, n);
            break;
        case 5:
            cout << "Exiting the program." << endl;
            return 0;
            break;
        default:
            cout << "Wrong Option Number\n";
        }
    }
    delete[] Products;
    return 0;
}

int getID(ProductInfo *Products, int n)
{
    int id;
    for (int i = 0; i < n; i++)
    {
        cout << i << ". " << Products[i].name << endl;
    }
    cout << "Select the ID of the product: ";
    cin >> id;
    return id;
}

void displayProduct(int id, ProductInfo *Products, int n)
{
    if (id < 0 || id >= n)
    {
        cout << "Wrong ID\n";
        return;
    }
    cout << "\nProduct Details:\n  ID: " << id << "\n  Name: " << Products[id].name << "\n  Price: " << Products[id].price << "\n  Quantity Available: " << Products[id].quantity << endl;
}

ProductInfo *addProduct(ProductInfo *Products, int &n)
{
    ProductInfo *NewProducts = new ProductInfo[n + 1];
    for (int i = 0; i < n; i++)
    {
        NewProducts[i] = Products[i];
    }

    cout << "Enter Product Name: ";
    getline(cin, NewProducts[n].name);
    cout << "Enter Product Price: ";
    cin >> NewProducts[n].price;
    cout << "Enter Product Quantity: ";
    cin >> NewProducts[n].quantity;
    cin.ignore();

    delete[] Products;
    n++;
    cout << "New product added successfully.";
    return NewProducts;
}

void updateProduct(int id, ProductInfo *Products, int n)
{
    if (id < 0 || id >= n)
    {
        cout << "Wrong ID Number." << endl;
        return;
    }
    int update;
    while (true)
    {
        cout << "\n1. Name\n2. Price\n3. Quantity\nSelect the information you want to update (4 to Exit): ";
        cin >> update;
        cin.ignore();
        switch (update)
        {
        case 1:
            cout << "Enter the new name: ";
            getline(cin, Products[id].name);
            break;
        case 2:
            cout << "Enter the new price: ";
            cin >> Products[id].price;
            break;
        case 3:
            cout << "Enter the new quantity: ";
            cin >> Products[id].quantity;
            break;
        case 4:
            return;
            break;
        default:
            cout << "Wrong option number\n";
        }
    }
}

ProductInfo *removeProduct(int id, ProductInfo *Products, int &n)
{
    if (id < 0 || id >= n)
    {
        cout << "Wrong ID Number." << endl;
        return Products;
    }

    ProductInfo *newProducts = new ProductInfo[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != id)
        {
            newProducts[j++] = Products[i];
        }
    }

    delete[] Products;
    n--;
    cout << "Products Removed Successfully." << endl;
    return newProducts;
}