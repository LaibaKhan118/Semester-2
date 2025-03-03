/*Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class ValidateString
{
private:
    string word;

public:
    ValidateString(const string &w) : word(w) {}

    // if the function is not constant then it will be allowed to modify the object which could lead to unexpected behavior
    bool validate() const
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (!isalpha(i))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    ValidateString obj1("Hello");
    ValidateString obj2("123");

    cout << "Object 1 is " << (obj1.validate() ? "valid" : "invalid") << endl;
    cout << "Object 2 is " << (obj2.validate() ? "valid" : "invalid") << endl;

    return 0;
}
