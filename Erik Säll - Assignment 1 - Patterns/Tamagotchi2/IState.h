#pragma once
class IState
{
public:
	IState();
	~IState();

	virtual bool Update() = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual IState* NextState() const = 0;
};

