#ifndef FVMATH_AVX_HPP
#define FVMATH_AVX_HPP


void fvmuls(double vector_v[4], double factor_k)
{
    __m256 a = _mm256_load_pd(vector_v);
    __m256 b = _mm256_broadcast_sd(&factor_k);
    
    a = _mm256_mul_pd(a, b);
    
    _mm256_store_pd(vector_v, a);
}


void fvdivs(double vector_v[4], double factor_k)
{
    __m256 a = _mm256_load_pd(vector_v);
    __m256 b = _mm256_broadcast_sd(&factor_k);
    
    a = _mm256_div_pd(a, b);
    
    _mm256_store_pd(vector_v, a);
}


void fvadd(float vector_v[4], float vector_u[4])
{
    __m256 a = _mm256_load_pd(vector_v);
    __m256 b = _mm256_load_pd(vector_u);
    
    a = _mm256_add_pd(a, b);
    
    _mm256_store_pd(vector_v, a);
}


void fvsub(float vector_v[4], float vector_u[4])
{
    __m256 a = _mm256_load_pd(vector_v);
    __m256 b = _mm256_load_pd(vector_u);
    
    a = _mm256_sub_pd(a, b);
    
    _mm256_store_pd(vector_v, a);
}


__m256 _fvlen_d(__m256 a)
{
    a = _mm256_mul_pd(a, a);
    a = _mm256_hadd_pd(a, a);
    a = _mm256_hadd_pd(a, a);
    a = _mm256_sqrt_pd(a);
    
    return a;
}


double fvlen(double vector_v[4])
{
    float result;
    __m256 a = _mm256_load_pd(vector_v);
    
    a = _fvlen_d(a);
    
    _mm_store_sd(&result, a);
    return result;
}


__m256 _fvnorm_d(__m256 a)
{
    __m256 b = _fvlen_d(a);
    
    a = _mm256_div_pd(a, b);
    
    return a;
}


void fvnorm(double vector_v[4])
{
    __m256 a = _mm256_load_ps(vector_v);

    a = _fvnorm_d(a);
    
    _mm256_store_pd(vector_v, a);
}


__m128 _fvdotp_d(__m256 a, __m256 b)
{
    a = _mm256_mul_pd(a, b);
    a = _mm256_hadd_pd(a, a);
    a = _mm256_hadd_pd(a, a);
    
    return a;
}


double fvdotp(double vector_v[4], double vector_u[4])
{
    double result;
    __m256 a = _mm256_load_pd(vector_v);
    __m256 b = _mm256_load_pd(vector_u);
    
    a = _fvdotp_d(a, b);
    
    _mm_store_sd(&result, a);
    return result;
}


__m256 _fvproj_d(__m256 a, __m256 b, __m256 c)
{
    a = _fvdotp_d(a, b);
    b = _fvlen_d(b);
    b = _mm256_mul_pd(b, b);
    a = _mm256_div_pd(a, b);
    a = _mm256_mul_pd(a, c);
    
    return a;
}


void fvproj(double vector_v[4], double vector_u[4])
{
    __m256 a = _mm_load_ps(vector_v);
    __m256 b = _mm_load_ps(vector_u);
    __m256 c = b;
    
    a = _fvproj_d(a, b, c);
    _mm256_store_pd(vector_v, a);
}


#endif
