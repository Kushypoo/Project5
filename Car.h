#ifndef _CAR_H_
#define _CAR_H_

#include "Vehicle.h"

class Car : public Vehicle(){
	private:
		char m_plates[256];
		int m_throttle;
	public:
		Car(); //set m_throttle = 0, leave rest uninitialized
		//this needs to get the m_lla value of the parent class Vehicle. Figure it out.
		/* NOT DONE*/ Car(const char *plates, const int throttle, float *lla); //m_throttle = 0, access the vehicle class m_lla values passed by address
		Car(const Car&);
		~Car();
		friend ostream& operator<<(ostream& os, Car& C);
		Car& operator=(const Car& C);
		char *getPlates();
		int getThrottle() const;
		bool setPlates(const char *plates);
		int setThrottle(const int throttle);
		bool Drive(int throttle);
		void Move(float *lla);
};

#endif
