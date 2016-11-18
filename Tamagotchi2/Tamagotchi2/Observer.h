#pragma once
#include "Subject.h"

class Subject;

class Observer
{
protected:
	Observer();
public:
	virtual ~Observer();
	virtual void Notify(Subject* subject) = 0;
};

