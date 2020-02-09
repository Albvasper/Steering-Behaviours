#pragma once
#include <vector>
#include "GameObject.h"
#include "Vector2.h"

class Vehicle : GameObject {
	private:
		/*std::vector<int> position;
		std::vector<int> velocity;
		std::vector<int> acceleration;*/	
		Vector2 position;
		Vector2 velocity;
		Vector2 acceleration;
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
		Vehicle(){}
		Vehicle(float x, float y);
		void seek(Vector2 _target);
		void applyForce(Vector2 v);
		void Update();
};

