#include <iostream>
#include <string>
#include <ctime> // For getting current date

using namespace std;

class HeartRates
{
private:
    string firstName;
    int uniqueID; // Extracted from the third digit of student ID
    int birthDay, birthMonth, birthYear;

public:
    // Constructor
    HeartRates(string fName, int id, int day, int month, int year)
        : firstName(fName), uniqueID(id), birthDay(day), birthMonth(month), birthYear(year) {}

    // Getters and Setters
    void setFirstName(string fName) { firstName = fName; }
    string getFirstName() const { return firstName; }

    void setBirthDate(int day, int month, int year)
    {
        birthDay = day;
        birthMonth = month;
        birthYear = year;
    }

    int getBirthDay() const { return birthDay; }
    int getBirthMonth() const { return birthMonth; }
    int getBirthYear() const { return birthYear; }
    int getUniqueID() const { return uniqueID; }

    // Function to calculate age
    int getAge() const
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int currentMonth = now->tm_mon + 1;
        int currentDay = now->tm_mday;

        int age = currentYear - birthYear;

        // Adjust age if birthday hasn't occurred yet this year
        if (birthMonth > currentMonth || (birthMonth == currentMonth && birthDay > currentDay))
        {
            age--;
        }

        return age;
    }

    // Function to calculate maximum heart rate
    int getMaximumHeartRate() const
    {
        return 220 - getAge();
    }

    // Function to calculate target heart rate range (50-85% of max heart rate)
    void getTargetHeartRate() const
    {
        int maxHeartRate = getMaximumHeartRate();
        double lowerBound = maxHeartRate * 0.50;
        double upperBound = maxHeartRate * 0.85;

        cout << "Target Heart Rate Range: " << lowerBound << " - " << upperBound << " BPM" << endl;
    }
};

// Function to extract unique ID from student ID (3rd digit after hyphen)
int extractUniqueID(string studentID)
{
    return studentID[6] - '0'; // Convert character to integer
}

int main()
{
    string studentID, firstName;
    int day, month, year;

    // Ask for student ID
    cout << "Enter your student ID (format: 24K-1234): ";
    cin >> studentID;

    // Extract unique ID from third digit
    int uniqueID = extractUniqueID(studentID);

    // Ask for user details
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your date of birth (day month year): ";
    cin >> day >> month >> year;

    // Create HeartRates object
    HeartRates person(firstName, uniqueID, day, month, year);

    // Display Information
    cout << "\n--- Health Report ---\n";
    cout << "Name: " << person.getFirstName() << endl;
    cout << "Unique ID: " << person.getUniqueID() << endl;
    cout << "Date of Birth: " << person.getBirthDay() << "/" << person.getBirthMonth() << "/" << person.getBirthYear() << endl;
    cout << "Age: " << person.getAge() << " years" << endl;
    cout << "Maximum Heart Rate: " << person.getMaximumHeartRate() << " BPM" << endl;
    person.getTargetHeartRate(); // Print target heart rate range

    return 0;
}
