#pragma once

#include "Port.h"
#include "Dock.h"
#include "Ship.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

void Port::printShipQueue(queue <Ship> _shipList)
{
	while (!_shipList.empty())
	{
		cout << _shipList.front().getShipName() << endl;
		fout << _shipList.front().getShipName() << endl;
		_shipList.pop();
	}
}

void Port::printDockList()
{
	cout << "The dock list status is:" << endl;
	fout << "The dock list status is:" << endl;
	for (size_t i = 0; i < dockList.size(); i++)
	{
		cout << "Dock number " << i + 1 << ":";
		fout << "Dock number " << i + 1 << ":";
		if (dockList[i].getDockBusyStatus() == true)
		{
			cout << " is empty\n";
			fout << " is empty\n";
		}
		else
		{
			cout << " the ship " << dockList[i].getShip().getShipName() << " is unloading" << endl;
			fout << " the ship " << dockList[i].getShip().getShipName() << " is unloading" << endl;
		}
	}
}

void Port::run()
{
	char s1[100];
	fin.open("SHIPS.IN.txt");
	fout.open("SHIPS.OUT.txt");

	if (!fin.is_open() || fin.peek() == '\0')
	{
		cout << "File is wrong or empty!\n";
		fout << "File is wrong or empty!\n";
	}
	else
	{
		fin.getline(s1, 100);
		int numOfDocks = stoi(s1);
		for (int i = 0; i < numOfDocks; i++)
			dockList.push_back(Dock());
		while (fin.getline(s1, 100))
		{
			string s(s1);

			switch (s1[0])
			{
			case '1': {
				//add ship to the reid
				string data = s.substr(2, s.length());
				shipList.push(Ship(data)); break; }
			case '2': {

				//move ship to dock
				string data = s.substr(2, s.length());
				cout << "The Dock " << data << " take a ship" << endl;
				fout << "The Dock " << data << "take a ship" << endl;
				int dockNumber = stoi(data);
				if (!shipList.empty())
				{
					dockList[dockNumber].setShip(shipList.front());
					shipList.pop();
					dockList[dockNumber].setDockBusyStatus(false);
				}
				else
				{
					dockList[dockNumber].setDockBusyStatus(true);
				}
				break; }
			case '3': {
				cout << "The queue of the ships is:\n";
				fout << "The queue of the ships is:\n";
				printShipQueue(shipList);
				break; }
			case '4': {
				printDockList();
				break; }
			default: {
				cout << "wrong data in file\n";
				fout << "wrong data in file\n"; }
			}
		}
		fin.close();
		fout.close();
	}
}