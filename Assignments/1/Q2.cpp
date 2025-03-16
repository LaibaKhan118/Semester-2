#include <iostream>
#include <tuple>
using namespace std;

class Ball
{
private:
    int x, y;

public:
    Ball()
    {
        x = 0;
        y = 0;
    }

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }

    tuple<int, int> getPosition() const
    {
        return make_tuple(x, y);
    }

    bool isGoalReached(int goalX, int goalY) const
    {
        return (x == goalX && y == goalY);
    }

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
};

class Goal
{
private:
    int x, y;

public:
    Goal(int goalX, int goalY)
    {
        x = goalX;
        y = goalY;
    }

    bool isGoalReached(int ballX, int ballY) const
    {
        return (ballX == x && ballY == y);
    }

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
};

class Robot
{
private:
    string name;
    int hits;

public:
    Robot(string n)
    {
        hits = 0;
        name = n;
    }

    void hitBall(Ball &ball, const string &direction)
    {
        if (direction == "up")
        {
            ball.move(0, 1);
        }
        else if (direction == "down")
        {
            ball.move(0, -1);
        }
        else if (direction == "left")
        {
            ball.move(-1, 0);
        }
        else if (direction == "right")
        {
            ball.move(1, 0);
        }
        hits++;
    }
    string getName() const { return name; }
    int getHits() const { return hits; }

    void setName(string newName) { name = newName; }
    void setHits(int newHits) { hits = newHits; }
};

class Team
{
private:
    string name;
    Robot *rob;

public:
    Team(string n, Robot &rob)
    {
        name = n;
        this->rob = &rob;
    }

    string getName() const { return name; }
    Robot *getRobot() const { return rob; }

    void setName(string newName) { name = newName; }
    void setRobot(Robot *newRobot) { rob = newRobot; }
};

class Game
{
private:
    Team team1, team2;
    Ball ball;
    Goal goal;

public:
    Game(string n1, string n2, Robot &rob1, Robot &rob2, int goalX, int goalY)
        : team1(n1, rob1), team2(n2, rob2), goal(goalX, goalY)
    {
        ball = Ball();
    }

    void startGame()
    {
        cout << "Game started" << endl;
        ball = Ball();
    }

    void play(Team &team)
    {
        char a;
        cout << team.getName() << "'s turn!" << endl;
        cout << "A: Left  W: Up  S: Down  D: Right" << endl;
        while (!goal.isGoalReached(ball.getX(), ball.getY()))
        {
            cout << "Play your move: " << endl;
            cin >> a;
            switch (a)
            {
            case 'A':
            case 'a':
                team.getRobot()->hitBall(ball, "left");
                break;
            case 'W':
            case 'w':
                team.getRobot()->hitBall(ball, "up");
                break;
            case 'S':
            case 's':
                team.getRobot()->hitBall(ball, "down");
                break;
            case 'D':
            case 'd':
                team.getRobot()->hitBall(ball, "right");
                break;
            default:
                cout << "Invalid move! Try again." << endl;
                continue;
            }
            cout << team.getRobot()->getName() << " moved ball to (" << ball.getX() << ", " << ball.getY() << ")" << endl;
        }
        cout << team.getName() << " reached the goal in " << team.getRobot()->getHits() << " hits!" << endl;
    }

    void declareWinner()
    {
        cout << endl
             << "----Results----" << endl;
        cout << team1.getName() << " scored in " << team1.getRobot()->getHits() << " hits" << endl
             << "And" << endl;
        cout << team2.getName() << " scored in " << team2.getRobot()->getHits() << " hits" << endl
             << endl;
        if (team1.getRobot()->getHits() < team2.getRobot()->getHits())
        {
            cout << "Team " << team1.getName() << " wins" << endl;
        }
        else if (team2.getRobot()->getHits() < team1.getRobot()->getHits())
        {
            cout << "Team " << team2.getName() << " wins" << endl;
        }
        else
        {
            cout << "It's a tie" << endl;
        }
    }
};

int main()
{
    Robot r1("Galaxy Annihilator");
    Robot r2("Astroid Destroyer");

    Game g("Hunters", "Gladiators", r1, r2, 3, 3);
    g.startGame();
    g.play(g.getTeam1());
    g.startGame();
    g.play(g.getTeam2());
    g.declareWinner();

    return 0;
}
/*
Mistakes in the previous Code:
1. No Ball class. It's not the Robot's responsibility to manage the Ball's position.
2. No Goal class. It's not the Robot's responsibility to handle the Goal.
3. No encapsulation
4. No reset after first player's done
*/
