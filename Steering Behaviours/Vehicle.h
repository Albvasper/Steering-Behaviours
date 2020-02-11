#pragma once
#include <vector>
#include "GameObject.h"
#include "Vector2.h"
#include "Sprite.h"
#include "Platform.h"
#include <math.h>
#include "SDL.h"
#include "Path.h"

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
		Path* path;
		int currentPoint;
		int pathDir;

	public:
		Vehicle();
		void Init(float x, float y, Platform* _platform);
		void Seek(Vector2 _target);
		void Flee(Vector2 _target);
		void Arrival(Vector2 _target);
		void Pursuit(Vehicle target);
		void Evade(Vehicle target);
		Vector2 PathFollowing();
		float Distance(Vector2 v1, Vector2 v2);
		void ApplyForce(Vector2 v);
		Vector2 GetPos();
		Vector2 GetVel();
		void Update();
		void Draw();
		int GetPosX();
		int GetPosY();
};

