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


void benchmark(int quantity)
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


void verification(ofstream &fout)
{
    //pass
}


int main()
{
    stub();
    //run_tests(TESTS);

    return 0;
}
