/**
 * Soma inteiros de um vetor
 * Autor: Philippe Matias
 */

#include <iostream>
#include <vector>
using namespace std;


/*-----------------------------*/
int min_element(const vector<int> items, size_t n = 0)
{
    if (n == items.size()-1)
        return items[n];

    int k = min_element(items, n+1);
    return  (k < items[n]) ? k : items[n];
}

/*-----------------------------*/
int max_element(const vector<int> items, size_t n = 0)
{
    if (n == items.size()-1)
        return items[n];

    int k = max_element(items, n+1);
    return  (k > items[n]) ? k : items[n];
}


/*-----------------------------*/
int main()
{
    vector<int> nums {1,2,3,4,5,6,7,8,9,0, -222};

    cout << "minimum:" << min_element(nums) << '\n';
    cout << "maximum:" << max_element(nums) <<'\n';

    cout << "\n\n";
    return 0;
}
