/*Device management*/
#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    string id;
    string type;
    double powerRating;
    bool status;

public:
    Device(string i, string t, double p) : id(i), type(t), powerRating(p), status(false) {}
    virtual void turnOn()
    {
        status = true;
        cout << "Turning ON the " << type << endl;
    }
    virtual void turnOff()
    {
        status = false;
        cout << "Turning OFF the " << type << endl;
    }
    virtual double calculatePowerUsage(int hours)
    {
        return powerRating * hours;
    }
    string getDeviceType() { return type; }
};

class Light : public Device
{
public:
    Light(string i, string t, double p) : Device(i, t, p) {}
};

class AC : public Device
{
    float desiredTemp;

public:
    AC(string i, string t, double p, float dT) : desiredTemp(dT), Device(i, t, p) {}
    double calculatePowerUsage(int hours) override
    {
        return powerRating * hours * (1 - (25 - desiredTemp) / 100); // Assuming current temp is 25
    }
    void turnOn() override
    {
        status = true;
        cout << "Turning on the " << type << ". Cooling to " << desiredTemp << " deg C." << endl;
        char op;
        while (1)
        {
            cout << "Would you like to change the temperature? (Y/N): ";
            cin >> op;
            if (op == 'Y' || op == 'y')
            {
                cout << "Enter the desired temperature: ";
                cin >> desiredTemp;
                cout << "Setting temperature to " << desiredTemp << " deg C." << endl;
                break;
            }
            else
            {
                break;
            }
        }
    }
};

class Fan : public Device
{
    float speedFactor;

public:
    Fan(string i, string t, double p, float s) : speedFactor(s), Device(i, t, p) {}
    double calculatePowerUsage(int hours) override
    {
        return powerRating * hours * speedFactor;
    }
    void turnOn() override
    {
        status = true;
        cout << "Turning ON the " << type << " at Speed " << speedFactor << "." << endl;
    }
};
class SecuritySystem;

class User
{
protected:
    string id;
    string role;
    int accessLevel; // 1 for edit, 0 for view-only

public:
    User(string i, string r, int level) : id(i), role(r), accessLevel(level) {}
    virtual void viewAccessibleDevices()
    {
        cout << "Accessible Devices:" << endl;
        if (accessLevel == 0)
        {
            cout << "Regular Staff have access to:" << endl;
            cout << "- Fan\n- AC\n- Light\n";
        }
        else if (accessLevel == 1)
        {
            cout << "Maintenance Staff have access to:" << endl;
            cout << "- Security System\n- Fan\n- AC\n- Light\n";
        }
        else
        {
            cout << "No accessible devices.\n";
        }
    }
    friend void accessSecurityLogs(const SecuritySystem &, const User &);
    int getAccessLevel() const { return accessLevel; }
};

class SecuritySystem : public Device
{
private:
    string password;
    bool intrusionDetected;
    // here the power rating that the constructor takes is the fixed power
public:
    SecuritySystem(string i, string t, double p, string pass) : password(pass), intrusionDetected(false), Device(i, t, p)
    {
    }
    double calculatePowerUsage(int hours) override
    {
        // I don't understand the fixed power consumption thing for this function, I assumed that the "log Security status means that I should print a statement before returning the power that the system has consumed so far."
        if (status)
        {
            cout << type << " is ON. Logging power usage." << endl;
            return powerRating * hours;
        }
        else
        {
            cout << type << " is OFF. No power consumed." << endl;
            return 0;
        }
    }
    void turnOff() override
    {
        string passcode;
        cout << "Enter Password: ";
        cin >> passcode;
        if (passcode == password)
        {
            status = false;
            cout << "Turning OFF the " << type << endl;
        }
        else
        {
            cout << "Enter correct passcode to turn OFF the " << type << endl;
        }
    }
    void triggerIntrusion()
    {
        intrusionDetected = true;
    }

    friend void accessSecurityLogs(const SecuritySystem &, const User &);

    friend class MaintenanceTool;
};

void accessSecurityLogs(const SecuritySystem &sys, const User &u)
{
    if (u.role == "Maintenance Staff")
    {
        cout << "Security Logs Accessed:\n";
        cout << "- Intrusion Detected at 3:00 AM\n";
        cout << "- System Reset Required\n";
    }
    else
    {
        cout << "Access denied. Only Maintenance Staff can access security logs." << endl;
    }
}

class MaintenanceTool
{
public:
    void resetSecurity(SecuritySystem &secSys, const User &u)
    {
        if (u.getAccessLevel() == 1)
        {
            secSys.intrusionDetected = false;
            cout << secSys.type << " Reset Completed.\n";
        }
        else
        {
            cout << "Access Denied! Only maintenance personnel can reset the security alerts of " << secSys.type << endl;
        }
    }
};

int main()
{
    // User Setup
    User user1("U001", "Regular User", 0);
    User user2("U002", "Maintenance Staff", 1);
    // Devices Setup
    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AC ac1("AC001", "Split AC", 1500, 20);
    SecuritySystem secSys1("S001", "Home Alarm", 100, "Home#123");
    // Device Operations
    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();
    // Power Consumption Calculation
    cout << "Power Consumptions: " << endl;
    cout << light1.getDeviceType() << ": " << light1.calculatePowerUsage(5) << endl;    // 50 Watts
    cout << fan1.getDeviceType() << ": " << fan1.calculatePowerUsage(3) << endl;        // Based on speed factor
    cout << ac1.getDeviceType() << ": " << ac1.calculatePowerUsage(6) << endl;          // Adjusted for temp
    cout << secSys1.getDeviceType() << ": " << secSys1.calculatePowerUsage(24) << endl; // Fixed consumption
    // Attempting to access security logs
    user1.viewAccessibleDevices();
    // Can see lights, fans, ACs, but NOT security systems
    accessSecurityLogs(secSys1, user2);
    // Allowed to view security logs return 0;
    MaintenanceTool mt1;
    mt1.resetSecurity(secSys1, user2);
}
