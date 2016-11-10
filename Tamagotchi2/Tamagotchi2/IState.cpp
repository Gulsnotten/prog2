#include "IState.h"



IState::IState()
{
}


IState::~IState()
{
}

bool IState::Update() {
	return true;
}
void IState::Enter() {

}
void IState::Exit() {

}
IState* IState::NextState() const{
	return new IState();
}