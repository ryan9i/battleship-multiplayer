#ifndef BATTLESHIP_H_
#define BATTLESHIP_H__H_
using namespace std;

class battleship
{
	public:
		void location (int x_input, int y_input, bool horizontal);
		bool hit (int targetx, int targety);
		void checkDamage();
		bool getSunk();
	private:
		int x,y;
		bool damage[4],horizontal,sunk;
};
#endif BATTLESHIP_H_