#include <iostream>
#include <string>
#include <tuple>
#include <cmath>
using namespace std;

class Shape
{
protected:
    tuple<float, float> position;
    string color;
    float border;

public:
    Shape(float x, float y, string c, float t) : position(make_tuple(x, y)), color(c), border(t) {}
    virtual void draw()
    {
        cout << "Drawing a Shape." << endl;
    }
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    float radius;
    // we dont need separate member for center's position, we can you the position member of Shape class.
public:
    Circle(float r, float x, float y, string c, float t) : radius(r), Shape(x, y, c, t) {}
    void draw() override
    {
        cout << "Drawing a Circle." << endl;
    }
    double calculateArea() override
    {
        return (3.14 * pow(radius, 2));
    }
    double calculatePerimeter() override
    {
        return (2 * 3.14 * radius);
    }
};

class Rectangle : public Shape
{
private:
    float width;
    float height;
    // we dont need separate member for top-left corner's position, we can you the position member of Shape class.
public:
    Rectangle(float w, float h, float x, float y, string c, float t) : width(w), height(h), Shape(x, y, c, t) {}
    void draw() override
    {
        cout << "Drawing a Rectangle." << endl;
    }
    double calculateArea() override
    {
        return (width * height);
    }
    double calculatePerimeter() override
    {
        return (2 * (width + height));
    }
};

class Triangle : public Shape
{
private:
    float s1, s2, s3;

public:
    Triangle(float a, float b, float c, float x, float y, string clr, float t) : s1(a), s2(b), s3(c), Shape(x, y, clr, t) {}
    void draw() override
    {
        cout << "Drawing a Triangle." << endl;
    }
    double calculateArea() override
    {
        double s = (s1 + s2 + s3) / 2.0;
        if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
        {
            cout << "Invalid Triangle!" << endl;
            return 0;
        }
        return sqrt(s * (s - s1) * (s - s2) * (s - s3));
    }
    double calculatePerimeter() override
    {
        return (s1 + s2 + s3);
    }
};

class Polygon : public Shape
{
private:
    int num;
    tuple<float, float> *vertices;

public:
    Polygon(int n, tuple<float, float> *v, float x, float y, string clr, float t) : num(n), Shape(x, y, clr, t)
    {
        vertices = new tuple<float, float>[num];
        for (int i = 0; i < num; i++)
        {
            vertices[i] = v[i];
        }
    }
    ~Polygon()
    {
        delete[] vertices;
    }
    void draw() override
    {
        cout << "Drawing a Polygon." << endl;
    }
    double calculateArea() override
    {
        double area = 0.0;
        for (int i = 0; i < num; i++)
        {
            float x1 = get<0>(vertices[i]);
            float y1 = get<1>(vertices[i]);
            float x2 = get<0>(vertices[(i + 1) % num]);
            float y2 = get<1>(vertices[(i + 1) % num]);
            area += (x1 * y2 - x2 * y1);
        }
        return (0.5 * fabs(area));
    }
    double calculatePerimeter() override
    {
        double peri = 0.0;
        for (int i = 0; i < num; i++)
        {
            float x1 = get<0>(vertices[i]);
            float y1 = get<1>(vertices[i]);
            float x2 = get<0>(vertices[(i + 1) % num]);
            float y2 = get<1>(vertices[(i + 1) % num]);
            peri += (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
        }
        return peri;
    }
};

int main()
{
    Shape *shapes[4];
    shapes[0] = new Circle(4.2, 10, 10, "Red", 5);
    shapes[1] = new Rectangle(6.6, 3.3, 20, 20, "Green", 9);
    shapes[2] = new Triangle(4, 6, 3, 30, 30, "Blue", 3);
    tuple<float, float> points[] = {
        {0, 0}, {4, 0}, {4, 3}, {0, 3} // A rectangle
    };
    shapes[3] = new Polygon(4, points, 40, 40, "Yellow", 4);

    for (int i = 0; i < 4; i++)
    {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl;
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete shapes[i];
    }

    return 0;
}
