#include <iostream>

using namespace std;

int main()
{
    int array[5] = {1, 3, 4, 6, 8}; //2

    for (int i = 0; i < 5 && i + 1 < 5; i++)
    {
        if (array[i] + 1 == array[i + 1])
        {
            continue;
        }
        else
        {
            cout << array[i] + 1 << endl;
            //break;
            // uncomment break to get only one missing
        }
    }
    return 0;
}