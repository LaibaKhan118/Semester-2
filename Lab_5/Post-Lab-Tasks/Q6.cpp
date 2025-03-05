/*Write a program that uses composition to implement a game engine. A game engine is made up of
several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logic for how these individual components work.*/

#include <iostream>
using namespace std;
class Graphics
{
public:
    Graphics() { cout << "Graphics Rendering Engine Created!" << endl; }
    ~Graphics() { cout << "Graphics Rendering Engine Destroyed!" << endl; }
};

class Input
{
public:
    Input() { cout << "Input handler Created!" << endl; }
    ~Input() { cout << "Input handler Destroyed!" << endl; }
};

class Physics
{
public:
    Physics() { cout << "Physics Engine Created!" << endl; }
    ~Physics() { cout << "Physics Engine Destroyed!" << endl; }
};

class Game
{
private:
    Graphics graphics_rendering_engine;
    Input input_handler;
    Physics physics_handler;

public:
    Game() { cout << "Game Created!" << endl; }
    ~Game() { cout << "Game Destroyed!" << endl; }
};
int main()
{
    Game g1;
    return 0;
}
