#include<bits/stdc++.h>
#include<queue>
using namespace std;
int sumoflevel[100] = {0};

struct BstNode 
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode (int data)
{
    BstNode* newNode = new BstNode ();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* ConstructTree (int pre[], int* preIndex, int low, int high, int size)
{
    if (*preIndex >= size || low > high)
        return NULL;

    BstNode* root = GetNewNode (pre[*preIndex]);
    *preIndex = *preIndex + 1;
 
    if (low == high)
        return root;

    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;
 
    root->left = ConstructTree (pre, preIndex, *preIndex, i - 1, size);
    root->right = ConstructTree (pre, preIndex, i, high, size);
    return root;
}

BstNode* BuildTree (int pre[], int size)
{
    int preIndex = 0;
    return ConstructTree (pre, &preIndex, 0, size - 1, size);
}

int SumOfLevel (BstNode* root, int k)
{
    if (root == NULL)
        return 0;
  
    queue<struct BstNode*> que;
  
    que.push(root);
    int level = 1;
    int sum = 0;
    int flag = 0;
  

    while (!que.empty()) 
    {
        int size = que.size();
        while (size--)
        {
            BstNode* ptr = que.front();
            que.pop();

            if (level == k) 
            {
                flag = 1;
                sum += ptr->data;
            }
            else 
            { 
                if (ptr->left)
                    que.push(ptr->left);
                if (ptr->right)
                    que.push(ptr->right);
            }
        }
        level++;
        if (flag == 1)
            break;
    }
    return sum;
}

int main ()
{
    BstNode* root = NULL;
    int sum = 0;
    int n, level, l;
    cin >> n;
    int pre [n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre [i];
    }

    root = BuildTree (pre, n);
    cin >> l;
    for (int i = 1; i <= l; i++)
    {
        cin >> level;
        sum += SumOfLevel (root, level);
    }
    cout << sum;
    return 0;
}
