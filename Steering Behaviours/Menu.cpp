#include "Menu.h"
#include<iostream>

Menu::Menu() {
}

void Menu::Init(Platform* platform, GameStateManager* manager) {
	this->platform = platform;
	this->manager = manager;
	seek = new Vehicle();
	target = Vector2(50, 50);
	seek->Init(50, 50, platform);
	seek->Seek(target);
}

void Menu::Draw() {
	platform->RenderClear();
	seek->Draw(50, 50);
	platform->RenderPresent();
}

bool Menu::Input(int keyInput) {
	//If ENTER is pressed
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
	seek->Update();
}

void Menu::Close() {
}

Menu::~Menu() {
}