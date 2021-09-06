// https://www.interviewbit.com/problems/balanced-binary-tree/

/*
Given a binary tree, determine if it is height-balanced.

Height-balanced binary tree  : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 
*/

// Recursive solution
// Time complexity:- O(n)
// Space complexity:- O(h)

int checkHeightBalanced(TreeNode* A,bool& ans)
{
    if(A==NULL)
        return 0;
    if(A->left==NULL && A->right==NULL)
        return 1;
    int lH = checkHeightBalanced(A->left,ans);
    int rH = checkHeightBalanced(A->right,ans);
    int h = max(lH,rH)+1;
    if(abs(lH-rH)>1)
        ans=false;

    return h;

}

int Solution::isBalanced(TreeNode* A) 
{
    if(A==NULL)
        return 1;
    if(A->left==NULL && A->right==NULL)
        return 1;
    bool ans=true;
    int  p = checkHeightBalanced(A,ans);
    if(ans==true)
        return 1;
    return 0;
}
