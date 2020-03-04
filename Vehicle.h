#ifndef _VEHICLE_H_
#define _VEHICLE_H_

using namespace std;

class Vehicle(){
	protected:
		float m_lla[3];
		const int m_vin;
	private:
		static int s_idgen;
	public:
		Vehicle();
		Vehicle(const int m_vin, float *m_lla);
		Vehicle(const Vehicle& V);
		~Vehicle();
		Vehicle& operator=(const Vehicle& V);
		float *get_lla();
		int get_vin() const;
		static int get_idgen();
		bool set_lla(float *m_lla);
		void set_vin(const int m_vin);
		void set_idgen(static int s_idgen);
		void move(float *m_lla);
		friend ostream& operator<<(ostream& os, const Vehicle& V);
		
};

#endif
