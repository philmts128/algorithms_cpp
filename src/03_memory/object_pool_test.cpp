#include <iostream>
#include <string>
using namespace std;

#include "object_pool.h"

struct my_struct {
    my_struct() {
        cout << "\nmy struct created\n";
    }

    ~my_struct() {
        cout << "\nmy struct destroyed\n";
    }
};

void test_my_struct(bool);
void test_strings();
void test_ints();

int main()
{
    test_ints();
    test_strings();
    test_my_struct(false); //sem leak
    test_my_struct(true); //com leak

    printf("\n\n");
    return 0;
}


void test_my_struct(bool leak = false)
{
    pm::object_pool<my_struct> pool(1024);

    my_struct* s1 = pool.allocate();
    my_struct* s2 = pool.allocate();
    my_struct* s3 = pool.allocate();

    if (!leak) {
        pool.deallocate(s1);
        pool.deallocate(s2);
        pool.deallocate(s3);
    }
}

void test_strings()
{
    pm::object_pool<string> pool(1024);

    string* fruits[5];

    fruits[0] = pool.allocate("\n\napple");
    fruits[1] = pool.allocate("banana");
    fruits[2] = pool.allocate("grape");
    fruits[3] = pool.allocate("orange");
    fruits[4] = pool.allocate("watermelon");

    for (auto f : fruits) {
        cout << *f << "\n";
        pool.deallocate(f);
    }
}

void test_ints()
{
    pm::object_pool<int> pool(1024);
    int* data[100];

    for (int i = 0 ; i < 100; ++i) {
        data[i] = pool.allocate(i);
    }

    for (int i = 0 ; i < 100; ++i) {
        cout << *data[i] << ' ';
    }

    for (int i = 0 ; i < 100; ++i) {
        pool.deallocate(data[i]);
    }
}
