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
	return _fvlen(mData);
}


Vector Vector::unit()
{
	return _fvnorm(mData);
}


float Vector::dotproduct(const Vector &op)
{
	return _fvdotp(mData, op);
}


Vector Vector::projection(const Vector &op)
{
	return _fvproj(mData, op);
}


void Vector::operator=(const Vector &op)
{
	mData = op.mData;
}


Vector Vector::operator+(const Vector &op)
{
	
}


Vector Vector::operator-(const Vector &op);
Vector Vector::operator*(const float &op);
Vector Vector::operator/(const float &op);