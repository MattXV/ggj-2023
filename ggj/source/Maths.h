#pragma once
#include <algorithm> // this gives us std::max()
#include <cmath>     // std::sqrt()

class vec2 {
public:
	vec2(float _x, float _y) : x(_x), y(_y) {}
	vec2(const vec2& otherVec2) : x(otherVec2.x), y(otherVec2.y) {}     // Copy constructor

	// Define what happens when we do vec2 + vec2
	vec2 operator+(const vec2& other) const;

	// Define what happens when we do vec2 + vec2
	vec2 operator-(const vec2& other) const;

	// Define what happens when we do vec2 * float
	vec2 operator*(const float& scalar) const;

	float dot(const vec2& other) const;
	vec2 reflect(const vec2& normal) const;
	float distance(const vec2& other) const;

	vec2 normalise() const;
	float x, y;
private:
};


class ray {
public:
	ray(vec2 _origin, vec2 _direction);
	ray(const ray& otherRay);	// Copy constructor

	vec2 GetPoint(float distance);

	vec2 GetOrigin() const { return origin; }
	vec2 GetDirection() const { return direction; }
	void SetOrigin(const vec2& newOrigin) { origin = newOrigin; }
	void SetDirection(const vec2& newDirection) { direction = newDirection; }

private:
	vec2 origin;
	vec2 direction;
};