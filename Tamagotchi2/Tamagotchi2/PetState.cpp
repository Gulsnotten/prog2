#include "PetState.h"



PetState::PetState() : _petInterfacePtr(nullptr)
{
}


PetState::~PetState()
{
}


int PetState::GetChoice(const std::vector<std::string> choices) const {
	int index = 0;
	PrintLn("(write the number of your choice)");
	for (auto c : choices) {
		index++;
		PrintLn(std::to_string(index) + " : " + c);
	}

	return getInputInt(1, choices.size()) - 1;
}

int PetState::getInputInt(int min, int max) const {
	int result;
	while (!(std::cin >> result) || !(result >= min && result <= max)) {
		std::cout << "OOPS! Please enter a NUMBER between " << min << "-" << max << "\n";

		if (!std::cin) {
			std::cin.clear();
			std::string temp;
			std::cin >> temp;
		}
	}

	return result;
}

void PetState::Enter(std::shared_ptr<PetInterface> _ptr) {
	_petInterfacePtr = _ptr;
}

SwitchType PetState::GetSwitchType() const {
	return SwitchType::error;
}


PetState* PetState::NextState() const {
	return new PetState();
}