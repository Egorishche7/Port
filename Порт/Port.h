#pragma once

#include "Dock.h"
#include "Ship.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

class Port
{
private:
	ifstream fin;
	ofstream fout;
	vector <Dock> dockList;
	queue <Ship> shipList;
	void printShipQueue(queue <Ship> _shipList);
	void printDockList();
public:
	void run();
};