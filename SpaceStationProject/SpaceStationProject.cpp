// SpaceStationProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SpaceStation.hpp"
#include "Robot.hpp"
#include <fstream>


#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

int main()
{
	std::ifstream InputFile("SpaceStationConstruct.txt");
	float pos_x, pos_y, pos_z; int NumRobot;
	while (InputFile >>pos_x>>pos_y>>pos_z>>NumRobot) 
	{
		std::shared_ptr<SpaceStation> NewStationValue = std::make_shared<SpaceStation>();
		NewStationValue->init();

		for (int i = 0; i < NumRobot-1; i++) {

			NewStationValue->addRobot();


		}

		auto NewaRobot = NewStationValue->getAllRobot();

		for (int i = 0; i < NewaRobot.size(); i++) {

			std::cout << "New space station";
			std::cout << i + 1 << ". ";
			NewaRobot.at(i)->checkSpaceStation();
			
		}
	
	
	}




	std::shared_ptr<SpaceStation> spaceStation = std::make_shared<SpaceStation>();
	spaceStation->init();

	for (int i = 0; i < 10; i++) {

	spaceStation->addRobot();

	}


	 

	
	//spaceStation->printStatus();
	{
		std::shared_ptr<SpaceStation> spaceStation2(spaceStation);
			for (int i = 0; i < 5; i++) {// add 10 robot

				spaceStation->addRobot();


			}


	}

	//copy construct
	std::shared_ptr<SpaceStation> spaceStation3 = std::make_shared<SpaceStation>();
	spaceStation3->operator=(spaceStation);

	for (int i = 0; i < 3; i++) { //add 5 robot

		spaceStation3->addRobot();

	}

	auto aRobot3 = spaceStation3->getAllRobot();

	for (int i = 0; i < aRobot3.size(); i++) {

	std::cout << "print form station 3 "  ;
	std::cout << i + 1 << ". ";
	aRobot3.at(i)->checkSpaceStation();

	}


	//copy from space station (not shared)





	//auto aRobot = spaceStation->getRobot();

	auto aRobot = spaceStation->getAllRobot();
	for (int i = 0;i<aRobot.size(); i++) {

	     //print from fist space station
		std::cout << "print form station 1 ";
		std::cout<< i+1 << ". ";
		aRobot.at(i)->checkSpaceStation();

	}




	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



}
