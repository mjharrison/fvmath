#ifndef CIVEK_HPP
#define CIVEK_HPP

#include <math.h>


void cmuls(float vector[4], float factor);

void cdivs(float vector[4], float factor);

void cadd(float vectorA[4], float vectorB[4]);

void csub(float vectorA[4], float vectorB[4]);

float clen(float vector[4]);

void cnorm(float vector[4]);

float cdotp(float vectorA[4], float vectorB[4]);

void cproj(float vectorA[4], float vectorB[4]);


#endif
