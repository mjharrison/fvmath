#include "fvmath.hpp"

#ifdef __SSE__

void fvmuls(float vector[4], float factor)
{
    __m128 u = _mm_load_ps(vector);
    __m128 k = _mm_load_ps1(&factor);
    
    u = _mm_mul_ps(u, k);
    
    _mm_store_ps(vector, u);
}


void fvdivs(float vector[4], float factor)
{
    __m128 a = _mm_load_ps(vector);
    __m128 b = _mm_load_ps1(&factor);
    
    a = _mm_div_ps(a, b);
    
    _mm_store_ps(vector, a);
}


void fvadd(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _mm_add_ps(a, b);
    
    _mm_store_ps(vectorA, a);
}


void fvsub(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _mm_sub_ps(a, b);
    
    _mm_store_ps(vectorA, a);
}


__m128 _fvlen(__m128 a)
{
    a = _mm_mul_ps(a, a);
    a = _mm_hadd_ps(a, a);
    a = _mm_hadd_ps(a, a);
    a = _mm_sqrt_ps(a);
    
    return a;
}


float fvlen(float vector[4])
{
    float result;
    __m128 a = _mm_load_ps(vector);
    
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


void fvnorm(float vector[4])
{
    __m128 a = _mm_load_ps(vector);

    a = _fvnorm(a);
    
    _mm_store_ps(vector, a);
}


__m128 _fvdotp(__m128 a, __m128 b)
{
    a = _mm_mul_ps(a, b);
    a = _mm_hadd_ps(a, a);
    a = _mm_hadd_ps(a, a);
    
    return a;
}


float fvdotp(float vectorA[4], float vectorB[4])
{
    float result;
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _fvdotp(a, b);
    
    _mm_store_ss(&result, a);
    return result;
}


__m128 _fvproj(__m128 a, __m128 b, __m128 c)
{
    a = _fvdotp(a, b);
    b = _fvlen(b);
    b = _mm_mul_ps(b, b);
    a = _mm_mul_ps(a, b);
    
    return a;
}


void fvproj(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    __m128 c = b;
    
    a = _fvproj(a, b, c);
    _mm_store_ps(vectorA, a);
}

#else

void fvmuls(float vector[4], float factor)
{
    for (int i = 0; i < 4; i++)
    {
        vector[i] *= factor;
    }
}


void fvdivs(float vector[4], float factor)
{
    for (int i = 0; i < 4; i++)
    {
        vector[i] /= factor;
    }
}


void fvadd(float vectorA[4], float vectorB[4])
{
    for (int i = 0; i < 4; i++)
    {
        vectorA[i] += vectorB[i];
    }
}


void fvsub(float vectorA[4], float vectorB[4])
{
    for (int i = 0; i < 4; i++)
    {
        vectorA[i] -= vectorB[i];
    }
}


float fvlen(float vector[4])
{
    float len = 0.0;

    for (int i = 0; i < 4; i++)
    {
        len += (vector[i] * vector[i]);
    }

    return sqrt(len);
}


void fvnorm(float vector[4])
{
    float len = vlen(vector);
    
    for (int i = 0; i < 4; i++)
    {
        vector[i] /= len;
    }
}


float fvdotp(float vectorA[4], float vectorB[4])
{
    float dotp = 0.0;
    
    for (int i = 0; i < 4; i++)
    {
        dotp += (vectorA[i] * vectorB[i]);
    }
    
    return dotp;
}


void fvproj(float vectorA[4], float vectorB[4])
{
    float dotp = vdotp(vectorA, vectorB);
    float len = vlen(vectorB);
    dotp /= (len * len);
    
    vmuls(vectorB, dotp);
}

#endif
