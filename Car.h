#ifndef _CAR_H_
#define _CAR_H_

#include "Vehicle.h"
#include <iostream>
#include <cstring>


class Car : Vehicle{
	private:
		char m_plates[256];
		int m_throttle;
	public:
		Car();
		Car(const char *plates, const int vin, const float *lla);
		Car(const Car&);
		~Car();
		friend std::ostream & operator<<(ostream & os, const Car & C);
		Car& operator=(const Car& C);
		const char *getPlates() const;
		const int getThrottle() const;
		static const int getIdgen();
		void setPlates(const char *plates);
		void setThrottle(const int throttle);
		void drive(const int throttle);
		void move(const float *lla);
};

#endif
