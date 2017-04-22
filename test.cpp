#include "test.hpp"


void copy(float dst[4], const float src[4])
{
    for (int i = 0; i < 4; i++)
    {
        dst[i] = src[i];
    }
}


void display(float vector[4])
{
    printf("%f, %f, %f, %f\n", vector[0], vector[1], vector[2], vector[3]);
}


void load(float vector[4], float x, float y, float z, float w)
{
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
    vector[3] = w;
}


void run_tests(int quantity)
{
    std::ofstream fout;

    fout.open(FILE_NAME, std::ofstream::out | std::ofstream::app);
    if (!fout || fout.fail())
    {
        exit(1);
    }
    
    fout << FILE_HEADER;
    
    for (int i = 0; i < quantity; i++)
    {
        test(fout);
    }
}


void stub()
{
    Timer timer;
    double duration;
    float vector[4];

    timer.start();
    copy(vector, SAMPLE_A);
    fvmuls(vector, 5.5);
    duration = timer.stop();
    display(vector);
    printf("Duration: %f\n", duration);
}


void test(std::string fout_path, std::ofstream &fout)
{
    Timer timer;
    double duration;
    float vector_v[4];
    float vector_u[4];
    float factor = 3;
    

    // Single-precision scalar multiplcation

    copy(vector_v, SAMPLE_A);
    timer.set();
    vmuls(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    
    copy(vector_v, SAMPLE_A);
    timer.set();
    fvmuls(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision scalar division

    copy(vector_v, SAMPLE_A);
    timer.set();
    vdivs(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.set();
    fvdivs(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector addition

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    vadd(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    fvadd(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector subtraction

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    vsub(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    fvsub(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector length 

    copy(vector_v, SAMPLE_A);
    timer.set();
    vlen(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.set();
    fvlen(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector normalization 

    copy(vector_v, SAMPLE_A);
    timer.set();
    vnorm(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.set();
    fvnorm(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector dot product

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    vdotp(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    fvdotp(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector projection

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    vproj(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.set();
    fvproj(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << "\n";
}


int main()
{
    stub();
    //run_tests(FILE_NAME, TESTS_QUANTITY);

    return 0;
}
