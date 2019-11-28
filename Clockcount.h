#include "ClockCalendar.h"

class ClockCount{

private:
	static ClockCount *instance;
	ClockCount();
	void *contador(void *pointer);

public:
	static ClockCount *takeinstance();
	ClockCalendar *calendar = new ClockCalendar(2019, 11, 28, 1, 0, 0, true);


};