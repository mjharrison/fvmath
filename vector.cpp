Vector::Vector()
{
	mData = _mm_xor_ps(mData, mData);
}


float Vector::x()
{
	return _mm_store_ps(mData)[0];
}


float Vector::y()
{
	return _mm_store_ps(mData)[1];
}


float Vector::z()
{
	return _mm_store_ps(mData)[2];
}


float Vector::w()
{
	return _mm_store_ps(mData)[3];
}


float Vector:len()
{
	float out;
	__m128 vect = _mm_mul_ps(mData, mData);

	__m128 shuf = _mm_movehdup_ps(vect);
	__m128 sum = _mm_add_ps(vect, shuf);
	shuf = _mm_movehl_ps(shuf, sum);
	sum = _mm_add_ss(sum, shuf);

	vect = _mm_sqrt_ps(sum);

	return _mm_store_ss(&out, len);
}


Vector Vector::unit()
{
	return _fvnorm(mData);
}


float Vector::dotproduct(const Vector &op)
{
	return _fvdotp(mData, op.mData);
}


Vector Vector::projection(const Vector &op)
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
	return Vector(_mm_mul_ps(mData, op.mData));
}


Vector Vector::operator/(const float &op)
{
	return Vector(_mm_div_ps());
}

Vector Vector::operator*(const Vector &op)
{
	return _fvdotp(mData, op.mData);
}
