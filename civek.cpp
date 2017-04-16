#include "civek.hpp"


void cmuls(float vector[4], float factor)
{
    for (int i = 0; i < 4; i++)
    {
        vector[i] *= factor;
    }
}


void cdivs(float vector[4], float factor)
{
    for (int i = 0; i < 4; i++)
    {
        vector[i] /= factor;
    }
}


void cadd(float vectorA[4], float vectorB[4])
{
    for (int i = 0; i < 4; i++)
    {
        vectorA[i] += vectorB[i];
    }
}


void csub(float vectorA[4], float vectorB[4])
{
    for (int i = 0; i < 4; i++)
    {
        vectorA[i] -= vectorB[i];
    }
}


float clen(float vector[4])
{
    float len = 0.0;

    for (int i = 0; i < 4; i++)
    {
        len += (vector[i] * vector[i]);
    }

    return sqrt(len);
}


void cnorm(float vector[4])
{
    float len = clen(vector);
    
    for (int i = 0; i < 4; i++)
    {
        vector[i] /= len;
    }
}


float cdotp(float vectorA[4], float vectorB[4])
{
    float dotp = 0.0;
    
    for (int i = 0; i < 4; i++)
    {
        dotp += (vectorA[i] * vectorB[i]);
    }
    
    return dotp;
}


void cproj(float vectorA[4], float vectorB[4])
{
    float dotp = cdotp(vectorA, vectorB);
    float len = clen(vectorB);
    dotp /= (len * len);
    
    cmuls(vectorB, dotp);
}
