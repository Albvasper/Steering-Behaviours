#pragma once
#include <vector>
#include "GameObject.h"

class Vehicle : GameObject {
	private:
		/*std::vector<int> position;
		std::vector<int> velocity;
		std::vector<int> acceleration;*/
		int posX;
		int posY;
		int velX;
		int velY;
		int accX;
		int accY;
		float r;
		float maxSpeed;
		float maxForce;
		int targetX;
		int targetY;

	public:
		Vehicle(float x, float y);
		void Update();
};

