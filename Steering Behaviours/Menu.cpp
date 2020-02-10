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
}

void Menu::Draw() {
	platform->RenderClear();
	agent->Draw();
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
	agent->Flee(target->GetPos());
	target->Update();
}

void Menu::Close() {
}

Menu::~Menu() {
}