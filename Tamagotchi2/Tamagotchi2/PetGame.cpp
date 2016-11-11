#include "PetGame.h"



PetGame::PetGame()
{
}


PetGame::~PetGame()
{
}



void PetGame::Run() {
	std::srand(std::time(0));

	while (true) {
		StateMachine* pet = PetFactory::CreatePet();
		while (pet->Update()) {
			
		}
		delete pet;
	}
}