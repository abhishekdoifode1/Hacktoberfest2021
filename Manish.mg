C++ Program to Find Sum of Diagonals elements in a Matrix
What is Matrix ?
Matrix representation is a method used by a computer language to store matrices of more than one dimension in memory. C uses “Row Major”, which stores all the elements for a given row contiguously in memory.
Two-dimensional Arrays : :

The simplest form of multidimensional array is the two-dimensional array. A two-dimensional array is, in essence, a list of one-dimensional arrays. An m × n (read as m by n) order matrix is a set of numbers arranged in m rows and n columns.

To declare a two-dimensional integer array of size [x][y], you would write something as follows −


 
type arrayName [ x ][ y ];
Where type can be any valid C data type and arrayName will be a valid C identifier.

Below is the source code for C++ Program to Find Sum of Diagonals elements in a Matrix which is successfully compiled and run on Windows System to produce desired output as shown below :


SOURCE CODE : :
/*  C++ Program to Find Sum of Diagonals elements in a Matrix  */

#include<iostream>

using namespace std;

int main()
{
    int a[10][10],d1sum=0,d2sum=0,m,i,j;
    cout<<"Enter size of matrix :: ";
    cin>>m;
    cout<<"\nEnter Elements to Matrix Below :: \n";

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;++j)
        {
            cout<<"\nEnter a["<<i<<"]["<<j<<"] Element :: ";
            cin>>a[i][j];
        }

    }

    cout<<"\nThe given matrix is :: \n\n";
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                cout<<"\t"<<a[i][j];
            }
            printf("\n\n");
        }



    for(i=0;i<m;++i)
        for(j=0;j<m;++j)
        {
            if(i==j)
                d1sum+=a[i][j];
            if(i+j==(m-1))
                d2sum+=a[i][j];
        }

    cout<<"\nSum of 1st diagonal is :: "<<d1sum;
    cout<<"\n\nSum of 2nd diagonal is :: "<<d2sum;

    return 0;
}
OUTPUT : :
/*  C++ Program to Find Sum of Diagonals elements in a Matrix  */

Enter size of matrix :: 3

Enter Elements to Matrix Below ::

Enter a[0][0] Element :: 1

Enter a[0][1] Element :: 2

Enter a[0][2] Element :: 3

Enter a[1][0] Element :: 4

Enter a[1][1] Element :: 5

Enter a[1][2] Element :: 6

Enter a[2][0] Element :: 7

Enter a[2][1] Element :: 8

Enter a[2][2] Element :: 9

The given matrix is ::

        1       2       3

        4       5       6

        7       8       9


Sum of 1st diagonal is :: 15

Sum of 2nd diagonal is :: 15

Process returned 0
