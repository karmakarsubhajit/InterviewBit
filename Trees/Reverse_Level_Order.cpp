// https://www.interviewbit.com/problems/reverse-level-order/

/*
Problem Description
Given a binary tree, return the reverse level order traversal of its nodes values. (i.e, from left to right and from last level to starting level).

Problem Constraints
1 <= number of nodes <= 5 * 105
1 <= node value <= 105

Input Format
First and only argument is a pointer to the root node of the Binary Tree, A.


Output Format
Return an integer array denoting the reverse level order traversal from left to right.

Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [15, 7, 9, 20, 3] 
Output 2:

 [3, 6, 2, 1]


Example Explanation
Explanation 1:
 Nodes as level 3 : [15, 7]
 Nodes at level 2: [9, 20]
 Nodes at level 1: [3]
 Reverse level order traversal will be: [15, 7, 9, 20, 3]
 
Explanation 2:
 Nodes as level 3 : [3]
 Nodes at level 2: [6, 2]
 Nodes at level 1: [1]
 Reverse level order traversal will be: [3, 6, 2, 1]
*/

// DFS approach
// Time complexity:- O(n)
// Space complexity:- O(n) (wosrt case stack space) + O(n) (2D vector to store nodes) = O(n)

void getAns(TreeNode* A, int lev, vector<vector<int>>& ans)
{
    if(A==NULL)
        return;
    if(lev==ans.size())
    {
        vector<int> v;
        ans.push_back(v);
    }
    ans[lev].push_back(A->val);
    if(A->left!=NULL)
        getAns(A->left,lev+1,ans);
    if(A->right!=NULL)
        getAns(A->right,lev+1,ans);
}

vector<int> Solution::solve(TreeNode* A) 
{
    vector<vector<int>> ans;
    vector<int> p;
    if(A==NULL)
        return p;
    getAns(A, 0, ans);
    int n = ans.size();
    for(int i=n-1;i>=0;i--)
    {
        vector<int> s = ans[i];
        for(auto j:s)
            p.push_back(j);
    }
    return p;
}
