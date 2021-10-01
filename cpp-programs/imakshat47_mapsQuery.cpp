/*
Maps are a part of the C++ STL.Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

    So the teacher has  queries:

        1 :Add the marks  to the student whose name is .

        2 : Erase the marks of the students whose name is .

        3 : Print the marks of the students whose name is . (If  didn't get any marks print .)

    Input Format
        The first line of the input contains  where  is the number of queries. The next  lines contain  query each.The first integer,  of each query is the type of the query.If query is of type , it consists of one string and an integer  and  where  is the name of the student and  is the marks of the student.If query is of type  or ,it consists of a single string  where  is the name of the student.

    Output Format
        For queries of type  print the marks of the given student.

    Sample Input
        7
        1 Jesse 20
        1 Jess 12
        1 Jess 18
        3 Jess
        3 Jesse
        2 Jess
        3 Jess

    Sample Output
        30
        20
        0
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, int> m;
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int type, num;
        string str;
        cin >> type >> str;

        if (type == 1)
        {
            scanf("%d", &num);
            m[str] += num;
        }
        else if (type == 2)
        {
            m.erase(str);
        }
        else if (type == 3)
        {
            auto it = m.find(str);
            if (it != m.end())
            {
                printf("%d\n", m[str]);
            }
            else
                printf("0\n");
        }
    }

    return 0;
}
