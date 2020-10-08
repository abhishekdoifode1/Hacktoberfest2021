/*
Sets are a part of the C++ STL. Sets are containers that store unique elements following a specific order.

    1 x  : Add an element  to the set.
    2 x : Delete an element  from the set. (If the number  is not present in the set, then do nothing).
    3 x : If the number  is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

    Input Format
        The first line of the input contains  where  is the number of queries. The next  lines contain  query each. Each query consists of two integers  and  where  is the type of the query and  is an integer.
    
    Output Format
        For queries of type  print "Yes"(without quotes) if the number  is present in the set and if the number is not present, then print "No"(without quotes).
        Each query of type  should be printed in a new line.

    Sample Input
        8
        1 9
        1 6
        1 10
        1 4
        3 6
        3 14
        2 6
        3 6

    Sample Output
        Yes
        No
        No
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set<int> s;
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int type, num;
        scanf("%d %d", &type, &num);

        if (type == 1)
        {
            s.insert(num);
        }
        else if (type == 2)
        {
            s.erase(num);
        }
        else if (type == 3)
        {
            auto it = s.find(num);
            if (it == s.end())
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
        }
    }

    return 0;
}
