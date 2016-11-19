#pragma once
#include "PDA_State.h"
#include "PetInterface.h"
#include <memory>
#include <string>
#include <vector>
#include "Printable.h"

class PetState : public PDA_State, public Printable
{
protected:
	std::shared_ptr<PetInterface> _petInterfacePtr;

	int GetChoice(const std::vector<std::string> choices) const;
	int getInputInt(int min, int max) const;
public:
	PetState();
	~PetState();

	virtual bool Update();
	virtual void Enter(std::shared_ptr<PetInterface> _ptr);
	virtual void Exit();
	SwitchType GetSwitchType() const;

	PetState* NextState() const;
};