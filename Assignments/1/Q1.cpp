#include <iostream>
#include <string>
using namespace std;

class Skill
{
private:
    int skillID;
    string skillName;
    string description;

public:
    Skill(int id, string name, string desc) : skillID(id), skillName(name), description(desc) {}

    void showSkillDetails()
    {
        cout << "----SKILL DETAILS----" << endl;
        cout << "Skill ID: " << skillID << endl;
        cout << "Skill Name: " << skillName << endl;
        cout << "Skill Description: " << description << endl;
    }

    void updateSkillDetails(string newDescription)
    {
        description = newDescription;
    }

    string getName() const { return skillName; }
};

class Sport
{
private:
    int sportID;
    string name;
    string description;
    string *requiredSkill;
    int skillCount;

public:
    Sport(int id, string n, string des, string req[], int size) : sportID(id), name(n), description(des), skillCount(size)
    {
        requiredSkill = new string[size];
        for (int i = 0; i < size; i++)
        {
            requiredSkill[i] = req[i];
        }
    }
    Sport(const Sport &other) : sportID(other.sportID), name(other.name), description(other.description), skillCount(other.skillCount)
    {
        requiredSkill = new string[skillCount];
        for (int i = 0; i < skillCount; i++)
        {
            requiredSkill[i] = other.requiredSkill[i];
        }
    }

    string getName() const { return name; }

    void addSkill(Skill s)
    {
        if (skillCount >= 50) // Assuming a max limit of 50
        {
            cout << "Array is full. No more space." << endl;
            return;
        }

        string *newRequiredSkill = new string[skillCount + 1];
        for (int i = 0; i < skillCount; i++)
        {
            newRequiredSkill[i] = requiredSkill[i];
        }

        newRequiredSkill[skillCount] = s.getName();
        delete[] requiredSkill;
        requiredSkill = newRequiredSkill;

        skillCount++;
        cout << "Added " << s.getName() << " to sport " << name << endl;
    }

    void removeSkill(Skill s)
    {
        int found = -1;
        for (int i = 0; i < skillCount; i++)
        {
            if (s.getName() == requiredSkill[i])
            {
                found = i;
                break;
            }
        }
        if (found != -1)
        {
            for (int i = found; i < skillCount - 1; i++)
            {
                requiredSkill[i] = requiredSkill[i + 1];
            }
            requiredSkill[skillCount - 1] = "";
            skillCount--;
            cout << "Removed skill: " << s.getName() << " from sport: " << name << endl;
        }
        else
        {
            cout << "Skill not found in skill set." << endl;
        }
    }
    ~Sport()
    {
        delete[] requiredSkill;
    }
};

class Mentor;

class Student
{
private:
    int studentID;
    string name;
    int age;
    string *sportsInterests;
    int interestsCount;
    Mentor *mentorAssigned;
    static int studentCount;

public:
    Student(int id, string n, int a, string *interests, int size) : studentID(id), name(n), age(a), interestsCount(size), mentorAssigned(nullptr)
    {
        sportsInterests = new string[size];
        for (int i = 0; i < size; i++)
        {
            sportsInterests[i] = interests[i];
        }
        studentCount++;
    }

    ~Student()
    {
        delete[] sportsInterests;
    }

    string getName() const { return name; }
    int getID() const { return studentID; }
    int getAge() const { return age; }
    int getInterestCount() const { return interestsCount; }
    Mentor *getMentor() { return mentorAssigned; }
    string getSport(int i) { return (i < interestsCount) ? sportsInterests[i] : ""; }

    void assignMentor(Mentor *m);
    void registerForMentorship(Mentor &m);
    void viewMentorDetails();
    void updateSportsInterests(Sport &s)
    {
        if (interestsCount < 10)
        {
            string *newSportsInterests = new string[interestsCount + 1];
            for (int i = 0; i < interestsCount; i++)
            {
                newSportsInterests[i] = sportsInterests[i];
            }
            newSportsInterests[interestsCount] = s.getName();
            delete[] sportsInterests;
            sportsInterests = newSportsInterests;
            interestsCount++;
            cout << "Added " << s.getName() << endl;
        }
        else
        {
            cout << "Cannot add more interests. Maximum limit reached." << endl;
        }
    }
};

int Student::studentCount = 0;

class Mentor
{
private:
    int mentorID;
    string name;
    string *sportsExpertise;
    int expertiseCount;
    int maxLearners;
    Student **assignedLearners;
    int assignedCount;

public:
    Mentor(int id, string n, string *expert, int size, int max) : mentorID(id), name(n), expertiseCount(size), maxLearners(max), assignedCount(0)
    {
        sportsExpertise = new string[size];
        for (int i = 0; i < size; i++)
        {
            sportsExpertise[i] = expert[i];
        }
        assignedLearners = new Student *[max];
    }

    int getCount() const { return expertiseCount; }
    int getAssignedCount() const { return assignedCount; }
    string getExpertise(int i) const { return sportsExpertise[i]; }
    Student *getLearners(int i) const { return assignedLearners[i]; }
    string getName() const { return name; }
    int getID() const { return mentorID; }

