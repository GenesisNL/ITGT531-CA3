#include "SpaceStation.hpp"

#include <iostream>
#include "Robot.hpp"

SpaceStation::SpaceStation() :
	m_x(0), m_y(0), m_z(0)
{
}

SpaceStation::SpaceStation(float pos_x, float pos_y, float pos_z) :

	m_x(pos_x), m_y(pos_y), m_z(pos_z)
{


}

SpaceStation::SpaceStation(const std::shared_ptr<SpaceStation> t_station) :

	m_x(t_station->m_x), m_y(t_station->m_y), m_z(t_station->m_z),m_robot(t_station->m_robot)
{
	

}

SpaceStation::~SpaceStation()
{
}

void SpaceStation::init()
{
	m_robot.push_back(std::make_shared<Robot>());

	//m_robot = std::make_shared<Robot>();

	// shared_from_this requires the object to exist, so
	// it cannot use within intializer.
	m_robot.at(0)->setStation(shared_from_this());

	//m_robot->setStation( shared_from_this() );
}

void SpaceStation::addRobot()
{
	//std::cout << m_robot.size();
	m_robot.push_back(std::make_shared<Robot>());
	//std::cout << m_robot.size();

	m_robot[m_robot.size()-1]->setStation(shared_from_this());
	//std::cout << m_robot.size();

}

void SpaceStation::printStatus() const
{
	std::cout << "x " << m_x << ", y " << m_y << ", z " << m_z << std::endl;

}


std::weak_ptr<Robot> SpaceStation::getRobot() const
{
	
	return m_robot.at(0);

}


std::vector<std::shared_ptr<Robot>> SpaceStation::getAllRobot() const
{

	return m_robot;



}


std::shared_ptr<SpaceStation>SpaceStation::operator = (const std::shared_ptr<SpaceStation> t_station) 
{
	m_x = t_station->m_x;
	m_y = t_station->m_y;
	m_z = t_station->m_z;
	m_robot = t_station->m_robot;

	return shared_from_this();

}
