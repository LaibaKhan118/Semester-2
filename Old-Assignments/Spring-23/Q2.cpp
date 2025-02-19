#include <iostream>
#include <string>

using namespace std;

class DataScientist
{
private:
    static int totalUsers; // Tracks the total number of users
    const int userID;      // Unique user ID (read-only)
    string firstName;
    string lastName;
    string highestEducation; // Can be set but not accessed
    int age;
    string country;
    int questionsAsked; // Read-only
    int answersGiven;   // Read-only

public:
    // Constructor to initialize a Data Scientist
    DataScientist(string fName, string lName, string education, int age, string country, int id)
        : firstName(fName), lastName(lName), highestEducation(education), age(age),
          country(country), userID(id), questionsAsked(0), answersGiven(0)
    {
        totalUsers++; // Increment total users
    }

    // Getter for userID
    int getUserID() const
    {
        return userID;
    }

    // Getters and Setters
    void setFirstName(string fName) { firstName = fName; }
    void setLastName(string lName) { lastName = lName; }
    void setAge(int newAge) { age = newAge; }
    void setCountry(string newCountry) { country = newCountry; }

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    int getAge() const { return age; }
    string getCountry() const { return country; }

    // Function to post a question
    void AskQuestion()
    {
        questionsAsked++;
        cout << firstName << " " << lastName << " has posted a question. Total questions: " << questionsAsked << endl;
    }

    // Function to answer a question
    void AnswerProblem()
    {
        answersGiven++;
        cout << firstName << " " << lastName << " has answered a question. Total answers: " << answersGiven << endl;
    }

    // Get read-only properties
    int getQuestionsAsked() const { return questionsAsked; }
    int getAnswersGiven() const { return answersGiven; }

    // Static function to get total users
    static int getTotalUsers()
    {
        return totalUsers;
    }
};

// Initialize static variable
int DataScientist::totalUsers = 0;

// Admin Class
class Admin
{
private:
    string firstName;
    string lastName;
    int age;
    string country;
    int adminID;

public:
    // Constructor
    Admin(string fName, string lName, int age, string country, int id)
        : firstName(fName), lastName(lName), age(age), country(country), adminID(id) {}

    // Getters and Setters
    void setFirstName(string fName) { firstName = fName; }
    void setLastName(string lName) { lastName = lName; }
    void setAge(int newAge) { age = newAge; }
    void setCountry(string newCountry) { country = newCountry; }

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    int getAge() const { return age; }
    string getCountry() const { return country; }

    // Function to display total users (only admin can see this)
    void TotalUsers() const
    {
        cout << "Total Data Scientists on DataHub: " << DataScientist::getTotalUsers() << endl;
    }
};


int main()
{
    // Ask user for student ID
    string studentID;
    cout << "Enter your student ID (format: 24K-1234): ";
    cin >> studentID;

    // Generate User ID
    int userID = stoi(studentID.substr(studentID.length() - 2));

    // Create Admin
    Admin admin1("Alice", "Smith", 35, "USA", 101);

    // Create Data Scientist users
    DataScientist ds1("John", "Doe", "PhD in Data Science", 28, "Canada", userID);
    DataScientist ds2("Emily", "Brown", "MSc in AI", 26, "UK", userID + 1);

    // Users ask and answer questions
    ds1.AskQuestion();
    ds1.AskQuestion();
    ds1.AnswerProblem();

    ds2.AskQuestion();
    ds2.AnswerProblem();
    ds2.AnswerProblem();

    // Admin displays total users
    admin1.TotalUsers();

    return 0;
}
