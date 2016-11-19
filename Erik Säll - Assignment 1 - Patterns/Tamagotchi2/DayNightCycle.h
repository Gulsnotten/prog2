#pragma once
#include "Subject.h"
#include "Printable.h"

enum TimeState {day, night};

class DayNightCycle : public Subject, public Printable
{
	static const int _DAY_HOURS;
	static const int _NIGHT_HOURS;
	static const int _TOTAL_HOURS;

	int _hour;
public:
	DayNightCycle();
	~DayNightCycle();

	TimeState GetTime() const;

	void Update();
};

