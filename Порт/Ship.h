#pragma once

#include <iostream>

using namespace std;

class Ship
{
private:
	string shipName;
	const int max = 5;
	const int min = 1;
public:
	Ship();
	Ship(string);
	Ship& operator = (const Ship&);
	string getShipName() const;
};