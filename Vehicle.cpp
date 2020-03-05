#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;

int Vehicle::s_idgen = 1;
int Vehicle::s_deleted[256] = {0};

Vehicle::Vehicle() : m_vin(s_idgen) {
	std::cout << "Vehicle #" << this->get_vin() << ": Default-ctor" << std::endl;
	s_idgen++;
}
Vehicle::Vehicle(const int m_vin, const float *m_lla): m_vin(availableVin(m_vin)) {
	set_lla(m_lla);
	std::cout << "Vehicle #" << this->get_vin() << ": Paramaterized-ctor" << std::endl;
}
Vehicle::~Vehicle(){
	for(int i = 0; s_deleted[i+1]; i++){
		if(!s_deleted[i]){
			s_deleted[i] = this->get_vin();
		}
	}
}
void Vehicle::set_lla(const float *lla){
	m_lla[0] = lla[0];
	m_lla[1] = lla[1];
	m_lla[2] = lla[2];
}
const int Vehicle::get_vin() const{
	return this->m_vin;
}
const float *Vehicle::get_lla() const{
	return this->m_lla;
}
const int Vehicle::getIdgen(){
	return s_idgen;
}

int Vehicle::availableVin(const int vin){
	for(int i = 0; i < 256; i++){
		if(s_deleted[i]){
			int available_vin = s_deleted[i];
			s_deleted[i] = 0;
			return available_vin;
		}
	}
	
	if(vin > s_idgen){
		return vin;
	}else{
		s_idgen++;
		return s_idgen;
	}
}
std::ostream & operator<<(std::ostream & os, const Vehicle & V){
	os << "Vehicle ##" << V.m_vin << " @ [" << V.m_lla[0] << ", " << V.m_lla[1] << ", " << V.m_lla[2] << "]" << std::endl;
	return os;
}
void Vehicle::operator=(const Vehicle V){
	this->set_lla(V.get_lla());
}
void Vehicle::move(const float *lla){
	std::cout << "Vehicle #" << this->get_vin() << ": CANNOT MOVE- I DON'T KNOW HOW" << std::endl;
}
