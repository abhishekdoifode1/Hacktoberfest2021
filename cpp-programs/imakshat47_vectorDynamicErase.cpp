/*
    A vector of  integers. Then, you are given  queries. For the first query, you are provided with  integer, which denotes a position in the vector. The value at this position in the vector needs to be erased. The next query consists of  integers denoting a range of the positions in the vector. The elements which fall under that range should be removed. The second query is performed on the updated vector which we get after performing the first query.

    Input Format
        The first line of the input contains an integer .The next line contains  space separated integers(1-based index).The third line contains a single integer ,denoting the position of an element that should be removed from the vector.The fourth line contains two integers  and  denoting the range that should be erased from the vector inclusive of a and exclusive of b.
    
    Output Format
        Print the size of the vector in the first line and the elements of the vector after the two erase operations in the second line separated by space.

    Sample Input
        6
        1 4 6 2 8 9
        2
        2 4

    Sample Output
        3
        1 8 9
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

    int pos, init, end;

    scanf("%d", &pos);
    vec.erase(vec.begin() + (pos - 1));

    scanf("%d %d", &init, &end);
    vec.erase(vec.begin() + (init - 1), vec.begin() + (end - 1));

    printf("%d\n", vec.size());

    for (auto i : vec)
        printf("%d ", i);

    return 0;
}
