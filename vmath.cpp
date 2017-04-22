#include "vmath.hpp"


void vmuls(float vector[4], float factor)
{
    for (int i = 0; i < 4; i++)
    {
        vector[i] *= factor;
    }
}


void vdivs(float vector[4], float factor)
{
    for (int i = 0; i < 4; i++)
    {
        vector[i] /= factor;
    }
}


void vadd(float vectorA[4], float vectorB[4])
{
    for (int i = 0; i < 4; i++)
    {
        vectorA[i] += vectorB[i];
    }
}


void vsub(float vectorA[4], float vectorB[4])
{
    for (int i = 0; i < 4; i++)
    {
        vectorA[i] -= vectorB[i];
    }
}


float vlen(float vector[4])
{
    float len = 0.0;

    for (int i = 0; i < 4; i++)
    {
        len += (vector[i] * vector[i]);
    }

    return sqrt(len);
}


void vnorm(float vector[4])
{
    float len = vlen(vector);
    
    for (int i = 0; i < 4; i++)
    {
        vector[i] /= len;
    }
}


float vdotp(float vectorA[4], float vectorB[4])
{
    float dotp = 0.0;
    
    for (int i = 0; i < 4; i++)
    {
        dotp += (vectorA[i] * vectorB[i]);
    }
    
    return dotp;
}


void vproj(float vectorA[4], float vectorB[4])
{
    float dotp = vdotp(vectorA, vectorB);
    float len = vlen(vectorB);
    dotp /= (len * len);
    
    vmuls(vectorB, dotp);
}
