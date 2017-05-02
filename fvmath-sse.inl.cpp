#include "fvmath.hpp"


void fvmuls(float vector_v[4], float factor_k)
{
    __m128 a = _mm_load_ps(vector_v);
    __m128 b = _mm_load_ps1(&factor_k);
    
    a = _mm_mul_ps(a, b);
    
    _mm_store_ps(vector_v, a);
}


void fvdivs(float vector_v[4], float factor_k)
{
    __m128 a = _mm_load_ps(vector_v);
    __m128 b = _mm_load_ps1(&factor_k);
    
    a = _mm_div_ps(a, b);
    
    _mm_store_ps(vector_v, a);
}


void fvadd(float vector_v[4], float vector_u[4])
{
    __m128 a = _mm_load_ps(vector_v);
    __m128 b = _mm_load_ps(vector_u);
    
    a = _mm_add_ps(a, b);
    
    _mm_store_ps(vector_v, a);
}


void fvsub(float vector_v[4], float vector_u[4])
{
    __m128 a = _mm_load_ps(vector_v);
    __m128 b = _mm_load_ps(vector_u);
    
    a = _mm_sub_ps(a, b);
    
    _mm_store_ps(vector_v, a);
}


__m128 _fvlen(__m128 a)
{
    a = _mm_mul_ps(a, a);
    a = _mm_hadd_ps(a, a);
    a = _mm_hadd_ps(a, a);
    a = _mm_sqrt_ps(a);
    
    return a;
}


float fvlen(float vector_v[4])
{
    float result;
    __m128 a = _mm_load_ps(vector_v);
    
    a = _fvlen(a);
    
    _mm_store_ss(&result, a);
    return result;
}


__m128 _fvnorm(__m128 a)
{
    __m128 b = _fvlen(a);
    
    a = _mm_div_ps(a, b);
    
    return a;
}


void fvnorm(float vector_v[4])
{
    __m128 a = _mm_load_ps(vector_v);

    a = _fvnorm(a);
    
    _mm_store_ps(vector_v, a);
}


__m128 _fvdotp(__m128 a, __m128 b)
{
    a = _mm_mul_ps(a, b);
    a = _mm_hadd_ps(a, a);
    a = _mm_hadd_ps(a, a);
    
    return a;
}


float fvdotp(float vector_v[4], float vector_u[4])
{
    float result;
    __m128 a = _mm_load_ps(vector_v);
    __m128 b = _mm_load_ps(vector_u);
    
    a = _fvdotp(a, b);
    
    _mm_store_ss(&result, a);
    return result;
}


__m128 _fvproj(__m128 a, __m128 b, __m128 c)
{
    a = _fvdotp(a, b);
    b = _fvlen(b);
    b = _mm_mul_ps(b, b);
    a = _mm_div_ps(a, b);
    a = _mm_mul_ps(a, c);
    
    return a;
}


void fvproj(float vector_v[4], float vector_u[4])
{
    __m128 a = _mm_load_ps(vector_v);
    __m128 b = _mm_load_ps(vector_u);
    __m128 c = b;
    
    a = _fvproj(a, b, c);
    _mm_store_ps(vector_v, a);
}
