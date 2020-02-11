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
	agentP->Init(600, 600, platform);
}

void Menu::Draw() {
	platform->RenderClear();
	agent->Draw();
	//agentP->Draw();
	/*platform->DrawLine(0,0, i+i,i*i,0xff,0xff,0x00);*/
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
	agent->Seek(agent->PathFollowing());
	/*agentP->Update();
	agentP->Pursuit(*agent);*/
	target->Update();
}

void Menu::Close() {
}

Menu::~Menu() {
}