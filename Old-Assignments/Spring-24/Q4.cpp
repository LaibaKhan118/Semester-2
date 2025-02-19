#include <iostream>
using namespace std;

// Base Class: GameObject
class GameObject
{
protected:
    const string name; // Constant name (Student ID format)
    int X, Y;          // Coordinates

public:
    // Constructor
    GameObject(string id, int x, int y) : name(id), X(x), Y(y) {}

    // Virtual draw function (to be overridden)
    virtual void draw()
    {
        cout << "Drawing GameObject: " << name << " at (" << X << ", " << Y << ")" << endl;
    }

    // Virtual destructor
    virtual ~GameObject() {}
};

// Derived Class: Player
class Player : public GameObject
{
private:
    int health;

public:
    // Constructor
    Player(int x, int y, int h) : GameObject("22K-1345", x, y), health(h) {}

    // Override draw()
    void draw() override
    {
        cout << "Drawing Player at (" << X << ", " << Y << ") with Health: " << health << endl;
    }

    // Getter & Setter
    int getHealth() { return health; }
    void setHealth(int h) { health = h; }

    // Overloaded "==" operator (compare health)
    bool operator==(const Player &other)
    {
        return health == other.health;
    }
};

// Derived Class: Enemy
class Enemy : public GameObject
{
private:
    int damage;

public:
    // Constructor
    Enemy(int x, int y, int d) : GameObject("22K-1345", x, y), damage(d) {}

    // Override draw()
    void draw() override
    {
        cout << "Drawing Enemy at (" << X << ", " << Y << ") with Damage: " << damage << endl;
    }

    // Getter & Setter
    int getDamage() { return damage; }
    void setDamage(int d) { damage = d; }
};

// Derived Class: PowerUp
class PowerUp : public GameObject
{
private:
    string effect;

public:
    // Constructor
    PowerUp(int x, int y, string e) : GameObject("22K-1345", x, y), effect(e) {}

    // Override draw()
    void draw() override
    {
        cout << "Drawing PowerUp at (" << X << ", " << Y << ") with Effect: " << effect << endl;
    }

    // Getter & Setter
    string getEffect() { return effect; }
    void setEffect(string e) { effect = e; }
};

// Game Class to Manage Objects (Dynamic Array)
class Game
{
private:
    GameObject **objects; // Array of pointers to GameObject
    int size;             // Current number of objects
    int capacity;         // Maximum capacity

public:
    // Constructor
    Game(int cap)
    {
        capacity = cap;
        size = 0;
        objects = new GameObject *[capacity]; // Dynamic allocation
    }

    // Function to add a GameObject
    void addObject(GameObject *obj)
    {
        if (size < capacity)
        {
            objects[size++] = obj;
        }
        else
        {
            cout << "Game object list is full!" << endl;
        }
    }

    // Function to draw all objects
    void drawAll()
    {
        for (int i = 0; i < size; i++)
        {
            objects[i]->draw();
        }
    }

    // Destructor
    ~Game()
    {
        for (int i = 0; i < size; i++)
        {
            delete objects[i]; // Free allocated memory
        }
        delete[] objects; // Delete array
    }
};

// Main Function
int main()
{
    // Creating Game Object Manager with capacity 3
    Game myGame(3);

    // Creating objects dynamically
    Player *p = new Player(5, 10, 100);
    Enemy *e = new Enemy(8, 12, 30);
    PowerUp *pu = new PowerUp(3, 7, "Speed Boost");

    // Adding objects to the game
    myGame.addObject(p);
    myGame.addObject(e);
    myGame.addObject(pu);

    // Calling drawAll to display all objects
    myGame.drawAll();

    return 0; // Destructor of Game class will clean up memory
}
