// https://www.interviewbit.com/problems/preorder-traversal/
/*
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

*/

//Recursive soln
//Time complexity:- O(n)
//Space complexity:- O(n)

void preorder(TreeNode* root, vector<int>& ans)
{
    if(!root)
       return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans); 
}
 

vector<int> Solution::preorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    preorder(A,ans);
    return ans;
}


