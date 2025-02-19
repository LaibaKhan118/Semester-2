#include <iostream>
#include <string>

using namespace std;

// User Class
class User
{
private:
    int userID[2]; // Stores {first 2 digits, last 4 digits} of roll number
    string name;
    int age;
    float height;
    char gender;
    float shoeSize;

public:
    // Default Constructor
    User()
    {
        userID[0] = 0;
        userID[1] = 0;
        name = "";
        age = 0;
        height = 0.0;
        gender = ' ';
        shoeSize = 0.0;
    }

    // Parameterized Constructor
    User(string userName, int userAge, float userHeight, char userGender, float userShoeSize, int firstID, int lastID)
    {
        name = userName;
        age = userAge;
        height = userHeight;
        gender = userGender;
        shoeSize = userShoeSize;
        userID[0] = firstID;
        userID[1] = lastID;
    }

    // Accessors (Getters)
    string getName() const { return name; }
    int getAge() const { return age; }
    float getHeight() const { return height; }
    char getGender() const { return gender; }
    float getShoeSize() const { return shoeSize; }
    const int *getUserID() const { return userID; }

    // Mutators (Setters)
    void setName(string userName) { name = userName; }
    void setAge(int userAge) { age = userAge; }
    void setHeight(float userHeight) { height = userHeight; }
    void setGender(char userGender) { gender = userGender; }
    void setShoeSize(float userShoeSize) { shoeSize = userShoeSize; }

    // Function to determine demographic category
    string getDemographic() const
    {
        if (age >= 0 && age <= 2)
            return "Infant";
        else if (age >= 3 && age <= 5)
            return "Toddler";
        else if (age >= 10 && age <= 12)
            return "Child";
        else if (age >= 13 && age <= 19)
            return "Teenager";
        else
            return "Adult";
    }
};

// Shoe Class
class Shoe
{
private:
    float size;
    string width;
    string style;
    string brand;
    string color;
    string demographic;

public:
    // Default Constructor
    Shoe()
    {
        size = 0.0;
        width = "";
        style = "";
        brand = "";
        color = "";
        demographic = "";
    }

    // Parameterized Constructor
    Shoe(float shoeSize, string shoeWidth, string shoeStyle, string shoeBrand, string shoeColor, string shoeDemographic)
    {
        size = shoeSize;
        width = shoeWidth;
        style = shoeStyle;
        brand = shoeBrand;
        color = shoeColor;
        demographic = shoeDemographic;
    }

    // Accessors (Getters)
    float getSize() const { return size; }
    string getWidth() const { return width; }
    string getStyle() const { return style; }
    string getBrand() const { return brand; }
    string getColor() const { return color; }
    string getDemographic() const { return demographic; }

    // Mutators (Setters)
    void setSize(float shoeSize) { size = shoeSize; }
    void setWidth(string shoeWidth) { width = shoeWidth; }
    void setStyle(string shoeStyle) { style = shoeStyle; }
    void setBrand(string shoeBrand) { brand = shoeBrand; }
    void setColor(string shoeColor) { color = shoeColor; }
    void setDemographic(string shoeDemographic) { demographic = shoeDemographic; }
};

// Global function to display user and shoe details
void displayInfo(const User &user, const Shoe &shoe)
{
    cout << "\n--- User Information ---\n";
    cout << "Name: " << user.getName() << "\n";
    cout << "Age: " << user.getAge() << "\n";
    cout << "Height: " << user.getHeight() << " cm\n";
    cout << "Gender: " << user.getGender() << "\n";
    cout << "Shoe Size: " << user.getShoeSize() << "\n";
    cout << "User ID: {" << user.getUserID()[0] << ", " << user.getUserID()[1] << "}\n";
    cout << "Demographic: " << user.getDemographic() << "\n";

    cout << "\n--- Shoe Information ---\n";
    cout << "Size: " << shoe.getSize() << "\n";
    cout << "Width: " << shoe.getWidth() << "\n";
    cout << "Style: " << shoe.getStyle() << "\n";
    cout << "Brand: " << shoe.getBrand() << "\n";
    cout << "Color: " << shoe.getColor() << "\n";
    cout << "Demographic: " << shoe.getDemographic() << "\n";
}

int main()
{
    string studentID, name, width, style, brand, color;
    int age, firstID, lastID;
    float height, shoeSize;
    char gender;

    // Ask for student ID
    cout << "Enter your student ID (format: 12K-2034): ";
    cin >> studentID;

    // Extract User ID
    firstID = stoi(studentID.substr(0, 2)); // First 2 digits
    lastID = stoi(studentID.substr(4, 4));  // Last 4 digits

    // User Input
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Height (in cm): ";
    cin >> height;
    cout << "Enter Gender (M/F): ";
    cin >> gender;
    cout << "Enter Shoe Size: ";
    cin >> shoeSize;

    // Create User object
    User user(name, age, height, gender, shoeSize, firstID, lastID);

    // Shoe Input
    cout << "\nEnter Shoe Width (Narrow, Medium, Wide): ";
    cin >> width;
    cout << "Enter Shoe Style (Running, Sneakers, Stiletto, etc.): ";
    cin.ignore();
    getline(cin, style);
    cout << "Enter Shoe Brand: ";
    cin >> brand;
    cout << "Enter Shoe Color: ";
    cin >> color;

    // Create Shoe object
    Shoe shoe(shoeSize, width, style, brand, color, user.getDemographic());

    // Menu-Driven Interface
    int choice;
    do
    {
        cout << "\n1. Update User Info\n2. Update Shoe Info\n3. View Details\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new Age: ";
            cin >> age;
            user.setAge(age);
            shoe.setDemographic(user.getDemographic());
            break;
        case 2:
            cout << "Enter new Shoe Size: ";
            cin >> shoeSize;
            shoe.setSize(shoeSize);
            break;
        case 3:
            displayInfo(user, shoe);
            break;
        }
    } while (choice != 4);

    return 0;
}
