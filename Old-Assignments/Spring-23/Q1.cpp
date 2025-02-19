#include <iostream>
#include <string>

using namespace std;

class Room; // Forward declaration

class Radiator
{
private:
    static int nextID; // Static variable to store the starting ID
    int RadiatorID;
    bool isOn;

public:
    // Static method to set the initial value of nextID
    static void setInitialID(int id)
    {
        nextID = id;
    }

    // Constructor
    Radiator()
    {
        RadiatorID = nextID; // Assign current ID
        nextID += 15;        // Increment for the next radiator
        isOn = false;        // Radiator starts OFF
    }

    // Accessor for RadiatorID
    int getRadiatorID() const
    {
        return RadiatorID;
    }

    // Heats a given room
    void heats(Room &room);
};

// Initialize static member variable (to be set dynamically)
int Radiator::nextID = 0;

class Room
{
private:
    string roomName;
    int seatingCapacity;
    int radiators[2]; // Stores up to 2 radiator IDs
    int numRadiators; // Counter for radiators

public:
    // Constructor
    Room(string name) : roomName(name), seatingCapacity(12), numRadiators(0)
    {
        radiators[0] = 0; // Initialize with 0 (no radiator added)
        radiators[1] = 0;
    }

    // Link a radiator to the room
    string isHeatedBy(Radiator &r)
    {
        int radID = r.getRadiatorID();

        // Check if the radiator is already added
        for (int i = 0; i < numRadiators; i++)
        {
            if (radiators[i] == radID)
            {
                return "Radiator already added to room.";
            }
        }

        // Check if we can add more radiators
        if (numRadiators < 2)
        {
            radiators[numRadiators] = radID; // Store radiator ID
            numRadiators++;                  // Increment counter
            return "Radiator successfully added to room.";
        }
        else
        {
            return "Cannot add Radiator. Room has a maximum number of radiators.";
        }
    }
};

// Define the heats method of Radiator
void Radiator::heats(Room &room)
{
    cout << room.isHeatedBy(*this) << endl;
}

int main()
{
    // Ask the user for their student ID
    string studentID;
    cout << "Enter your student ID (format: 24K-1234): ";
    cin >> studentID;

    // Extract the last three digits (assuming valid format)
    int lastThreeDigits = stoi(studentID.substr(studentID.length() - 3));

    // Set the starting value of RadiatorID using the static method
    Radiator::setInitialID(lastThreeDigits);

    // Create Room and Radiators
    Room room("Living Room");
    Radiator rd1, rd2;

    // Link radiators to the room
    rd1.heats(room);
    rd2.heats(room);

    return 0;
}
