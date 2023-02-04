#include "Maths.h"


vec2 vec2::operator+(const vec2& other) const
{
	return vec2(this->x + other.x, this->y + other.y);
}

vec2 vec2::operator-(const vec2& other) const
{
	return vec2(this->x - other.x, this->y - other.y);
}

vec2 vec2::operator*(const float& scalar) const
{
	return vec2(this->x * scalar, this->y * scalar);
}

float vec2::dot(const vec2& other) const
{
	return this->x * other.x + this->y * other.y;
}

float vec2::distance(const vec2& other) const
{
	return std::sqrt(std::pow(this->x - other.x, 2) + std::pow(this->y - other.y, 2));
}

vec2 vec2::reflect(const vec2& normal) const
{
	vec2 reflectionNormal = (normal * this->dot(normal)) * 2.0f;
	vec2 reflection = *this - reflectionNormal;
	return reflection;
}


vec2 vec2::normalise() const
{


	float max = std::max(std::abs(x), std::abs(y));
	float newX = x / max;
	float newY = y / max;

	return vec2(newX, newY);
}

ray::ray(vec2 _origin, vec2 _direction) :
	origin(_origin),
	direction(_direction)
{
}

ray::ray(const ray& otherRay) :
	origin(otherRay.origin),
	direction(otherRay.direction)
{
}

vec2 ray::GetPoint(float distance)
{
	// Equation for a point 'r(t)' along a ray 'r', with distance 't' from the origin 'o'
	// where 'd' is the direction of the vector
	// r(t) = o + t * d

	//vec2 normalisedDirection = direction.normalise();
	vec2 dir = direction * distance;
	vec2 point = origin + dir;
	return point;
}