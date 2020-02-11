#pragma once
#include "Vector2.h"
#include <vector>

class Path {

	private:
		std::vector<Vector2> points;
		float radius;

	public:
		Path();
		void AddPoint(Vector2 vector);
		std::vector<Vector2> GetPoints();
		float GetRadius();
		~Path();
};

