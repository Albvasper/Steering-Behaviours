#pragma once
#include <vector>
#include "GameObject.h"
#include "Vector2.h"
#include "Sprite.h"
#include "Platform.h"

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
		Platform* platform;
		Sprite* sprite;

	public:
		Vehicle();
		void Init(float x, float y, Platform* _platform);
		void Seek(Vector2 _target);
		void Evading(Vector2 _target);
		void ApplyForce(Vector2 v);
		void Update();
		void Draw();
		int GetPosX();
		int GetPosY();
};

