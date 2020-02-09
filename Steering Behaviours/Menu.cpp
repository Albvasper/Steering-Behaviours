#include "Menu.h"
#include<iostream>

Menu::Menu() {
}

void Menu::Init(Platform* platform, GameStateManager* manager) {
	this->platform = platform;
	this->manager = manager;
	agent = new Vehicle();
	target = Vector2(20, 52);
	agent->Init(500, 510, platform);
	agent->Seek(target);
}

void Menu::Draw() {
	platform->RenderClear();
	agent->Draw(agent->GetPosX(), agent->GetPosY());
	platform->RenderPresent();
}

bool Menu::Input(int keyInput) {
	//If ENTER is pressed
	if (keyInput == 27) {
		//Quittt
		exit(1);
	}
	else {
		//manager->SetState(new Game());
	}
	return false;
}

void Menu::Update() {
	agent->Update();
}

void Menu::Close() {
}

Menu::~Menu() {
}