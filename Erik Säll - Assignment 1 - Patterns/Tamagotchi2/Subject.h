#pragma once
#include "Observer.h"
#include <vector>
#include <memory>

class Observer;

class Subject
{
private:
	std::vector<std::shared_ptr<Observer>> _observers;
protected:
	Subject();
public:
	~Subject();
	void AddObserver(std::shared_ptr<Observer> observer);
	void RemoveObserver(std::shared_ptr<Observer> observer);
	void NotifyObservers();
};

