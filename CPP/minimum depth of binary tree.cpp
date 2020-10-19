//problem link: https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1
//FUNCTION PROBLEM
int minDepth(Node *node) {
    //👀We initialise ld and rd as INT_MAX for the cases when node->left!=NULL &
    //node->right==NULL or if left is null and right is not null . In first case,
    //rd me hum INT_MAX store kraenge tabhi wo min me ld ka value return karega
    //apne parent ko
    int ld=INT_MAX,rd=INT_MAX;
    if(node->left==NULL&&node->right==NULL)
        return 1;
    if(node->left)
        ld=minDepth(node->left);
    if(node->right)
        rd=minDepth(node->right);

    //😋 😋 After, calculating ld and rd at every level and return minimum of the two to
    //above recursion calls that can be used for further calculation of minimum depth
    return 1+min(ld,rd);

}
