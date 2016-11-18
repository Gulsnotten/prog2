#include "DayNightCycle.h"


const int DayNightCycle::_DAY_HOURS = 4;
const int DayNightCycle::_NIGHT_HOURS = 1;
const int DayNightCycle::_TOTAL_HOURS = DayNightCycle::_DAY_HOURS + DayNightCycle::_NIGHT_HOURS;


DayNightCycle::DayNightCycle() : _hour(0)
{
}


DayNightCycle::~DayNightCycle()
{
}

TimeState DayNightCycle::GetTime() const
{
	if (_hour == _TOTAL_HOURS - 1) {
		return TimeState::night;
	}
	else {
		return TimeState::day;
	}
}

void DayNightCycle::Update()
{
	_hour++;
	if (_hour >= _TOTAL_HOURS) {
		_hour = 0;
	}

	if (_hour == _TOTAL_HOURS - 1 || _hour == 0) {
		if (GetTime() == TimeState::day) {
			PrintLn("The sun is rising.");
			PrintLn();
		}
		else {
			PrintLn();
			PrintLn("The sun is setting.");
		}
		
		NotifyObservers();
	}
}