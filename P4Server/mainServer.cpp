// mainServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

#include "ModelServer.h"

int main()
{
	//std::cout << "Hello World!\n";
	//bool isStopping = false;
	bool isRunning = true;

	ModelServer* server = new ModelServer(isRunning);
	server->start();

	// isRunning is changed in the ModelServer destructor
	while (isRunning)
	{
		std::cout << "Press S to shut down the server. ";

		if (const auto in = _getch(); in == 's' || in == 'S')
		{
			std::cout << "Shutting down the server...\n";
			delete server;
		}
		else
		{
			std::cout << "Invalid input. \n";
		}
	}


	return 0;
}
