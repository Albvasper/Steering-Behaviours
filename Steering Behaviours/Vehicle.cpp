#include "Vehicle.h"

Vehicle::Vehicle() {
}

void Vehicle::Init(float x, float y, Platform* _platform) {
	platform = _platform;
	sprite = new Sprite();
	sprite->LoadImage("../Assets/Sprites/vehicle.png");
	position = Vector2(x, y);
	acceleration = Vector2(0,0);
	velocity = Vector2(0,-2);
	r = 6;
	maxSpeed = 4;
	maxForce = 2;
}

void Vehicle::Seek(Vector2 _target) {
	Vector2 desired = desired.sub(_target, position);
	desired = desired.normalize(desired);
	desired = desired.mult(desired, maxSpeed);
	Vector2 steer = steer.sub(desired, velocity);
	ApplyForce(steer);
}

void Vehicle::Flee(Vector2 _target) {
	Vector2 desired = desired.sub(position, _target);
	desired = desired.normalize(desired);
	desired = desired.mult(desired, maxSpeed);
	Vector2 steer = steer.sub(desired, velocity);
	ApplyForce(steer);
}

void Vehicle::Arrival(Vector2 _target) {
	Vector2 desired = desired.sub(_target, position);
	float distance = desired.Mag(desired);
	//loat var = distance / 100;
	if (distance < 100) {
		desired = desired.normalize(desired);
		desired = desired.mult(desired, maxSpeed);
		desired = desired.mult(desired, distance/100);
	}
	else{
		desired = desired.normalize(desired);
		desired = desired.mult(desired, maxSpeed);
		//steer = steer.sub(desired, velocity);
	}
	
	Vector2 steer = steer.sub(desired, velocity);
	ApplyForce(steer);

}

void Vehicle::ApplyForce(Vector2 v) {
	acceleration = acceleration.add(v, acceleration);
}

void Vehicle::Update() {
	velocity = velocity.add(velocity, acceleration);
	//velocity = velocity.limit(maxSpeed);
	position = position.add(position, velocity);
	acceleration = acceleration.mult(acceleration, 0);
}

void Vehicle::Draw() {
	platform->RenderSprite(sprite, position.GetPosX() - 32, position.GetPosY() - 32 , 0);
}

int Vehicle::GetPosX() {
	return posX;
}

int Vehicle::GetPosY() {
	return posY;
}
