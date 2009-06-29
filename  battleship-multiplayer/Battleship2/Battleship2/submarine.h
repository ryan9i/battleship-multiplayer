#ifndef SUBMARINE_H_
#define SUBMARINE_H__H_
using namespace std;

class submarine
{
	public:
		void location (int x_input, int y_input, bool horizontal);
		bool hit (int targetx, int targety);
		void checkDamage();
		bool getSunk();
	private:
		int x,y;
		bool damage[3],horizontal,sunk;
};
#endif SUBMARINE_H_