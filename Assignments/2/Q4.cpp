// A2-Q4[24K-0644]
#include <iostream>
#include <string>
using namespace std;

int generateHash(const string &pass)
{
    int hash = 5381;
    for (char c : pass)
    {
        hash = hash * 33 + static_cast<int>(c);
    }
    return hash;
}

class User
{
protected:
    string name;
    string ID;
    string email;
    int hashed_pass;
    string *permissions;
    int permCount;

public:
    User(string n, string id, string e, string pass, string *perm, int count) : name(n), ID(id), email(e), permCount(count)
    {
        hashed_pass = generateHash(pass);
        permissions = new string[permCount];
        for (int i = 0; i < permCount; i++)
        {
            permissions[i] = perm[i];
        }
    }

    virtual ~User()
    {
        delete[] permissions;
    }

    bool authenticate(string pass)
    {
        return generateHash(pass) == hashed_pass;
    }

    virtual void display() const
    {
        cout << "Name: " << name << "\nID: " << ID << "\nEmail: " << email << "\nRole: Generic User" << "\nPermissions: " << endl;
        for (int i = 0; i < permCount; i++)
        {
            cout << " " << i + 1 << ". " << permissions[i] << endl;
        }
    }

    bool hasPermission(string action)
    {
        for (int i = 0; i < permCount; i++)
        {
            if (action == permissions[i])
            {
                return true;
            }
        }
        return false;
    }

    virtual bool accessLab(string action)
    {
        if (hasPermission(action))
        {
            cout << name << " has been granted access to: " << action << endl;
            return true;
        }
        cout << name << " doesn't have permission to: " << action << endl;
        return false;
    }
};

class Student : public User
{
protected:
    bool *assignments;
    int assignmentCount;

public:
    Student(string n, string id, string e, string pass, int aCount) : User(n, id, e, pass, new string[1]{"submit_assignment"}, 1), assignmentCount(aCount)
    {
        assignments = new bool[assignmentCount];
        for (int i = 0; i < assignmentCount; i++)
        {
            assignments[i] = false;
        }
    }

    ~Student()
    {
        delete[] assignments;
    }

    void display() const override
    {
        cout << "Name: " << name << "\nID: " << ID << "\nEmail: " << email << "\nRole: Student" << "\nPermissions: " << endl;
        for (int i = 0; i < permCount; i++)
        {
            cout << " " << i + 1 << ". " << permissions[i] << endl;
        }
    }

    void submitAssignment(int index)
    {
        if ((index - 1) >= 0 && (index - 1) < assignmentCount)
        {
            assignments[index - 1] = true;
            cout << name << " has successfully submitted assignment " << index << endl;
        }
        else
        {
            cout << "Invalid Assignment Index!" << endl;
        }
    }

    void viewAssignments() const
    {
        cout << name << "'s assignment status:" << endl;
        for (int i = 0; i < assignmentCount; i++)
        {
            cout << "Assignment " << i + 1 << ": " << (assignments[i] ? "Submitted" : "Pending") << endl;
        }
    }

    string getName() const { return name; }
};

class TA : public Student
{
protected:
    Student **managedStudents;
    int studentCount;
    string *projects;
    int projectCount;

public:
    TA(string n, string id, string e, string pass, int aCount) : Student(n, id, e, pass, aCount), studentCount(0), projectCount(0)
    {
        delete[] permissions;
        permissions = new string[2]{"view_projects", "manage_students"};
        permCount = 2;

        managedStudents = new Student *[10];
        projects = new string[2];
    }

    ~TA()
    {
        delete[] managedStudents;
        delete[] projects;
    }

    void display() const override
    {
        cout << "Name: " << name << "\nID: " << ID << "\nEmail: " << email << "\nRole: Student" << "\nPermissions: " << endl;
        for (int i = 0; i < permCount; i++)
        {
            cout << " " << i + 1 << ". " << permissions[i] << endl;
        }
    }

    void addStudent(Student *student)
    {
        if (studentCount < 10)
        {
            managedStudents[studentCount++] = student;
            cout << name << " is managing " << student->getName() << endl;
        }
        else
        {
            cout << "Cannot add more students! Capacity Reached." << endl;
        }
    }

    bool addproject(string project)
    {
        if (projectCount < 2)
        {
            projects[projectCount++] = project;
            cout << name << " is now working on project: " << project << endl;
            return true;
        }
        cout << "Cannot add more projects! Capacity Reached." << endl;
        return false;
    }

    void viewProjects()
    {
        cout << name << "'s current projects:\n";
        for (int i = 0; i < projectCount; i++)
        {
            cout << "- " << projects[i] << endl;
        }
    }
};

class Professor : public User
{
protected:
    TA **tas;
    int taCount;
    int taCapacity;

public:
    Professor(string n, string id, string e, string pass, int cap) : User(n, id, e, pass, (new string[2]{"assign_projects", "full_lab_access"}), 2), taCapacity(cap), taCount(0)
    {
        tas = new TA *[taCapacity];
    }

    ~Professor()
    {
        delete[] tas;
    }

    void assignProject(TA *ta, string project)
    {
        if (taCount < taCapacity)
        {
            if (ta->addproject(project))
            {
                tas[taCount++] = ta;
            }
        }
    }
};

void authenticateAndPerformAction(User *user, string password, string action)
{
    if (user->authenticate(password))
    {
        cout << "Authentication Successful." << endl;
        user->accessLab(action);
    }
    else
    {
        cout << "Authentication failed." << endl;
    }
}

int main()
{
    Professor prof("Dr. Zunairah", "P001", "smith@university.edu", "profpass", 5);

    TA ta1("Yumna", "TA001", "alice@university.edu", "tapass1", 3);
    TA ta2("Faiza", "TA002", "bob@university.edu", "tapass2", 3);

    prof.assignProject(&ta1, "AI Research");
    prof.assignProject(&ta1, "Data Science");
    prof.assignProject(&ta2, "Quantum Computing");

    cout << endl;
    ta1.viewProjects();
    ta2.viewProjects();

    Student student1("Aamna", "S001", "charlie@university.edu", "studpass1", 3);
    Student student2("Abeeha", "S002", "diana@university.edu", "studpass2", 3);

    cout << endl;
    ta1.addStudent(&student1);
    ta1.addStudent(&student2);

    cout << endl;
    student1.submitAssignment(1);
    student1.submitAssignment(2);
    student2.submitAssignment(1);

    cout << endl;
    student1.viewAssignments();
    student2.viewAssignments();

    cout << endl;
    authenticateAndPerformAction(&prof, "profpass", "full_lab_access");
    authenticateAndPerformAction(&ta1, "tapass1", "view_projects");
    authenticateAndPerformAction(&student1, "studpass1", "submit_assignment");

    return 0;
}
