#ifndef NAVY_H_
#define NAVY_H_
#include "aircraft_carrier.h"
#include "battleship.h"
#include "submarine.h"
#include "destroyer.h"
#include "pt_boat.h"

using namespace std;

class navy
{
	public:
		aircraft_carrier aircraftCarrier;
		battleship battleship;
		submarine submarine;
		destroyer destroyer;
		ptBoat ptboat;
		void nothing();
	private:

};
#endif NAVY_H_