#include "Menu.h"
#include<iostream>

Menu::Menu() {
}

void Menu::Init(Platform* platform, GameStateManager* manager) {
	this->platform = platform;
	this->manager = manager;
	agent = new Vehicle();
	agent->Init(500, 500, platform);
	target = new Target();
	target->Init(platform);
	agentP = new Vehicle();
	agentP->Init(300, 300, platform);
}

void Menu::Draw() {
	platform->RenderClear();
	agent->Draw();
	agentP->Draw();
	platform->RenderPresent();
}

bool Menu::Input(int keyInput) {
	//If ESC is pressed
	if (keyInput == 27) {
		//Quit
		exit(1);
	}
	else {
		//manager->SetState(new Game());
	}
	return false;
}

void Menu::Update() {
	agent->Update();
	agent->Arrival(target->GetPos());
	agentP->Update();
	agentP->Pursuit(*agent);
	target->Update();
}

void Menu::Close() {
}

Menu::~Menu() {
}