#pragma once
#include "Subject.h"

class Subject;

class Observer
{
protected:
	Observer();
public:
	virtual ~Observer();
	virtual void Notify(const Subject* subject) = 0;
};

