//  https://www.interviewbit.com/problems/identical-binary-trees/

/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True
*/

// Time complexity:- O(min(m,n)) , where m, n are no of nodes in Binary tree
// Space complexity:- O(min(h1,h2)) , stack space, h1, h2 heights of Binary tree

 bool getAns(TreeNode* A, TreeNode* B)
 {
     if(A==NULL && B!=NULL)
        return false;
    else if(A!=NULL && B==NULL)
        return false;
    else if(A==NULL && B==NULL)
        return true;
    else if(A!=NULL && B!=NULL)
    {
        return (A->val==B->val)&&getAns(A->left,B->left)&&getAns(A->right, B->right);
    }
 }

int Solution::isSameTree(TreeNode* A, TreeNode* B) 
{
    return getAns(A,B);
}
