// SpaceStationProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SpaceStation.hpp"
#include "Robot.hpp"


#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

int main()
{
	std::shared_ptr<SpaceStation> spaceStation = std::make_shared<SpaceStation>();
	spaceStation->init();

	for (int i = 0; i < 20; i++) {

	spaceStation->addRobot();

	}


	std::cout << "0. ";  

	spaceStation->printStatus();
	{
		std::shared_ptr<SpaceStation> spaceStation2(spaceStation);
			for (int i = 0; i < 10; i++) {

				spaceStation->addRobot();

			}

	}


	//auto aRobot = spaceStation->getRobot();
	auto aRobot = spaceStation->getAllRobot();
	for (int i = 0;i<aRobot.size(); i++) {

	/*if (!i.expired())
	{ 
		aRobot.lock()->checkSpaceStation();
	 }*/
		std::cout<< i+1 << ". ";
		aRobot.at(i)->checkSpaceStation();

	}

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

}
