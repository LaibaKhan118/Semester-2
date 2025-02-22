#include <iostream>
#include <tuple>
using namespace std;

class Robot
{
public:
    string name;
    int hits;
    int x, y;

    Robot(string n)
    {
        x = 0;
        y = 0;
        hits = 0;
        name = n;
    }

    void hitBall(int &ballX, int &ballY, const string &direction)
    {
        if (direction == "up")
        {
            ballY += 1;
            y += 1;
        }
        else if (direction == "down")
        {
            ballY -= 1;
            y -= 1;
        }
        else if (direction == "left")
        {
            ballX -= 1;
            x -= 1;
        }
        else if (direction == "right")
        {
            ballX += 1;
            x += 1;
        }
        hits++;
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }

    tuple<int, int> getPosition()
    {
        return make_tuple(x, y);
    }

    bool isGoalReached(int ballX, int ballY)
    {
        if (ballX == 3 && ballY == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Team
{
public:
    string name;
    Robot *rob;

    Team()
    {
        name = "";
    }

    Team(string n, Robot &rob)
    {
        name = n;
        this->rob = &rob;
    }
};

class Game
{
public:
    Team team1, team2;
    int ballX, ballY;

    Game(string n1, string n2, Robot &rob1, Robot &rob2)
    {
        team1 = Team(n1, rob1);
        team2 = Team(n2, rob2);
        ballX = 0;
        ballY = 0;
    }

    void startGame()
    {
        cout << "Game started" << endl;
        team1.rob->x = 0;
        team1.rob->y = 0;
        team2.rob->x = 0;
        team2.rob->y = 0;
    }

    void play(Team &team)
    {
        char a;
        ballX = 0;
        ballY = 0;
        cout << team.name << "'s turn!" << endl;
        cout << "A: Left  W: Up  S: Down  D: Right" << endl;
        while (!team.rob->isGoalReached(ballX, ballY))
        {
            cout << "Play your move: " << endl;
            cin >> a;
            switch (a)
            {
            case 'A':
            case 'a':
                team.rob->hitBall(ballX, ballY, "left");
                break;
            case 'W':
            case 'w':
                team.rob->hitBall(ballX, ballY, "up");
                break;
            case 'S':
            case 's':
                team.rob->hitBall(ballX, ballY, "down");
                break;
            case 'D':
            case 'd':
                team.rob->hitBall(ballX, ballY, "right");
                break;
            default:
                cout << "Invalid move! Try again." << endl;
                continue;
            }
            cout << team.rob->name << " moved ball to (" << ballX << ", " << ballY << ")" << endl;
        }
        cout << team.name << " reached the goal in " << team.rob->hits << " hits!" << endl;
    }

    void declareWinner()
    {
        cout << endl
             << "----Results----" << endl;
        cout << team1.name << " scored in " << team1.rob->hits << " hits" << endl
             << "And" << endl;
        cout << team2.name << " scored in " << team2.rob->hits << " hits" << endl
             << endl;
        if (team1.rob->hits < team2.rob->hits)
        {
            cout << "Team " << team1.name << " wins" << endl;
        }
        else if (team2.rob->hits < team1.rob->hits)
        {
            cout << "Team " << team2.name << " wins" << endl;
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

    Game g("Hunters", "Gladiators", r1, r2);
    g.startGame();
    g.play(g.team1);
    g.play(g.team2);
    g.declareWinner();

    return 0;
}
