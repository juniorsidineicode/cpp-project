#include "Clockcount.h"
#include <thread>
#include <iostream>
#include <iomanip>

using namespace std;

ClockCount::ClockCount(){

}


void * ClockCount::contador(void *pointer){
	ClockCalendar* Calendar = static_cast<ClockCalendar*>(pointer);

	unsigned int year, month, day, hour, min, sec;
	bool isPM;

	bool secondAdvanced = false;
	time_t now, elapsed;
	double seconds;

	while (true) {
		secondAdvanced = false;
		time(&now);
		while (!secondAdvanced) {
			time(&elapsed);
			seconds = difftime(elapsed, now);
			if (seconds == 1) {
				secondAdvanced = true;
				Calendar->advance();
				Calendar->readCalendar(year, month, day);
				Calendar->readClock(hour, min, sec, isPM);

			}
		}
	}

	cout.flush ();
	return nullptr;
}

ClockCount* ClockCount::instance = nullptr;

ClockCount* ClockCount::takeinstance(){
	if (ClockCount::instance == nullptr){
		ClockCount::instance = new ClockCount();
		thread ClockThread([&]()
		{
			ClockCount::instance->takeinstance()->contador(static_cast<void*>(ClockCount::instance->takeinstance()->calendar));
		});

		ClockThread.detach();
	}

	return ClockCount::instance;
}



