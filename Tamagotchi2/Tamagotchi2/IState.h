#pragma once
class IState
{
public:
	IState();
	~IState();

	virtual bool Update();
	virtual void Enter();
	virtual void Exit();
	virtual IState* NextState() const;
};

