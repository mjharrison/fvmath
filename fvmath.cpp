#include "fvmath.hpp"


#ifdef __SSE__
#include "fvmath-sse.inl.cpp"
#else


void fvmuls(float vector_v[4], float factor_k)
{
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] *= factor_k;
    }
}


void fvdivs(float vector_v[4], float factor_k)
{
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] /= factor_k;
    }
}


void fvadd(float vector_v[4], float vector_u[4])
{
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] += vector_u[i];
    }
}


void fvsub(float vector_v[4], float vector_u[4])
{
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] -= vector_u[i];
    }
}


float fvlen(float vector_v[4])
{
    float len = 0.0;

    for (int i = 0; i < 4; i++)
    {
        len += (vector_v[i] * vector_v[i]);
    }

    return sqrt(len);
}


void fvnorm(float vector_v[4])
{
    float len = fvlen(vector_v);
    
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] /= len;
    }
}


float fvdotp(float vector_v[4], float vector_u[4])
{
    float dotp = 0.0;
    
    for (int i = 0; i < 4; i++)
    {
        dotp += (vector_v[i] * vector_u[i]);
    }
    
    return dotp;
}


void fvproj(float vector_v[4], float vector_u[4])
{
    float dotp = fvdotp(vector_v, vector_u);
    float len = fvlen(vector_u);
    dotp /= (len * len);
    
    fvmuls(vector_u, dotp);
}


#endif


#ifdef __AVX__
#include "fvmath-avx.inl.cpp"
#else


void fvmuls(double vector_v[4], double factor_k)
{
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] *= factor_k;
    }
}


void fvdivs(double vector_v[4], double factor_k)
{
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] /= factor_k;
    }
}


void fvadd(double vector_v[4], double vector_u[4])
{
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] += vector_u[i];
    }
}


void fvsub(double vector_v[4], double vector_u[4])
{
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] -= vector_u[i];
    }
}


double fvlen(double vector_v[4])
{
    double len = 0.0;

    for (int i = 0; i < 4; i++)
    {
        len += (vector_v[i] * vector_v[i]);
    }

    return sqrt(len);
}


void fvnorm(double vector_v[4])
{
    double len = fvlen(vector_v);
    
    for (int i = 0; i < 4; i++)
    {
        vector_v[i] /= len;
    }
}


double fvdotp(double vector_v[4], double vector_u[4])
{
    double dotp = 0.0;
    
    for (int i = 0; i < 4; i++)
    {
        dotp += (vector_v[i] * vector_u[i]);
    }
    
    return dotp;
}


void fvproj(double vector_v[4], double vector_u[4])
{
    float dotp = vdotp(vector_v, vector_u);
    float len = vlen(vector_u);
    dotp /= (len * len);
    
    fvmuls(vector_u, dotp);
}


#endif
