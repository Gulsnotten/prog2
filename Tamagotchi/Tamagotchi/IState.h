#pragma once
class IState
{
public:
	IState();
	~IState();

	virtual void Enter();
	virtual void Exit();
	virtual bool Update();
	virtual IState NextState();
	virtual ExitAction getExitAction();
};

enum ExitAction { change, push, revert };