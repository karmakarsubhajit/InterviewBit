//https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
/*
Given a binary tree, flatten it to a linked list in-place.

Example :

Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.
*/

// Right Left Root traversal of Binary Tree
// Time complexity:- O(n) 
// Space complexity:- O(h)

void flattenBT_to_LL(TreeNode* A,TreeNode** prev)
{
    if(A==NULL)
        return;
    flattenBT_to_LL(A->right,prev);
    flattenBT_to_LL(A->left,prev);
    A->right = *prev;
    A->left = NULL;
    *prev = A;
}

TreeNode* Solution::flatten(TreeNode* A) 
{
    TreeNode* prev=NULL;
    flattenBT_to_LL(A,&prev);
    return A;
}
