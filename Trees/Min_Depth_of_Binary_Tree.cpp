//https://www.interviewbit.com/problems/min-depth-of-binary-tree/
/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
min depth = 2.
*/

// Recursive soln
// Time complexity:- O(n)
// Space complexity:- O(n)

void dfs(TreeNode* A, int lev, int& mn)
{
    if(A==NULL)
        return;
    if((A->left==NULL) && (A->right==NULL))
    {
        mn = min(mn,lev);
        return;
    }
    dfs(A->left,lev+1,mn);
    dfs(A->right,lev+1,mn);
}


int Solution::minDepth(TreeNode* A) 
{
    int mn = INT_MAX;
    if(A==NULL)
        return 0;
    dfs(A,1,mn);
    return mn;
}
