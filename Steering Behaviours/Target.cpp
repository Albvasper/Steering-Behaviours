#include "Target.h"

Target::Target() {
}

void Target::Init(Platform* _platform) {
	platform = _platform;
}

void Target::Update() {
	position = Vector2(float(platform->GetMouseX()), float (platform->GetMouseY()));
}

Vector2 Target::GetPos() {
	return position;
}

Target::~Target() {
}
