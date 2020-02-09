#include "Vehicle.h"


Vehicle::Vehicle(float x, float y) {
	position = Vector2(x, y);
	acceleration = Vector2(0,0);
	velocity = Vector2(0,-2);
	r = 6;
	maxSpeed = 4;
	maxForce = 2;
}

void Vehicle::seek(Vector2 _target) {
	Vector2 desired = desired.sub(_target, position);

	desired = desired.normalize(desired);
	desired = desired.mult(desired, maxSpeed);
	Vector2 steer = steer.sub(desired, velocity);
	applyForce(steer);
}

void Vehicle::applyForce(Vector2 v) {
	acceleration = acceleration.add(v, acceleration);
}

void Vehicle::Update() {
	velocity = velocity.add(velocity, acceleration);
	//velocity = velocity.limit(maxSpeed);
	position = position.add(position, velocity);
	acceleration = acceleration.mult(acceleration, 0);
}
