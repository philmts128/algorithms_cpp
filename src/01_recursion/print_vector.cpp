/**
 * Percorre vetor recursivamente.
 * Autor: Philippe Matias
 */

#include <iostream>
#include <vector>
using namespace std;

/*-----------------------------*/
void print_ascending(const vector<int>& nums, int n = 0)
{
    if (n == (int)(nums.size()))
        return;
    cout << nums.at(n) << ' ';
    print_ascending(nums, n+1);
}

/*-----------------------------*/
void print_descending(const vector<int>& nums, int n = 0)
{
    if (n == (int)(nums.size()))
        return;
    cout << nums.at((nums.size()-(n+1))) << ' ';
    print_descending(nums, n+1);
}

/*-----------------------------*/
int main()
{
    vector<int> nums { 2,3,4,5,6,7,8 };

    print_descending(nums);

    cout << "\n\n";
    return 0;
}