    ~Mentor()
    {
        delete[] sportsExpertise;
        delete[] assignedLearners;
    }

    void assignLearner(Student &s)
    {
        if (assignedCount < maxLearners)
        {
            assignedLearners[assignedCount++] = &s;
            s.assignMentor(this);
            cout << s.getName() << " is assigned to mentor " << name << endl;
        }
        else
        {
            cout << "No space for more learners." << endl;
        }
    }

    void removeLearner(Student &s)
    {
        int found = -1;
        for (int i = 0; i < assignedCount; i++)
        {
            if (assignedLearners[i]->getID() == s.getID())
            {
                found = i;
                break;
            }
        }
        if (found != -1)
        {
            for (int i = found; i < assignedCount - 1; i++)
            {
                assignedLearners[i] = assignedLearners[i + 1];
            }
            assignedLearners[assignedCount - 1] = nullptr;
            assignedCount--;

            s.assignMentor(nullptr);

            cout << "Removed learner " << s.getName() << "." << endl;
        }
        else
        {
            cout << "Student not found in assigned learners." << endl;
        }
    }

    void viewLearners()
    {
        cout << "\n----LEARNERS DETAILS----" << endl;
        if (assignedCount == 0)
        {
            cout << "No learners assigned to " << name << "." << endl;
            return;
        }

        for (int i = 0; i < assignedCount; i++)
        {
            if (assignedLearners[i] == nullptr)
                continue;

            Student *s = assignedLearners[i];

            cout << "Name: " << s->getName() << endl;
            cout << "ID: " << s->getID() << endl;
            cout << "Age: " << s->getAge() << endl;

            Mentor *assignedMentor = s->getMentor();
            if (assignedMentor != nullptr)
                cout << "Mentor Assigned: " << assignedMentor->getName() << endl;
            else
                cout << "Mentor Assigned: None" << endl;

            cout << "Sports Interests: " << endl;
            for (int j = 0; j < s->getInterestCount(); j++)
            {
                string sport = s->getSport(j);
                if (!sport.empty())
                    cout << " - " << sport << endl;
            }
            cout << "---------------------------" << endl;
        }
    }

    void provideGuidance(Student &s, Sport &sp)
    {
        cout << "\n---- GUIDANCE FROM MENTOR " << name << " ----" << endl;
        cout << "Hello " << s.getName() << " Based on your interest in " << sp.getName() << ", here are some tips:" << endl;

        cout << "1. **Training Routine:**" << endl;
        cout << "       - Practice at least 5 days a week." << endl;

        cout << "2. **Progress Tracking:**" << endl;
        cout << "       - Keep a log of your daily progress." << endl;
        cout << "       - Record your best performance in each session.\n"
             << endl;

        cout << "Good luck, " << s.getName() << "! Keep pushing yourself!" << endl;
    }
};

void Student::registerForMentorship(Mentor &m)
{
    for (int i = 0; i < interestsCount; i++)
    {
        for (int j = 0; j < m.getCount(); j++)
        {
            if (sportsInterests[i] == m.getExpertise(j))
            {
                mentorAssigned = &m;
                m.assignLearner(*this);
                return;
            }
        }
    }
    cout << "No matching expertise found." << endl;
}

void Student::viewMentorDetails()
{
    if (!mentorAssigned)
    {
        cout << "No mentor assigned yet." << endl;
        return;
    }
    cout << "\n----MENTOR DETAILS----" << endl;
    cout << "Name: " << getMentor()->getName() << endl;
    cout << "ID: " << getMentor()->getID() << endl;
    cout << "Sports Expertise: " << endl;
    for (int i = 0; i < getMentor()->getCount(); i++)
    {
        cout << " - " << getMentor()->getExpertise(i) << endl;
    }
    cout << "Assigned Learners: " << endl;
    for (int i = 0; i < getMentor()->getAssignedCount(); i++)
    {
        cout << " - " << getMentor()->getLearners(i)->getName() << endl;
    }
}

void Student::assignMentor(Mentor *m)
{
    mentorAssigned = m;
}

int main()
{
    Skill skill1(1, "Dribbling", "Ability to control the ball with feet.");
    Skill skill2(2, "Shooting", "Ability to score goals.");
    Skill skill3(3, "Passing", "Ability to pass the ball accurately.");

    skill1.showSkillDetails();
    skill2.showSkillDetails();
    skill3.showSkillDetails();

    string footballSkills[] = {"Dribbling", "Shooting", "Passing"};
    Sport football(1, "Football", "A team sport played with a spherical ball.", footballSkills, 3);

    football.addSkill(skill1);
    football.addSkill(skill2);
    football.removeSkill(skill1);

    string student1Interests[] = {"Football"};
    Student student1(1, "John Doe", 20, student1Interests, 1);

    string mentor1Expertise[] = {"Football"};
    Mentor mentor1(1, "Coach Smith", mentor1Expertise, 1, 5);

    student1.registerForMentorship(mentor1);

    student1.viewMentorDetails();

    mentor1.provideGuidance(student1, football);

    mentor1.viewLearners();
    return 0;
}
