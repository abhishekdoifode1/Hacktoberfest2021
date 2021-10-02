/* Write a program to print the magic matrix.
(i) Magic matrix is a square matrix of order nxn
(ii) A magic matrix exists only for odd values of n.
(iii) The number of matrix will be 1,2,3,4,…..n 2 and each number can occur in the
matrix only once.
(iv) The sums of the elements of every row, column and diagonal are equal which
is equal to n(n 2 +1)/2.

The procedure for creating a magic matrix is
Start filling numbers from the centre column of bottom row, so initially place
the number 1 in the centre column of the bottom row. Keep on placing the
numbers by moving one row down and one column left (down-left) till you
reach one of the following situations-
I) If you reach at the bottom left of the matrix, or a square that is already
filled then move one row up in the same column. This situation will
arise when previously placed number was divisible by n.
II) If you have to move left of the leftmost column, then go to the
rightmost column.
III) If you have to move down the bottom row, then go to the topmost row. */

#include<stdio.h>

int main()
{
    int row,col,n;
    printf("Enter Number of rows(odd):");
    scanf("%d",&n);
    if(n%2!=0)
    {
        int a[n][n];
        printf("Magic Square for %d rows is\n",n);
        row=0;
        col=n/2;
        for(int i=1;i<=n*n;i++)
        {
            a[row][col]=i;
            row--;
            col++;
            if(i%n==0)
            {
                row=row+2;
                col=col-1;
                if(row==n)
                row=row-n;
            }
            else
            {
            if(col==n)
                col=col-n;
            if(row<0)
                row=row+n;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                printf("%d\t",a[i][j]);
            }
        printf("\n");
        }
    }
    else
    {
        printf("Entered number is even.");
    }
    return 0;
}
