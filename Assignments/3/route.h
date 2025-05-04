#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
#include <string>
using namespace std;

class Route
{
    string startStop, endStop;

public:
    Route(string start, string end);
    Route();
    void display() const;
};

#endif
