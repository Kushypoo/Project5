#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;


void Vehicle::operator=(const Vehicle &V){
	m_lla = V.m_lla;
	m_vin = V.m_vin;
	s_idgen = V.s_idgen;
}



/* STILL NEED ALL THE CONSTRUCTORS FOR CAR AND VEHICLE, AND THE 

int main(){
	
}
