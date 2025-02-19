#include <iostream>
#include <string>
using namespace std;

// Base class Juice
class Juice {
protected:
    int price;
    string ingredients;
    string taste;
    static int juiceCount;

public:
    Juice(int p, string ing, string t) : price(p), ingredients(ing), taste(t) {
        juiceCount++;
    }

    virtual void print() {
        cout << "Juice Details:\n";
        cout << "Price: " << price << " PKR\n";
        cout << "Ingredients: " << ingredients << "\n";
        cout << "Taste: " << taste << "\n";
    }

    int getPrice() { return price; }
    static int getJuiceCount() { return juiceCount; }
    virtual ~Juice() {}
};
int Juice::juiceCount = 0;

// Derived class FruitJuice
class FruitJuice : public Juice {
protected:
    string season;

public:
    FruitJuice(int p, string ing, string t, string s) : Juice(p, ing, t), season(s) {}

    void print() override {
        Juice::print();
        cout << "Season: " << season << "\n";
        cout << "22K-1234 Fahim also likes fruit juice.\n";
    }
};

// Subclasses of FruitJuice
class CitrusJuice : public FruitJuice {
public:
    CitrusJuice() : FruitJuice(399, "Oranges, Lemons, Grapefruits", "Sweet & Tangy", "Winter") {}
};

class BerryJuice : public FruitJuice {
public:
    BerryJuice() : FruitJuice(450, "Strawberries, Blueberries, Raspberries", "Sweet & Tart", "Summer") {}
};

class TropicalJuice : public FruitJuice {
public:
    TropicalJuice() : FruitJuice(500, "Mangoes, Pineapples, Bananas", "Sweet", "All year") {}
};

// Derived class VegetableJuice
class VegetableJuice : public Juice {
protected:
    string origin;

public:
    VegetableJuice(int p, string ing, string t, string o) : Juice(p, ing, t), origin(o) {}

    void print() override {
        Juice::print();
        cout << "Origin: " << origin << "\n";
        cout << "22K-1234 Fahim also likes vegetable juice.\n";
    }
};

// Subclasses of VegetableJuice
class LeafyGreenJuice : public VegetableJuice {
public:
    LeafyGreenJuice() : VegetableJuice(499, "Kale, Spinach, Celery", "Bitter & Earthy", "Organic Farm") {}
};

class RootVegetableJuice : public VegetableJuice {
public:
    RootVegetableJuice() : VegetableJuice(520, "Carrots, Beets, Ginger", "Sweet & Spicy", "Local Farm") {}
};

class MixedVegetableJuice : public VegetableJuice {
public:
    MixedVegetableJuice() : VegetableJuice(550, "Cabbage, Cucumber, Carrot", "Fresh", "Hybrid") {}
};

// Derived class MixedJuice
class MixedJuice : public Juice {
public:
    MixedJuice(int p, string ing, string t) : Juice(p, ing, t) {}

    void print() override {
        Juice::print();
        cout << "22K-1234 Fahim also likes mixed juice.\n";
    }
};

// Subclasses of MixedJuice
class FruitAndVeggieJuice : public MixedJuice {
public:
    FruitAndVeggieJuice() : MixedJuice(600, "Apples, Spinach, Ginger", "Sweet & Spicy") {}
};

class SmoothieJuice : public MixedJuice {
public:
    SmoothieJuice() : MixedJuice(650, "Banana, Almond Milk, Chia Seeds", "Creamy & Sweet") {}
};

// Sales class
class Sales {
private:
    int saleID;
    string customerName;
    int totalBill;
    int numFruitJuice, numVegJuice, numMixedJuice;

public:
    Sales(int id, string name) : saleID(id), customerName(name), totalBill(0), numFruitJuice(0), numVegJuice(0), numMixedJuice(0) {}

    void addSale(int bill, int f, int v, int m) {
        totalBill += bill;
        numFruitJuice += f;
        numVegJuice += v;
        numMixedJuice += m;
    }

    void print() {
        cout << "\nSale ID: " << saleID << "\nCustomer: " << customerName << "\nTotal Bill: " << totalBill << " PKR\n";
        cout << "Fruit Juices: " << numFruitJuice << ", Vegetable Juices: " << numVegJuice << ", Mixed Juices: " << numMixedJuice << "\n";
    }

    Sales operator+(const Sales &other) {
        if (this->customerName != other.customerName) {
            cout << "Error: Sales must belong to the same customer.\n";
            return *this;
        }
        Sales newSale(saleID, customerName);
        newSale.totalBill = totalBill + other.totalBill;
        newSale.numFruitJuice = numFruitJuice + other.numFruitJuice;
        newSale.numVegJuice = numVegJuice + other.numVegJuice;
        newSale.numMixedJuice = numMixedJuice + other.numMixedJuice;
        return newSale;
    }
};

// Main function
int main() {
    string customerName;
    cout << "Welcome to the Juice Shop! Enter your name: ";
    cin >> customerName;

    Sales sale(1, customerName);

    int choice, subChoice;
    bool shopping = true;

    while (shopping) {
        cout << "\n1. Fruit Juice\n2. Vegetable Juice\n3. Mixed Juice\n4. Checkout\nChoose a category: ";
        cin >> choice;

        if (choice == 4) {
            shopping = false;
            break;
        }

        switch (choice) {
            case 1:
                cout << "\n1. Citrus Juice\n2. Berry Juice\n3. Tropical Juice\nChoose a type: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    CitrusJuice cj;
                    sale.addSale(cj.getPrice(), 1, 0, 0);
                    cout << "Citrus Juice added to cart.\n";
                } else if (subChoice == 2) {
                    BerryJuice bj;
                    sale.addSale(bj.getPrice(), 1, 0, 0);
                    cout << "Berry Juice added to cart.\n";
                } else if (subChoice == 3) {
                    TropicalJuice tj;
                    sale.addSale(tj.getPrice(), 1, 0, 0);
                    cout << "Tropical Juice added to cart.\n";
                }
                break;

            case 2:
                cout << "\n1. Leafy Green Juice\n2. Root Vegetable Juice\n3. Mixed Vegetable Juice\nChoose a type: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    LeafyGreenJuice lgj;
                    sale.addSale(lgj.getPrice(), 0, 1, 0);
                    cout << "Leafy Green Juice added to cart.\n";
                } else if (subChoice == 2) {
                    RootVegetableJuice rvj;
                    sale.addSale(rvj.getPrice(), 0, 1, 0);
                    cout << "Root Vegetable Juice added to cart.\n";
                } else if (subChoice == 3) {
                    MixedVegetableJuice mvj;
                    sale.addSale(mvj.getPrice(), 0, 1, 0);
                    cout << "Mixed Vegetable Juice added to cart.\n";
                }
                break;

            case 3:
                cout << "\n1. Fruit and Veggie Juice\n2. Smoothie Juice\nChoose a type: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    FruitAndVeggieJuice fvj;
                    sale.addSale(fvj.getPrice(), 0, 0, 1);
                    cout << "Fruit and Veggie Juice added to cart.\n";
                } else if (subChoice == 2) {
                    SmoothieJuice sj;
                    sale.addSale(sj.getPrice(), 0, 0, 1);
                    cout << "Smoothie Juice added to cart.\n";
                }
                break;
        }
    }

    sale.print();
    return 0;
}
