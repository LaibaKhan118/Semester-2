#include <iostream>
using namespace std;

// Forward declaration
class Airplane;
class Crew;

class Flight {
private:
    string flightNumber;
    string destination;
    string departureDateTime;
    Airplane* assignedAirplane; // Pointer to assigned airplane
    Crew* crewMembers[5];       // Array for up to 5 crew members
    int crewCount;              // Track number of crew members assigned

public:
    Flight(string number, string dest, string dateTime)
        : flightNumber(number), destination(dest), departureDateTime(dateTime), assignedAirplane(nullptr), crewCount(0) {}

    void assignAirplane(Airplane* airplane);
    void assignCrew(Crew* crew);
    void displayFlightDetails() const;

    string getFlightNumber() const { return flightNumber; }
    string getDestination() const { return destination; }
    string getDepartureTime() const { return departureDateTime; }
};

class Airplane {
private:
    string id;
    string airline;
    string model;
    int number;
    Flight* assignedFlights[10]; // Fixed array for up to 10 flights
    int flightCount;

public:
    Airplane(string i, string a, string m, int n) : id(i), airline(a), model(m), number(n), flightCount(0) {}

    void addFlight(Flight* flight) {
        if (flightCount < 10) {
            assignedFlights[flightCount++] = flight;
        } else {
            cout << "Cannot assign more flights to airplane " << id << endl;
        }
    }

    void displayAirplaneDetails() const {
        cout << "\nAirplane ID: " << id << "\nAirline: " << airline << "\nModel: " << model
             << "\nNumber: " << number << "\nTotal Flights: " << flightCount << endl;
    }

    string getID() const { return id; }
    string getAirline() const { return airline; }
};

class Crew {
private:
    string name;
    string role;
    Flight* assignedFlights[5]; // Fixed array for up to 5 flights
    int flightCount;

public:
    Crew(string n, string r) : name(n), role(r), flightCount(0) {}

    void assignFlight(Flight* flight) {
        if (flightCount < 5) {
            assignedFlights[flightCount++] = flight;
        } else {
            cout << "Crew member " << name << " cannot be assigned more flights.\n";
        }
    }

    void displayCrewDetails() const {
        cout << "\nCrew Name: " << name << "\nRole: " << role
             << "\nTotal Assigned Flights: " << flightCount << endl;
    }

    string getName() const { return name; }
};

// Function Definitions
void Flight::assignAirplane(Airplane* airplane) {
    assignedAirplane = airplane;
    airplane->addFlight(this);
}

void Flight::assignCrew(Crew* crew) {
    if (crewCount < 5) {
        crewMembers[crewCount++] = crew;
        crew->assignFlight(this);
    } else {
        cout << "Cannot assign more crew members to flight " << flightNumber << endl;
    }
}

void Flight::displayFlightDetails() const {
    cout << "\nFlight Number: " << flightNumber << "\nDestination: " << destination
         << "\nDeparture Time: " << departureDateTime;
    if (assignedAirplane) {
        cout << "\nAssigned Airplane: " << assignedAirplane->getID() << " (" << assignedAirplane->getAirline() << ")";
    } else {
        cout << "\nNo airplane assigned.";
    }
    cout << "\nTotal Crew Members: " << crewCount << endl;
}

// Main function
int main() {
    // Create airplanes
    Airplane airplane1("A320X1", "Emirates", "Airbus A320", 101);
    Airplane airplane2("B737Y2", "Qatar Airways", "Boeing 737", 202);

    // Create flights
    Flight flight1("EK501", "Dubai", "2025-03-10 10:30 AM");
    Flight flight2("QR302", "Doha", "2025-03-11 5:00 PM");

    // Assign flights to airplanes
    flight1.assignAirplane(&airplane1);
    flight2.assignAirplane(&airplane2);

    // Create crew members
    Crew crew1("John Doe", "Pilot");
    Crew crew2("Sarah Connor", "Co-Pilot");

    // Assign crew to flights
    flight1.assignCrew(&crew1);
    flight1.assignCrew(&crew2);
    flight2.assignCrew(&crew2); // Sarah Connor also works on flight2

    // Display details
    flight1.displayFlightDetails();
    flight2.displayFlightDetails();
    airplane1.displayAirplaneDetails();
    airplane2.displayAirplaneDetails();
    crew1.displayCrewDetails();
    crew2.displayCrewDetails();

    return 0;
}
