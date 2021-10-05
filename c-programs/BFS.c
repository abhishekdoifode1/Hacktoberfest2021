//C program to create a spanning tree from a given graph using BFS algorithm.
#include <stdio.h> //including the standard input-output header file

int q[20], front = -1, rear = -1, a[20][20], vis[20];
//declaring global variables

//to add the element to the maintained Queue
void add(int item)
{
    if (rear == 19) //condition for checking for QUEUE Overflow
        printf("QUEUE FULL");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}
//to delete the element from the maintained Queue
int delete ()
{
    int k;
    if ((front > rear) || (front == -1)) //condition to check for Empty Queue
        return 0;
    else
    {
        k = q[front++];
        return k;
    }
}

//Breadth First Search recursive algorithm
void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete ();
    if (p != 0)
        printf(" %c", (p + 64));
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = delete ();
        if (p != 0)
            printf(" %c ", (p + 64));
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n); //invoking the function recursively
}

//the main() function from where execution begins
void main()
{
    int n, i, j;
    char s;
    //declaring local variables

    printf("Total Number Of Vertices: ");
    scanf("%d", &n); //accepting the total number of vertices

    printf("Enter The ADJACENCY MATRIX:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
        vis[i] = 0;
    scanf("%c");
    printf("\nStarting Vertex: ");
    scanf("%c", &s); //accepting the vertex from where traversal starts
    printf("\nAfter BFS, the SPANNING TREE : ");
    bfs(((int)s - 64), n); //invoking the BFS function
}
//end of program
//Contributed by - Dipanjan Dutta
