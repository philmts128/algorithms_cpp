#include <iostream>
#include <string>
using namespace std;

#include "object_pool.h"
#include "timer.h"


int main()
{
    constexpr int iter = 200000000;
    long x = 0;
    pm::timer timer;

    timer.measure(2, [&](){
        for (int i = 0; i < iter; ++i) {
            int *k = new int;
            *k = i+1;
            x += *k;
            delete k;
        }
    });

    cout << "tempo [sem pool]: " << timer.get_result() << '\n';

    pm::object_pool<int> pool(2048);

    timer.measure(2, [&](){
        for (int i = 0; i < iter; ++i) {
            int *k = pool.allocate();
            *k = i+1;
            x += *k;
            pool.deallocate(k);
        }
    });

    cout << "tempo [com pool]: " << timer.get_result() << '\n';

    printf("\n\n");
    return 0;
}

