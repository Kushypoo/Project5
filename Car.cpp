#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

Car::Car(): m_throttle(0) {
	std::cout << "Car #" << this->get_vin() << ": Default-ctor" << std::endl;
}
Car::Car(const char *plates, const int vin, const float *lla): Vehicle(vin, lla) {
	this->setPlates(plates);
	std::cout << "Car #" << this->get_vin() << ": Parameterized-ctor" << std::endl;
}
Car::Car(const Car &C): Vehicle(C) {
	setPlates(C.getPlates());
	std::cout << "Car #" << this->get_vin() << ": Copy-ctor" << std::endl;
}
Car::~Car(){
	std::cout << "Car #" << this->get_vin() << ": Destructor-dtor" << std::endl;
}
void Car::setThrottle(const int throttle){
	m_throttle = throttle;
}
void Car::setPlates(const char *plates){
	strcpy(m_plates, plates);
}
const int Car::getThrottle() const{
	return m_throttle;
}
const char *Car::getPlates() const{
	return m_plates;
}
const int Car::getIdgen(){
	return Vehicle::getIdgen();
}
void Car::move(const float *lla){
	std::cout << "Car #" << this->get_vin() << "DRIVE to destination, with throttle @ 75 " << std::endl;
	this->drive(75);
	this->set_lla(lla);
}
void Car::drive(const int throttle){
	this->setThrottle(throttle);
}
std::ostream & operator<<(std::ostream & os, const Car & C){

	const float *lla = C.get_lla();
	
	os << "Car #" << C.get_vin() << " Plates: " << C.getPlates() << ", Throttle: " << C.getThrottle() << " @ [" << *lla << ", " << std::endl;
	++lla;
	os << *lla << ", ";
	++lla;
	os << *lla << "]" << std::endl;
	
	return os;
}
