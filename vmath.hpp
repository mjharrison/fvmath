#ifndef CIVEK_HPP
#define CIVEK_HPP

#include <math.h>


void vmuls(float vector[4], float factor);

void vdivs(float vector[4], float factor);

void vadd(float vectorA[4], float vectorB[4]);

void vsub(float vectorA[4], float vectorB[4]);

float vlen(float vector[4]);

void vnorm(float vector[4]);

float vdotp(float vectorA[4], float vectorB[4]);

void vproj(float vectorA[4], float vectorB[4]);


#endif
