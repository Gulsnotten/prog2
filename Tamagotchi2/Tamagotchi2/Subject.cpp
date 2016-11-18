#include "Subject.h"



Subject::Subject()
{
}


Subject::~Subject()
{
}

void Subject::AddObserver(std::shared_ptr<Observer> observer)
{
	_observers.push_back(observer);
}

void Subject::RemoveObserver(std::shared_ptr<Observer> observer)
{
	for (unsigned int i = 0; i < _observers.size(); i++) {
		if (_observers[i] == observer) {
			_observers[i] = _observers[_observers.size() - 1];
			_observers.pop_back();
			return;
		}
	}
}

void Subject::NotifyObservers()
{
	for (auto o : _observers) {
		o->Notify(this);
	}
}
