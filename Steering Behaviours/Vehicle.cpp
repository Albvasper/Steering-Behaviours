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
 		Vector2 vec(desired.GetPosX() * maxSpeed * (distance / 100), desired.GetPosY() * maxSpeed * (distance / 100));
		velocity = vec;
		position = Vector2(position.GetPosX() + velocity.GetPosX(), position.GetPosY() + velocity.GetPosY());
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

void Vehicle::Interpose(Vehicle* v1, Vehicle* v2) {
	Vector2 v1Future = v1Future.add(v1->GetPos(), v1->GetVel());
	Vector2 v2Future = v1Future.add(v2->GetPos(), v2->GetVel());
	v1Future = v1Future.mult(v1Future, 1.5f);
	v2Future = v2Future.mult(v2Future, 1.5f);
	float ekis = (v1Future.GetPosX() + v2Future.GetPosX()) / 2;
	float ye = (v1Future.GetPosY() + v2Future.GetPosY()) / 2;
	Vector2 mid = Vector2(ekis, ye);
	Seek(mid);
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
