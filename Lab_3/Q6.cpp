// [24K-0644]
/*Q6: Create a class called Smartphone with the following attributes: Company, Model, Display Resolution, RAM, ROM, and Storage

Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example: Make a phone call, Send a message, Connect to the wifi, and Browse the internet

Create different smartphone objects. Set their attributes using the setter functions and display their attributes after
using the getter functions to fetch the attributes.*/

#include <iostream>
using namespace std;

class Smartphone
{
private:
    string company;
    string model;
    string resolution;
    int RAM;     // in MBs
    int ROM;     // in MBs
    int storage; // in GBs
public:
    // setters
    void setCompany(const string &company)
    {
        this->company = company;
    }

    void setModel(const string &model)
    {
        this->model = model;
    }

    void setResolution(const string &resolution)
    {
        this->resolution = resolution;
    }

    void setRAM(int RAM)
    {
        this->RAM = RAM;
    }

    void setROM(int ROM)
    {
        this->ROM = ROM;
    }

    void setStorage(int storage)
    {
        this->storage = storage;
    }

    // getters
    string getCompany() const
    {
        return company;
    }

    string getModel() const
    {
        return model;
    }

    string getResolution() const
    {
        return resolution;
    }

    int getRAM() const
    {
        return RAM;
    }

    int getROM() const
    {
        return ROM;
    }

    int getStorage() const
    {
        return storage;
    }

    // Methods
    void makePhoneCall() const
    {
        cout << "Making a phone call..." << endl;
    }

    void sendMessage() const
    {
        cout << "Sending a message..." << endl;
    }

    void connectToWifi() const
    {
        cout << "Connecting to Wi-Fi..." << endl;
    }

    void browseInternet() const
    {
        cout << "Browsing the internet..." << endl;
    }
};

int main()
{
    Smartphone smartphone1, smartphone2;

    smartphone1.setCompany("Apple");
    smartphone1.setModel("iPhone 14");
    smartphone1.setResolution("2532 x 1170");
    smartphone1.setRAM(4096);    // 4GB
    smartphone1.setROM(128);     // 128GB
    smartphone1.setStorage(128); // in GBs

    smartphone2.setCompany("Samsung");
    smartphone2.setModel("Galaxy S23");
    smartphone2.setResolution("2340 x 1080");
    smartphone2.setRAM(8192);    // 8GB
    smartphone2.setROM(256);     // 256GB
    smartphone2.setStorage(256); // in GBs

    cout << "Smartphone 1 - " << smartphone1.getCompany() << " " << smartphone1.getModel() << endl;
    cout << "Resolution: " << smartphone1.getResolution() << endl;
    cout << "RAM: " << smartphone1.getRAM() << " MB" << endl;
    cout << "ROM: " << smartphone1.getROM() << " MB" << endl;
    cout << "Storage: " << smartphone1.getStorage() << " GB" << endl;

    cout << endl;

    cout << "Smartphone 2 - " << smartphone2.getCompany() << " " << smartphone2.getModel() << endl;
    cout << "Resolution: " << smartphone2.getResolution() << endl;
    cout << "RAM: " << smartphone2.getRAM() << " MB" << endl;
    cout << "ROM: " << smartphone2.getROM() << " MB" << endl;
    cout << "Storage: " << smartphone2.getStorage() << " GB" << endl;

    cout << endl;
    smartphone1.makePhoneCall();
    smartphone2.connectToWifi();

    return 0;
}
