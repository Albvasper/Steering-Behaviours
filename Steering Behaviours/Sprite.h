#pragma once
#include "SDL.h"
#include <iostream>
#include "GameObject.h"

class Sprite : public GameObject {
	
	private:
		SDL_Texture* sprite;
		std::string name;
		unsigned short width;
		unsigned short height;

	public:
		Sprite();
		void LoadImage(std::string name);
		SDL_Texture* GetTexture();
		int GetWidth();
		int GetHeight();
		~Sprite();
};

