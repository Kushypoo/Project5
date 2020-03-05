#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>
#include <cstring>


using namespace std;

class Vehicle{
	protected:
		float m_lla[3];
		const int m_vin;
	private:
		static int s_idgen;
		static int s_deleted[256];
	public:
		Vehicle();
		Vehicle(const int m_vin, const float *m_lla);
		Vehicle(const Vehicle& V);
		~Vehicle();
		void operator=(const Vehicle V);
		const float *get_lla() const;
		const int get_vin() const;
		static const int getIdgen();
		void set_lla(const float *lla);
		void move(const float *lla);
		static int availableVin(const int vin);
		friend std::ostream & operator<<(ostream& os, const Vehicle& V);
		
};

#endif
