//[24K-0644]
/*Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of
strings), and another list with the prices of the items (hint: array of prices).
Create a menu-driven program to:
1. Allow the shop owner to add the items and their prices.
2. Fetch the list of items
3. Edit the prices of the items
4. View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the
shopkeeper inputs the items and their amounts bought by the customer.*/

#include <iostream>
#include <iomanip>

using namespace std;

class StationeryShop {
private:
    static const int MAX_ITEMS = 50; // Maximum number of items the shop can store
    string items[MAX_ITEMS];         
    double prices[MAX_ITEMS];        
    int itemCount;                   

public:
    StationeryShop() {
        itemCount = 0;
    }

    void addItem() {
        if (itemCount >= MAX_ITEMS) {
            cout << "Cannot add more items! Maximum limit reached.\n";
            return;
        }
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, items[itemCount]);
        cout << "Enter item price: ";
        cin >> prices[itemCount];
        itemCount++;
        cout << "Item added successfully!\n";
    }

    void fetchItems() {
        if (itemCount == 0) {
            cout << "No items available in the shop.\n";
            return;
        }
        cout << "\nAvailable Items:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }

    void editPrice() {
        if (itemCount == 0) {
            cout << "No items available to edit.\n";
            return;
        }
        fetchItems();
        int choice;
        cout << "Enter the item number to edit its price: ";
        cin >> choice;
        if (choice < 1 || choice > itemCount) {
            cout << "Invalid item number!\n";
            return;
        }
        cout << "Enter new price for " << items[choice - 1] << ": ";
        cin >> prices[choice - 1];
        cout << "Price updated successfully!\n";
    }

    void viewItems() {
        if (itemCount == 0) {
            cout << "No items available in the shop.\n";
            return;
        }
        cout << "\nItems in Stationery Shop:\n";
        cout << setw(20) << left << "Item Name" << setw(10) << "Price\n";
        cout << "---------------------------------\n";
        for (int i = 0; i < itemCount; i++) {
            cout << setw(20) << left << items[i] << setw(10) << fixed << setprecision(2) << prices[i] << endl;
        }
    }

    void generateReceipt() {
        if (itemCount == 0) {
            cout << "No items available for purchase.\n";
            return;
        }
        
        int numItems;
        double total = 0.0;
        
        cout << "\nHow many different items did the customer buy? ";
        cin >> numItems;
        
        string boughtItems[numItems];
        int quantities[numItems];
        double itemTotal[numItems];

        for (int i = 0; i < numItems; i++) {
            fetchItems();
            int choice;
            cout << "Enter the item number: ";
            cin >> choice;
            
            if (choice < 1 || choice > itemCount) {
                cout << "Invalid choice! Try again.\n";
                i--;
                continue;
            }

            boughtItems[i] = items[choice - 1];
            cout << "Enter quantity for " << boughtItems[i] << ": ";
            cin >> quantities[i];

            itemTotal[i] = prices[choice - 1] * quantities[i];
            total += itemTotal[i];
        }

        cout << "\n******** RECEIPT ********\n";
        cout << setw(20) << left << "Item Name" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Total\n";
        cout << "------------------------------------------------\n";
        for (int i = 0; i < numItems; i++) {
            cout << setw(20) << left << boughtItems[i] << setw(10) << quantities[i] 
                 << setw(10) << fixed << setprecision(2) << prices[i] << setw(10) << itemTotal[i] << endl;
        }
        cout << "------------------------------------------------\n";
        cout << setw(30) << "Total Amount: " << setw(10) << total << endl;
        cout << "**************************\n";
    }
};

int main() {
    StationeryShop shop;
    int choice;

    do {
        cout << "\n===== Stationery Shop Menu =====\n";
        cout << "1. Add Items\n";
        cout << "2. Fetch Items\n";
        cout << "3. Edit Item Prices\n";
        cout << "4. View All Items & Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.addItem();
                break;
            case 2:
                shop.fetchItems();
                break;
            case 3:
                shop.editPrice();
                break;
            case 4:
                shop.viewItems();
                break;
            case 5:
                shop.generateReceipt();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
