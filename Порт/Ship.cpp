#pragma once

#include "Ship.h"
#include <iostream>

using namespace std;

Ship::Ship() {}

Ship::Ship(string _shipName)
{
	shipName = _shipName;
}

Ship& Ship::operator = (const Ship& _ship)
{
	// Проверка на самоприсваивание
	if (this == &_ship)
		return *this;
	shipName = _ship.shipName;
	return *this; // возвращает объект, который сгенерировал вызов
}

string Ship::getShipName() const
{
	return shipName;
}