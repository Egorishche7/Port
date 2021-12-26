#pragma once

#include "Ship.h"
#include <iostream>

using namespace std;

class Dock
{
private:
	bool isBusy = true;
	Ship ship;
public:
	void setShip(Ship);
	bool getDockBusyStatus() const;
	void setDockBusyStatus(bool);
	Ship getShip() const;
};