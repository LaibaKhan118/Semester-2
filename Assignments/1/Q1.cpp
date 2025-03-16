#include <iostream>
#include <string>
using namespace std;

class Skill {
private:
    int skillID;
    string skillName;
    string description;

public:
    Skill(int id, string name, string desc) : skillID(id), skillName(name), description(desc) {}

    void showSkillDetails() {
        cout << "----SKILL DETAILS----" << endl;
        cout << "Skill ID: " << skillID << endl;
        cout << "Skill Name: " << skillName << endl;
        cout << "Skill Description: " << description << endl;
    }

    void updateSkillDetails(string newDescription) {
        description = newDescription;
    }
};

class Sport {
private:
    int sportID;
    string name;
    string description;
    string* requiredSkill;
    int skillCount;
    
public:
    Sport(int id, string n, string des, string req[], int size) : sportID(id), name(n), description(des), skillCount(size) {
        requiredSkill = new string[size];
        for (int i = 0; i < size; i++) {
            requiredSkill[i] = req[i];
        }
    }
    
    ~Sport() {
        delete[] requiredSkill;
    }
};

class Mentor; 

class Student {
private:
    int studentID;
    string name;
    int age;
    string* sportsInterests;
    int interestsCount;
    Mentor* mentorAssigned;
    static int studentCount;

public:
    Student(int id, string n, int a, string interests[], int size) : studentID(id), name(n), age(a), interestsCount(size), mentorAssigned(nullptr) {
        sportsInterests = new string[size];
        for (int i = 0; i < size; i++) {
            sportsInterests[i] = interests[i];
        }
        studentCount++;
    }

    ~Student() {
        delete[] sportsInterests;
    }

    void registerForMentorship(Mentor& m);
    void viewMentorDetails();
};

int Student::studentCount = 0;

class Mentor {
private:
    int mentorID;
    string name;
    string* sportsExpertise;
    int expertiseCount;
    int maxLearners;
    Student** assignedLearners;
    int assignedCount;

public:
    Mentor(int id, string n, string expert[], int size, int max) : mentorID(id), name(n), expertiseCount(size), maxLearners(max), assignedCount(0) {
        sportsExpertise = new string[size];
        for (int i = 0; i < size; i++) {
            sportsExpertise[i] = expert[i];
        }
        assignedLearners = new Student*[max];
    }

    ~Mentor() {
        delete[] sportsExpertise;
        delete[] assignedLearners;
    }

    void assignLearner(Student& s) {
        if (assignedCount < maxLearners) {
            assignedLearners[assignedCount++] = &s;
            cout << s.name << " is assigned to mentor " << name << endl;
        } else {
            cout << "No space for more learners." << endl;
        }
    }
};

void Student::registerForMentorship(Mentor& m) {
    for (int i = 0; i < interestsCount; i++) {
        for (int j = 0; j < m.expertiseCount; j++) {
            if (sportsInterests[i] == m.sportsExpertise[j]) {
                mentorAssigned = &m;
                m.assignLearner(*this);
                return;
            }
        }
    }
    cout << "No matching expertise found." << endl;
}

int main() {
    string basketballSkills[] = {"Dribbling", "Shooting", "Defense"};
    Sport s(101, "Basketball", "A team sport played with a ball and hoop.", basketballSkills, 3);
    
    string mentorExpertiseM1[] = {"Basketball", "Football"};
    Mentor m1(201, "Coach Jeff", mentorExpertiseM1, 2, 5);
    
    string studentInterests1[] = {"Basketball", "Tennis"};
    Student stud1(301, "John", 20, studentInterests1, 2);
    
    stud1.registerForMentorship(m1);
    
    return 0;
}

// Mistakes In The Previous Code
/*
    1. Encapsulation: All data members were public. Had to do so to avoid the errors I was getting.
    2. Arrays: I should've used DMA for arrays. I didn't because the concept was not clear yet. 
    3. viewMentorDetails() Logic: That was a mistake; it should display m.name instead of mentorAssigned.
    4. Invalid Array Bounds in Loop: That was a typo.
    5. Returning from registerForMentorship() Immediately: I should have checked all expertise before returning.
*/
