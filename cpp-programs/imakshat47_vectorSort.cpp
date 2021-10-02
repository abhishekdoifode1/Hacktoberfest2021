/*
Vector-Sort
    Sample Input
        5
        1 6 10 8 4
    Sample Output
        1 4 6 8 10
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> vec(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &vec[i]);
    }

    sort(vec.begin(), vec.end());

    // To print values in vector
    for (auto i : vec)
    {
        printf("%d ", i);
    }

    return 0;
}
