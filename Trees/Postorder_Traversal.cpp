// https://www.interviewbit.com/problems/postorder-traversal/

/*
Given a binary tree, return the Postorder traversal of its nodes values.

NOTE: Using recursion is not allowed.



Problem Constraints
 1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return an integer array denoting the Postorder traversal of the given binary tree.



Example Input
Input 1:

   1
    \
     2
    /
   3
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [3, 2, 1]
Output 2:

 [6, 3, 2, 1]


Example Explanation
Explanation 1:

 The Preoder Traversal of the given tree is [3, 2, 1].
Explanation 2:

 The Preoder Traversal of the given tree is [6, 3, 2, 1].

*/

// Time complexity:- O(n)
// SPace complexity:- O(n)

void getAns(TreeNode* A, vector<int>& ans)
{
    if(A==NULL)
        return;
    getAns(A->left,ans);
    getAns(A->right, ans);
    ans.push_back(A->val);
}

vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    getAns(A,ans);
    return ans;
}
