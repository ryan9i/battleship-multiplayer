#ifndef PT_BOAT_H_
#define PT_BOAT_H__H_
using namespace std;

class ptBoat
{
	public:
		void location (int x_input, int y_input, bool horizontal);
		bool hit (int targetx, int targety);
		void checkDamage();
		bool getSunk();
	private:
		int x,y;
		bool damage[2],horizontal,sunk;
};
#endif PT_BOAT_H_