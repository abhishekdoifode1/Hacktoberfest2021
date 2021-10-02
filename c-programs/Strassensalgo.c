// Strassen's algorithm is used to claculate multiplication of large matrices by dividing it into smaller sub matrices using recursion.


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int** add(int n,int **a,int **b);
int** sub(int n,int **a,int **b);
void split(int n,int **f,int **ch,int op,int en);
void merge(int n,int **ch,int **f,int op,int en);
void printmatrix(int n,int **arr);
int** multiply(int n,int **a,int **b)
{
    // initialising the resultant matrix dynamically.
    int **result;
    result = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
    {
        result[i] = malloc(sizeof(int*)*n);
    }
    if(n==1)
    {
        result[0][0]=a[0][0]*b[0][0];
    }
    else
    {
       // Initialising samller submatrices required to get for the resultant matrix.
        int **a11,**a12,**a21,**a22,**b11,**b12,**b22;
        int** b21;
        a11 = malloc(sizeof(int*) * n/2);
        a12 = malloc(sizeof(int*) * n/2);
        a21 = malloc(sizeof(int*) * n/2);
        a22 = malloc(sizeof(int*) * n/2);
        b11 = malloc(sizeof(int*) * n/2);
        b12 = malloc(sizeof(int*) * n/2);
        b21 = malloc(sizeof(int*) * n/2);
        b22 = malloc(sizeof(int*) * n/2);
        for(int i = 0; i < n/2; i++)
        {
            a11[i] = malloc(sizeof(int*) * n/2);
            a12[i] = malloc(sizeof(int*) * n/2);
            a21[i] = malloc(sizeof(int*) * n/2);
            a22[i] = malloc(sizeof(int*) * n/2);
            b11[i] = malloc(sizeof(int*) * n/2);
            b12[i] = malloc(sizeof(int*) * n/2);
            b21[i] = malloc(sizeof(int*) * n/2);
            b22[i] = malloc(sizeof(int*) * n/2);
        }

        // splitting the 1st matrix into 4 equal parts
        split(n,a,a11,0,0);
        split(n,a,a12,0,n/2);
        split(n,a,a21,n/2,0);
        split(n,a,a22,n/2,n/2);

        // splitting the 2nd matrix into 4 equal parts
        split(n,b,b11,0,0);
        split(n,b,b12,0,n/2);
        split(n,b,b21,n/2,0);
        split(n,b,b22,n/2,n/2);

      // Initialising samller submatrices required to get for the resultant matrix.
         int **M1,**M2,**M3,**M4,**M5,**M6,**M7,**C11,**C12,**C21,**C22;
          M1 = malloc(sizeof(int*) * n/2);
          M2 = malloc(sizeof(int*) * n/2);
          M3 = malloc(sizeof(int*) * n/2);
          M4 = malloc(sizeof(int*) * n/2);
          M5 = malloc(sizeof(int*) * n/2);
          M6 = malloc(sizeof(int*) * n/2);
          M7 = malloc(sizeof(int*) * n/2);
          C11 = malloc(sizeof(int*) * n/2);
          C12 = malloc(sizeof(int*) * n/2);
          C21 = malloc(sizeof(int*) * n/2);
          C22 = malloc(sizeof(int*) * n/2);
         for(int i = 0; i < n/2; i++)
         {
            M1[i] = malloc(sizeof(int*) * n/2);
            M2[i] = malloc(sizeof(int*) * n/2);
            M3[i] = malloc(sizeof(int*) * n/2);
            M4[i] = malloc(sizeof(int*) * n/2);
            M5[i] = malloc(sizeof(int*) * n/2);
            M6[i] = malloc(sizeof(int*) * n/2);
            M7[i] = malloc(sizeof(int*) * n/2);
            C11[i] = malloc(sizeof(int*) * n/2);
            C12[i] = malloc(sizeof(int*) * n/2);
            C21[i] = malloc(sizeof(int*) * n/2);
            C22[i] = malloc(sizeof(int*) * n/2);
         }

     // Forming the matrices using appropriate steps involved in strassen's algorithm.
            M1=multiply(n/2,add(n/2,a11,a22),add(n/2,b11,b22));
            M2=multiply(n/2,add(n/2,a21,a22),b11);
            M3=multiply(n/2,a11, sub(n/2,b12, b22));
            M4=multiply(n/2,a22,sub(n/2,b21,b11));
            M5=multiply(n/2,add(n/2,a11,a12),b22);
            M6=multiply(n/2,sub(n/2,a21,a11),add(n/2,b11,b12));
            M7=multiply(n/2,sub(n/2,a12,a22),add(n/2,b21,b22));



          C11=add(n/2,sub(n/2,add(n/2,M1,M4),M5),M7);
          C12=add(n/2,M3,M5);
          C21=add(n/2,M2,M4);
          C22=add(n/2,sub(n/2,add(n/2,M1, M3), M2), M6);


            merge(n,C11,result, 0 , 0);
            merge(n,C12,result, 0 , n/2);
            merge(n,C21,result, n/2, 0);
            merge(n,C22,result, n/2, n/2);

    }
    return result;//Returning the resultant matrix.

}
void split(int n,int **f,int **ch,int op,int en)//Function to split the matrix into it's subparts.
{
     for(int i=0,x=op;i<n/2;i++,x++)
     {
         for(int j=0,y=en;j<n/2;j++,y++)
         {
             ch[i][j]=f[x][y];
         }
     }
}
int** add(int n,int **a,int **b) //Function to add two matrices.
{
    int **result;
    result = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++) {
        result[i] = malloc(sizeof(int*) * n);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[i][j]=a[i][j]+b[i][j];
        }
    }
    return result;
}
int** sub(int n,int **a,int **b) //Function to subtract two matrices.
{
    int **result;
    result = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++) {
        result[i] = malloc(sizeof(int*) * n);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[i][j]=a[i][j]-b[i][j];
        }
    }
    return result;
}

