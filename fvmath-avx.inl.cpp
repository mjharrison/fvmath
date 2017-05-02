#include "fvmath.hpp"


void fvmuls(double vector_v[4], double factor_k)
{
    __m256d a = _mm256_load_pd(vector_v);
    __m256d b = _mm256_broadcast_sd(&factor_k);
    
    a = _mm256_mul_pd(a, b);
    
    _mm256_store_pd(vector_v, a);
}


void fvdivs(double vector_v[4], double factor_k)
{
    __m256d a = _mm256_load_pd(vector_v);
    __m256d b = _mm256_broadcast_sd(&factor_k);
    
    a = _mm256_div_pd(a, b);
    
    _mm256_store_pd(vector_v, a);
}


void fvadd(double vector_v[4], double vector_u[4])
{
    __m256d a = _mm256_load_pd(vector_v);
    __m256d b = _mm256_load_pd(vector_u);
    
    a = _mm256_add_pd(a, b);
    
    _mm256_store_pd(vector_v, a);
}


void fvsub(double vector_v[4], double vector_u[4])
{
    __m256d a = _mm256_load_pd(vector_v);
    __m256d b = _mm256_load_pd(vector_u);
    
    a = _mm256_sub_pd(a, b);
    
    _mm256_store_pd(vector_v, a);
}


__m256d _fvlen(__m256d a)
{
    a = _mm256_mul_pd(a, a);
    a = _mm256_hadd_pd(a, a);
    a = _mm256_hadd_pd(a, a);
    a = _mm256_sqrt_pd(a);
    
    return a;
}


double fvlen(double vector_v[4])
{
    double result;
    __m256d a = _mm256_load_pd(vector_v);
    
    a = _fvlen(a);
    
    _mm_store_sd(&result, a);
    return result;
}


__m256d _fvnorm(__m256d a)
{
    __m256d b = _fvlen(a);
    
    a = _mm256_div_pd(a, b);
    
    return a;
}


void fvnorm(double vector_v[4])
{
    __m256d a = _mm256_load_ps(vector_v);

    a = _fvnorm(a);
    
    _mm256_store_pd(vector_v, a);
}


__m128 _fvdotp(__m256d a, __m256d b)
{
    a = _mm256_mul_pd(a, b);
    a = _mm256_hadd_pd(a, a);
    a = _mm256_hadd_pd(a, a);
    
    return a;
}


double fvdotp(double vector_v[4], double vector_u[4])
{
    double result;
    __m256d a = _mm256_load_pd(vector_v);
    __m256d b = _mm256_load_pd(vector_u);
    
    a = _fvdotp(a, b);
    
    _mm_store_sd(&result, a);
    return result;
}


__m256d _fvproj(__m256d a, __m256d b, __m256d c)
{
    a = _fvdotp(a, b);
    b = _fvlen(b);
    b = _mm256_mul_pd(b, b);
    a = _mm256_div_pd(a, b);
    a = _mm256_mul_pd(a, c);
    
    return a;
}


void fvproj(double vector_v[4], double vector_u[4])
{
    __m256d a = _mm_load_ps(vector_v);
    __m256d b = _mm_load_ps(vector_u);
    __m256d c = b;
    
    a = _fvproj(a, b, c);
    _mm256_store_pd(vector_v, a);
}
