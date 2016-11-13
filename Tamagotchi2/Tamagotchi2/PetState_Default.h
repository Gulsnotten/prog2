#pragma once
#include "PetState.h"
#include "AbstractFactory.h"

enum Action { play, meal, treat, wash };

class PetState_Default : public PetState
{
	void PrintWashMsg();
	static const std::vector<std::string> CHOICES;
protected:
	std::unique_ptr<AbstractFactory> _foodFactoryPtr;

	virtual void DoFeed(Action action);
	virtual void Feed(Action action) = 0;
	virtual void Wash();
	virtual void Play() = 0;

	void Interact();
public:
	PetState_Default(AbstractFactory* factoryPtr);
	~PetState_Default();
};

