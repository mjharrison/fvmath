#include "vector.hpp"


float Vector::get(short i)
{
	float array[4];

    _mm_store_ps(array, mData);
    
    return array[i];
}


Vector::Vector()
{
	mData = _mm_xor_ps(mData, mData);
}


Vector::Vector(__m128 data)
{
	mData = data;
}


Vector::Vector(const float array[])
{
	mData = _mm_load_ps(array);
}


float Vector::x()
{
    return get(0);
}


float Vector::y()
{
	return get(1);
}


float Vector::z()
{
	return get(2);
}


float Vector::w()
{
	return get(3);
}


float Vector::len()
{
    __m128 len;
    float out;
    
    len = _fvlen(mData);
    
    _mm_store_ss(&out, len);
	return out;
}


Vector Vector::unit()
{
	return _fvnorm(mData);
}


float Vector::dot(const Vector &op)
{
    __m128 dotp;
    float out;
    
    dotp = _fvdotp(mData, op.mData);

    _mm_store_ss(&out, dotp);
	return out;
}


Vector Vector::project(const Vector &op)
{
	return Vector(_fvproj(mData, op.mData));
}


void Vector::operator=(const Vector &op)
{
	mData = op.mData;
}


Vector Vector::operator+(const Vector &op)
{
	return Vector(_mm_add_ps(mData, op.mData));
}


Vector Vector::operator-(const Vector &op)
{
	return Vector(_mm_sub_ps(mData, op.mData));
}


Vector Vector::operator*(const float &op)
{
    __m128 k = _mm_load_ps1(&op);

	return Vector(_mm_mul_ps(mData, k));
}


Vector Vector::operator/(const float &op)
{
    __m128 k = _mm_load_ps1(&op);

	return Vector(_mm_div_ps(mData, k));
}


std::ostream &operator<<(std::ostream &out, const Vector &vector)
{
	float array[4];
	
	_mm_store_ps(array, vector.mData);

	for (int i = 0; i < 4; i++)
	{
		out << array[i] << " ";
	}
	
	return out;
}
