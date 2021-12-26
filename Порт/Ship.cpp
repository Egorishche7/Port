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
	// �������� �� ����������������
	if (this == &_ship)
		return *this;
	shipName = _ship.shipName;
	return *this; // ���������� ������, ������� ������������ �����
}

string Ship::getShipName() const
{
	return shipName;
}