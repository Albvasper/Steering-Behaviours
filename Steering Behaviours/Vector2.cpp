#include "Vector2.h"


Vector2::Vector2(float _x, float _y) {
	x = _x;
	y = _y;
}

Vector2 Vector2::normalize(Vector2 v)
{
	double tam;
	Vector2 resultado;
	tam = sqrt((v.x * v.x) + (v.y * v.y));
	resultado = Vector2(v.x/tam,v.y/tam);
	return resultado;
}

Vector2 Vector2::sub(Vector2 _f, Vector2 _l)
{
	Vector2 resultado(_f.x - _l.x, _f.y - _l.y);

	return resultado;
}

Vector2 Vector2::add(Vector2 _f, Vector2 _l)
{
	Vector2 resultado(_f.x + _l.x, _f.y + _l.y);

	return resultado;
}

Vector2 Vector2::mult(Vector2 v, int n)
{
	Vector2 resultado(v.x*n,v.y*n);	
	return resultado;
}

Vector2 Vector2::limit(Vector2 v, int n)
{
	
	return v;
}

Vector2 Vector2::setMag(float n)
{

	return Vector2();
}

float Vector2::Mag(Vector2 v) {
	
	return (float)sqrt((v.x * v.x) + (v.y * v.y));
	/*x = pow(x, 2);
	y = pow(y, 2);
	float result = x + y;
	result = sqrt(result);
	return result;*/
}

float Vector2::GetPosX() {
	return x;
}

float Vector2::GetPosY() {
	return y;
}

