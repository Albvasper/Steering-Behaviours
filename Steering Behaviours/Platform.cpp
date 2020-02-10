#include "Platform.h"
#include <iostream>

SDL_Renderer* Platform::renderer;

Platform::Platform(std::string name) {
	//Window size
	width = 1920;
	height = 1080;

	//SDL window logic
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init";
		return;
	}
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "CreateWindow";
		SDL_Quit();
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "CreateRenderer";
		SDL_Quit();
		return;
	}
}

void Platform::RenderClear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Platform::RenderPresent() {
	SDL_RenderPresent(renderer);
}

void Platform::RenderSprite(Sprite* sprite, int x, int y, float angle) {
	RenderTexture(sprite, x, y, angle);
}

void Platform::RenderTexture(Sprite* sprite, int x, int y, double a) {
	SDL_Rect srcrect;
	srcrect.x = x;
	srcrect.y = y;
	srcrect.w = sprite->GetWidth();
	srcrect.h = sprite->GetHeight();
	SDL_RenderCopyEx(renderer, sprite->GetTexture(), NULL, &srcrect, a, NULL, SDL_FLIP_NONE);
}

void Platform::CheckEvent(GameState* obj, bool (GameState::* f)(int)) {
	//New SDL event called "e"
	SDL_Event e;
	bool leftMouseButtonDown = false;
	while (SDL_PollEvent(&e)) {
		//Allways updates the mouse position
		mouseX = e.motion.x;
		mouseY = e.motion.y;
		if (e.type == SDL_KEYDOWN) {
			(obj->*f)(e.key.keysym.sym);
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				leftMouseButtonDown = false;
				//std::cout << "arriba" << std::endl;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				leftMouseButtonDown = true;
				//std::cout << "abajo" << std::endl;
			}
		}
	}
}

int Platform::GetMouseX() {
	return mouseX;
}

int Platform::GetMouseY() {
	return mouseY;
}

Platform::~Platform() {
}

void  Platform::DrawLine(float x, float y, float x1, float y1, int R, int B, int G)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, 0xff);
	SDL_RenderDrawLine(renderer, x, y, x1, y1);
}