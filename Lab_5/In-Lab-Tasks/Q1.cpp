/*Task-01:
Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of
those Square objects. After each time the area method is called, call that square’s getters for area and
allareas to display the updated values.*/

#include <iostream>
using namespace std;

class Square
{
private:
    float sidelength;
    float area;
    static float allarea;

public:
    Square(float len)
    {
        setSideLength(len);
    }

    void setSideLength(float len)
    {
        sidelength = len;
    }

    float getlength()
    {
        return sidelength;
    }
    static float getAllArea();
    float getArea()
    {
        return area;
    }

    void calculateArea()
    {
        area = sidelength * sidelength;
        allarea += area;
    }
};

float Square::allarea = 0.0;
float Square::getAllArea()
{
    return allarea;
}

int main()
{
    Square s1(10), s2(5.9), s3(30.5);
    s1.calculateArea();
    cout << "\nArea of Square 1: " << s1.getArea() << "\nTotal Area: " << Square::getAllArea();
    s2.calculateArea();
    cout << "\nArea of Square 2: " << s2.getArea() << "\nTotal Area: " << Square::getAllArea();
    s3.calculateArea();
    cout << "\nArea of Square 3: " << s3.getArea() << "\nTotal Area: " << Square::getAllArea();

    return 0;
}
