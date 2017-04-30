#include "test.hpp"
#include "vector.hpp"
#include <iostream>

int main()
{
	Vector v = Vector(SAMPLE_A);
	Vector u = Vector(SAMPLE_B);
    cout << "v: " << v << "\n" 
         << "u: " << u << "\n";

    v = v + u;
    cout << "v + u: " << v << "\n";
    
    v = v - u;
    cout << "v + u - u: " << v << "\n";
    
    v = v * 2;
    cout << "v * 2: " << v << "\n";
    
    v = v / 2;
    cout << "v / 2: " << v << "\n";
    
    cout << (v == v ? "v==v\n" : "v!=v") << "\n";

    return 0;
}
