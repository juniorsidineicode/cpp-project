#include <iostream>
#include "ClockCalendar.h"

using namespace std;

ClockCalendar::ClockCalendar (unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM)
	: Clock (hour, min, sec, isPM), Calendar (year, month, day) {

}

ClockCalendar::~ClockCalendar () { }

void ClockCalendar::advance () {
	bool wasPm = Clock::isPM; // save current pm.
	Clock::advance();
	if ((wasPm == true) && (Clock::isPM == false))
		Calendar::advance();
}

