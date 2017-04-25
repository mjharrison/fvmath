#include "x86intrin.h"
#include "fvmath.hpp"


class Vector
{
	private:
	__m128 mData;
	static bool SSE;
	static bool SSE2;
	static bool SSE3;
	static bool SSE4;
	static bool AVX;

	public:
	Vector();
	Vector(_m128 data);
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
}
