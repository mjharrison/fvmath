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
    ofstream fout;

    fout.open(FILE_NAME, ofstream::out | ofstream::app);
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
	double difference;
    float vectorA[4];
	float vectorB[4];
	float result;

    copy(vectorA, SAMPLE_A);
	copy(vectorB, SAMPLE_B);
    
    timer.start();
    result = vdotp(vectorA, vectorB);
    duration = timer.stop();
    printf("\nvdotp: %f\ntime: %f\n\n", result, duration);

	difference = duration;

	timer.start();
	result = fvdotp(vectorA, vectorB);
	duration = timer.stop();
	printf("fvdotp: %f\ntime: %f\n\n", result, duration);

	difference -= duration;

	printf("diff: %f\n", difference);
	printf(difference > 0 ? "SUCCESS\n\n" : "FAILURE\n\n");
}


void test(ofstream &fout)
{
    Timer timer;
    double duration;
    float vector_v[4];
    float vector_u[4];
    float factor = 3;
    

    // Single-precision scalar multiplcation

    copy(vector_v, SAMPLE_A);
    timer.start();
    vmuls(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    
    copy(vector_v, SAMPLE_A);
    timer.start();
    fvmuls(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision scalar division

    copy(vector_v, SAMPLE_A);
    timer.start();
    vdivs(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.start();
    fvdivs(vector_v, factor);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector addition

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.start();
    vadd(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.start();
    fvadd(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector subtraction

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.start();
    vsub(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.start();
    fvsub(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector length 

    copy(vector_v, SAMPLE_A);
    timer.start();
    vlen(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.start();
    fvlen(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector normalization 

    copy(vector_v, SAMPLE_A);
    timer.start();
    vnorm(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    timer.start();
    fvnorm(vector_v);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector dot product

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.start();
    vdotp(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.start();
    fvdotp(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    

    // Single-precision vector projection

    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.start();
    vproj(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << ",";
    
    
    copy(vector_v, SAMPLE_A);
    copy(vector_u, SAMPLE_B);
    timer.start();
    fvproj(vector_v, vector_u);
    duration = timer.stop();
    fout << duration << "\n";
}


int main()
{
    stub();
    //run_tests(TESTS);

    return 0;
}
