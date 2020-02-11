#include "Path.h"

Path::Path() {
	radius = 50;
	points = std::vector<Vector2>();
}

void Path::AddPoint(Vector2 vector) {
	points.push_back(vector);
}

std::vector<Vector2> Path::GetPoints() {
	return points;
}

float Path::GetRadius() {
	return radius;
}

Path::~Path() {
}
