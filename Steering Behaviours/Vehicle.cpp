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
	pathDir = 1;
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
	if (distance < 100) {
		desired = desired.normalize(desired);
		desired = desired.mult(desired, int(maxSpeed));
		desired = desired.mult(desired, int(distance / 100));
	}
	else {
		desired = desired.normalize(desired);
		desired = desired.mult(desired, maxSpeed);
	}
	Vector2 steer = steer.sub(desired, velocity);
	ApplyForce(steer);

}

void Vehicle::Pursuit(Vehicle target) {
	float distance = Distance(target.GetPos(), position);	
	float ahead = distance / maxSpeed;
	Vector2 futurePosition;
	futurePosition = futurePosition.add(target.GetPos(), target.GetVel());
	futurePosition = futurePosition.mult(futurePosition, int(ahead));
	Seek(futurePosition);
}

void Vehicle::Evade(Vehicle target) {
	float distance = Distance(target.GetPos(), position);
	float ahead = distance / 10;
	Vector2 futurePosition = velocity;
	futurePosition = futurePosition.add(target.GetPos(), target.GetVel());
	futurePosition = futurePosition.mult(futurePosition, ahead);
	Flee(futurePosition);
}

Vector2 Vehicle::PathFollowing() {
	path = new Path();
	path->AddPoint(Vector2(50, 500));
	path->AddPoint(Vector2(400, 100));
	path->AddPoint(Vector2(800, 800));
	path->AddPoint(Vector2(1200, 600));
	Vector2 target;
	if (path != nullptr) {
		std::vector<Vector2> points = path->GetPoints();
		target = points[currentPoint];
		if (Distance(position, target) <= path->GetRadius()) {
			currentPoint += pathDir;
			if (currentPoint >= points.size() || currentPoint < 0) {
				pathDir *= -1;
				currentPoint += pathDir;
			}
		}
	}
	return target;
}

void Vehicle::ApplyForce (Vector2 v) {
	acceleration = acceleration.add(v, acceleration);
}

Vector2 Vehicle::GetPos() {
	return position;
}

Vector2 Vehicle::GetVel() {
	return velocity;
}

void Vehicle::Update() {
	velocity = velocity.add(velocity, acceleration);
	//velocity = velocity.limit(maxSpeed);
	position = position.add(position, velocity);
	acceleration = acceleration.mult(acceleration, 0);
}

float Vehicle::Distance(Vector2 v1, Vector2 v2) {
	float resultado;
	resultado = sqrt(((v2.GetPosX() - v1.GetPosX()) * (v2.GetPosX() - v1.GetPosX()) + ((v2.GetPosY() - v1.GetPosY()) * v2.GetPosY() - v1.GetPosY())));
	return resultado;
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
