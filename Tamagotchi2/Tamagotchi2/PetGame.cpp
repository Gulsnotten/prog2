#include "PetGame.h"



PetGame::PetGame()
{
}


PetGame::~PetGame()
{
}



void PetGame::Run() {
	std::srand(int(std::time(0)));

	while (true) {
		StateMachine* ptr = PetFactory::CreatePet();
		std::shared_ptr<StateMachine> pet = std::shared_ptr<StateMachine>(ptr);
		DayNightCycle dnc;
		dnc.AddObserver(pet);
		while (pet->Update()) {
			dnc.Update();
		}
	}
}