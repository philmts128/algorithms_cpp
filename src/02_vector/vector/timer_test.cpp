#include <iostream>
using namespace std;

#include "timer.h"



double e(long long int it)
{
    double r = 0;
    double prev = 1.0;
    for (int i = 1; i <= it; ++i) {
        r += (double)i/prev;
        prev = (i + 1.0) * prev;
    }
    return r;
}

int main()
{
    cout.precision(20);

    pm::timer t;
    double x;

    t.measure(3, [&](){
        x = e(1000000000);
    });

    cout << "| e: " << x << '\n';
    cout << "| tempo: " << t.get_result() << '\n';

    return 0;
}
