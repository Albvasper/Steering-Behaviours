#pragma once
#include "Vector2.h"
#include "GameObject.h"
#include "Platform.h"

class Target : GameObject{

	private: 
		Vector2 position;
		Platform* platform;

	public:
		Target();
		void Init(Platform* _platform);
		void Update();
		Vector2 GetPos();
		~Target();
};

