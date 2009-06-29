#ifndef DESTROYER_H_
#define DESTROYER_H__H_
using namespace std;

class destroyer
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
#endif DESTROYER_H_