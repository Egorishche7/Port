#pragma once

#include "Dock.h"
#include <iostream>

using namespace std;

void Dock::setShip(Ship _ship)
{
	ship = _ship;
}

bool Dock::getDockBusyStatus() const
{
	return isBusy;
}

void Dock::setDockBusyStatus(bool _isBusy)
{
	isBusy = _isBusy;
}

Ship Dock::getShip() const
{
	return ship;
}