void merge(int n,int **ch,int **f,int op,int en) //Function to merge sub-matrices into the main/resultant matrix.
{
    for(int i=0,x=op;i<n/2;i++)
    {
        for(int j=0,y=en;j<n/2;j++)
        {
            f[x][y]=ch[i][j];
            y++;
        }
        x++;
    }
}
void printmatrix(int n,int **arr)// Function to print the matrix.
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int isPowerOfTwo (int x)// Function to check if the order of the input matrix is in the power of 2 or not.
{
  return x && (!(x&(x-1)));
}
int main  () {
    int n;
    printf("Enter the order of matrix:-");
    scanf("%d",&n);
    if(isPowerOfTwo(n)==0)
    printf("The order of the matrices should be a power of 2 only. TRY AGAIN!!!!.\n");
    else
    {
    int **matrix1,**matrix2;// Initialising the two input matrices.
    matrix1 = malloc(sizeof(int*) * n);

    for(int i = 0; i < n; i++) {
        matrix1[i] = malloc(sizeof(int*) * n);
    }

        matrix2 = malloc(sizeof(int*) * n);

    for(int i = 0; i < n; i++) {
        matrix2[i] = malloc(sizeof(int*) * n);
    }

    printf("Enter the matrix 1:-\n");//Taking inputs for the 1st matrix.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter the matrix 2:-\n");//Taking inputs for the 2nd matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
        clock_t start=clock();
        int **ans;
         printf("The multiplication of both the matrices are as follows:-\n");
         ans=multiply(n,matrix1,matrix2);
        printmatrix(n,ans);
        clock_t end=clock();
        printf("\nTotal time in ms :-%u",end-start); // Time elapsed to execute the code.
    }
return 0;
}

// TIME COMPLEXITY :-  O(n^2.80)
// SPACE COMPLEXITY :-  O(n^2)
// By Aaryan Gupta
