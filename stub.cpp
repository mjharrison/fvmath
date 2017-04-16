#include <fstream>
#include <string>
#include <stdlib.h>

#include "vivek.hpp"
#include "civek.hpp"
#include "timer.hpp"


const int TEST_COUNT = 100;
const float SAMPLE_A[4] = { 1.2, 3.5, 0.7, 0.0 };
const float SAMPLE_B[4] = { 11.5, 2.6, 6.1, 0.0 };
const std::string FILE_NAME = "out.csv";
const std::string FILE_HEADER = "cmuls,vmuls,cdivs,vdivscadd,vadd,csub,vsub,clen,vlen,cnorm,vnorm,cdotp,vdotp,cproj,vproj\n";


void copy(float dst[4], const float src[4])
{
    for (int i = 0; i < 4; i++)
    {
        dst[i] = src[i];
    }
}


void load(float vector[4], float x, float y, float z, float w)
{
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
    vector[3] = w;
}


void test(std::ofstream &fout)
{
    Timer timer;
    double duration;
    float vector_v[4];
    float vector_u[4];
    float factor = 3;
    

    // Single-precision scalar multiplcation

    copy(vector_v, SAMPLE_A);
    timer.set();
    cmuls(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    
    copy(vector_v, SAMPLE_A);
    timer.set();
    vmuls(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision scalar division

    copy(vector_v, SAMPLE_A);
    timer.set();
    cdivs(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.set();
    vdivs(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector addition

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    cadd(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    vadd(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector subtraction

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    csub(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    vsub(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector length 

    copy(vector_v, SAMPLE_A);
    timer.set();
    clen(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.set();
    vlen(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector normalization 

    copy(vector_v, SAMPLE_A);
    timer.set();
    cnorm(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.set();
    vnorm(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector dot product

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    cdotp(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    vdotp(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector projection

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    cproj(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    vproj(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << "\n";
}


int main()
{
    std::ofstream fout;

    fout.open(FILE_NAME, std::ofstream::out | std::ofstream::app);
    if (!fout || fout.fail())
    {
        exit(1);
    }
    
    fout << FILE_HEADER;
    
    for (int i = 0; i < TEST_COUNT; i++)
    {
        test(fout);
    }
    
    return 0;
}
