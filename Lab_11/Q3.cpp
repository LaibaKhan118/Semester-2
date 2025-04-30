/*Create an exception hierarchy:
Base class: FileException (with what()).
Derived classes: FileNotFoundException, Permission Denied Exception.
Write a function readFile(const string& filename) that throws these exceptions based on file issues.
Requirements:
Use polymorphism to catch base class FileException.
Handle specific exceptions in separate catch blocks.
Sample Input/Output:
Reading 'secret.txt': Permission Denied Exception - Access denied!*/

#include <iostream>
#include <exception>
#include <fstream>
using namespace std;

class FileException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "FileException occurred!";
    }
};

class FileNotFoundException : public FileException
{
public:
    const char *what() const noexcept override
    {
        return "FileNotFoundException - File not found!";
    }
};

class PermissionDenied : public FileException
{
public:
    const char *what() const noexcept override
    {
        return "Permission Denied Exception - Access denied!";
    }
};

void readFile(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        if (filename == "secret.txt")
        {
            throw FileNotFoundException();
        }
        else
        {
            throw PermissionDenied();
        }
    }
    cout << filename << " was opened successfully!" << endl;
    file.close();
}

int main()
{
    try
    {
        readFile("example.txt"); // Created example.txt manually n file explorer to show permission denied exception
    }
    catch (const FileNotFoundException &e)
    {
        cout << e.what() << endl;
    }
    catch (const PermissionDenied &e)
    {
        cout << e.what() << endl;
    }
    catch (const FileException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
