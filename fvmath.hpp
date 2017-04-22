#ifndef VIVEK_HPP
#define VIVEK_HPP

#include <x86intrin.h>


void fvmuls(float vector[4], float factor);

void fvdivs(float vector[4], float factor);

void fvadd(float vectorA[4], float vectorB[4]);

void fvsub(float vectorA[4], float vectorB[4]);

float fvlen(float vector[4]);

void fvnorm(float vector[4]);

float fvdotp(float vectorA[4], float vectorB[4]);

void fvproj(float vectorA[4], float vectorB[4]);


#endif
