base class
	derived class


FSM pattern:
	StateMachine.h // is a Pushdown automata
	Istate.h
		PDA_State.h
			PetState.h
				PetState_Dead.h
				PetState_Sleep.h
				PetState_Default.h
					PetState_Idle.h
					PetState_Sick.h

Observer pattern
	I did not utilize the ObserverCenter pattern, but did the simpler pattern where the subject keeps its observers in its own vector.

	PetGame.h // The subject is assigned an observer
	Observer.h
	Subject.h

	StateMachine is an Observer
	DayNightCycle is a Subject

Abstract Factory pattern
	AbstractFactory.h
		Factory_HealthyFood.h
		Factory_SickFood.h

	PetState_Idle has a Factory_HealthyFood.h as a member variable
	PetState_Sick has a Factory_SickFood.h as a member variable

	AbstractProduct.h
		Food_Jalapeno.h // healthy
		Food_Pizza.h // healthy
		Food_Soup.h // sick
		Food_Pill.h // sick