#include "GameStateManager.h"
#include <iostream>

GameStateManager::GameStateManager() {
	platform = new Platform("Match4!");
}

void GameStateManager::GameLoop() {
	//Infinite loop
	while (true) {
		try {
			//if there are no states in the stack 
			if (states.getSize() == 0) {	
				//Throw an error
				throw std::exception("Error");	
			}
			//Take the state that is on top of the stack
			auto state = states.first->data;
			//Check for an event
			platform->CheckEvent(state, &GameState::Input);
			//Update the current state
			state->Update();
			//Draw the current state
			state->Draw();

		}
		catch (...) {
			//Error ocurred and close window
			std::cout << "Critical error, program is closing...";
			//Quit the gameloop
			break;
		}
	}
}

void GameStateManager::SetState(GameState* state) {
	//Initialize current state
	state->Init(platform, this);
	//Push the state to the states stack
	states.push(state);
}

void GameStateManager::RealaseState() {
	//Take the state that is at the top of the stack
	auto state = states.first->data;
	//Close the current state
	state->Close();
	//Pop it from the stack
	states.pop();
}

GameStateManager::~GameStateManager() {
}