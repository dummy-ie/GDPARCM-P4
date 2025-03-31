// P4Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ModelServer.h"

int main()
{
    //std::cout << "Hello World!\n";
    ModelServer::runServer(50051);
}
