#include "vivek.hpp"


void vmuls(float vector[4], float factor)
{
    __m128 a = _mm_load_ps(vector);
    __m128 b = _mm_load_ps1(&factor);
    
    a = _mm_mul_ps(a, b);
    
    _mm_store_ps(vector, a);
}


void vdivs(float vector[4], float factor)
{
    __m128 a = _mm_load_ps(vector);
    __m128 b = _mm_load_ps1(&factor);
    
    a = _mm_div_ps(a, b);
    
    _mm_store_ps(vector, a);
}


void vadd(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _mm_add_ps(a, b);
    
    _mm_store_ps(vectorA, a);
}


void vsub(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _mm_sub_ps(a, b);
    
    _mm_store_ps(vectorA, a);
}


__m128 _vlen(__m128 a)
{
    a = _mm_mul_ps(a, a);
    a = _mm_hadd_ps(a, a);
    a = _mm_hadd_ps(a, a);
    a = _mm_sqrt_ps(a);
    
    return a;
}


float vlen(float vector[4])
{
    float result;
    __m128 a = _mm_load_ps(vector);
    
    a = _vlen(a);
    
    _mm_store_ss(&result, a);
    return result;
}


__m128 _vnorm(__m128 a)
{
    __m128 b = _vlen(a);
    
    a = _mm_div_ps(a, b);
    
    return a;
}


void vnorm(float vector[4])
{
    __m128 a = _mm_load_ps(vector);

    a = _vnorm(a);
    
    _mm_store_ps(vector, a);
}


__m128 _vdotp(__m128 a, __m128 b)
{
    a = _mm_mul_ps(a, b);
    a = _mm_hadd_ps(a, a);
    a = _mm_hadd_ps(a, a);
    
    return a;
}


float vdotp(float vectorA[4], float vectorB[4])
{
    float result;
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _vdotp(a, b);
    
    _mm_store_ss(&result, a);
    return result;
}


__m128 _vproj(__m128 a, __m128 b, __m128 c)
{
    a = _vdotp(a, b);
    b = _vlen(b);
    b = _mm_mul_ps(b, b);
    a = _mm_mul_ps(a, b);
    
    return a;
}


void vproj(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    __m128 c = b;
    
    a = _vproj(a, b, c);
    _mm_store_ps(vectorA, a);
}
