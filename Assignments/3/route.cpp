#include "route.h"

Route::Route(string start, string end) : startStop(start), endStop(end) {}

Route::Route() : startStop(""), endStop("") {}

void Route::display() const
{
    cout << "Route: " << startStop << " to " << endStop << endl;
}
