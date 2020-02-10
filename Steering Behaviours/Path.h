#pragma once
#include "Vector2.h"
#include <vector>

class Path {

	private:
		std::vector<Vector2> points;
		float radius;

	public:
		Path();
		~Path();
};

