#include <iostream>
#include "x86intrin.h"
#include "fvmath.hpp"


class Vector
{
	private:
	__m128 mData;

	public:
	Vector();
	Vector(__m128 data);
	Vector(const float array[]);
	~Vector();

	float x();
	float y();
	float z();
	float w();
	float len();
	Vector unit();
	float dotproduct(const Vector &op);
	Vector projection(const Vector &op);

	Vector operator=(const Vector &op);
	Vector operator+(const Vector &op);
	Vector operator-(const Vector &op);
	Vector operator*(const float &op);
	Vector operator/(const float &op);

	friend std::ostream &operator<<(std::ostream os, const Vector &v);
};
