// https://www.interviewbit.com/problems/right-view-of-binary-tree/
/*
Problem Description

Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.



Problem Constraints
1 <= Number of nodes in binary tree <= 105

0 <= node values <= 109 



Input Format
First and only argument is an pointer to the root of binary tree A.



Output Format
Return an integer array denoting the right view of the binary tree A.



Example Input
Input 1:

        1
      /   \
     2    3
    / \  / \
   4   5 6  7
  /
 8 
Input 2:

    1
   /  \
  2    3
   \
    4
     \
      5


Example Output
Output 1:

 [1, 3, 7, 8]
Output 2:

 [1, 3, 4, 5]
*/

// DFS traversal
// Time complexity:- O(n)
// Space complexity:- O(h), where h is height of tree, in skewed tree it will be worst case of O(n)

void dfs(TreeNode* A, vector<int>& ans, int lev)
{
    if(A==NULL)
        return;
    if(ans.size()==lev)
        ans.push_back(A->val);
    if(A->right!=NULL)
        dfs(A->right, ans, lev+1);
    if(A->left!=NULL)
        dfs(A->left, ans, lev+1);
    return;    
}

vector<int> Solution::solve(TreeNode* A) 
{
    vector<int> ans;
    if(A==NULL)
        return ans;
    dfs(A,ans,0);
    return ans;
}
