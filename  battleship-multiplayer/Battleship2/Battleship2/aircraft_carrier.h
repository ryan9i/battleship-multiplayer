#ifndef AIRCRAFT_CARRIER_H_
#define AIRCRAFT_CARRIER_H_
using namespace std;

class aircraft_carrier
{
	public:
		void location (int x_input, int y_input, bool horizontal);
		bool hit (int targetx, int targety);
		void checkDamage();
		bool getSunk();
	private:
		int x,y;
		bool damage[5],horizontal,sunk;
};
#endif AIRCRAFT_CARRIER_H_