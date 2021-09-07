// https://www.interviewbit.com/problems/path-sum/
/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
Example :
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

// Time complexity:- O(n)
// Space complexity:- O(h)

bool hasPath(TreeNode* A, int B, int sm)
{
    if(A==NULL)
        return false;
    sm+=A->val;
    if((sm==B) && (A->left==NULL) && (A->right==NULL))
        return true;
    bool ans = false;
    ans = ans || hasPath(A->left,B, sm);
    ans = ans || hasPath(A->right,B,sm); 
    return  ans;
}

int Solution::hasPathSum(TreeNode* A, int B) 
{
    return hasPath(A,B,0);
}
