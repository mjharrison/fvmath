#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "x86intrin.h"
#include "fvmath.hpp"


class Vector
{
	private:
	__m128 mData;
	float get(short i);
	
	public:
	Vector();
	Vector(__m128 data);
	Vector(const float array[]);

	float x();
	float y();
	float z();
	float w();
	float len();
	Vector unit();
	float dot(const Vector &op);
	Vector project(const Vector &op);

	void operator=(const Vector &op);
	Vector operator+(const Vector &op);
	Vector operator-(const Vector &op);
	Vector operator*(const float &op);
	Vector operator/(const float &op);

	friend std::ostream &operator<<(std::ostream &out, const Vector &vector);
};


#endif
