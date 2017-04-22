#ifndef TEST_HPP
#define TEST_HPP

#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "fvmath.hpp"
#include "vmath.hpp"
#include "timer.hpp"

const std::string FILE_NAME = "out.csv";
const std::string FILE_HEADER = "vmuls,fvmuls,vdivs,fvdivs,vadd,fvadd,vsub,fvsub,vlen,fvlen,vnorm,fvnorm,vdotp,fvdotp,vproj,fvproj\n";
const float SAMPLE_A[4] = { 1.2, 3.5, 0.7, 0.0 };
const float SAMPLE_B[4] = { 11.5, 2.6, 6.1, 0.0 };
const int TESTS_QUANTITY = 100;

void copy(float dst[4], const float src[4]);
void display(float vector[4]);
void load(float vector[4], float a, float b, float c, float d);

void run_tests(int quantity);
void stub();
void test(std::ofstream);


#endif
