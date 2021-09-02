//https://www.interviewbit.com/problems/max-depth-of-binary-tree/
/*
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
max depth = 2.

*/

// Time complexity:- O(n)
// Space complexity:- O(n), stack space

int Solution::maxDepth(TreeNode* A) 
{
   if(A==NULL)
      return 0;
    if(A->left==NULL && A->right==NULL)
       return 1;
    return 1+max(maxDepth(A->left),maxDepth(A->right));
}
