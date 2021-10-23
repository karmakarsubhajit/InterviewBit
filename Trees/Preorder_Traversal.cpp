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



//Iterative soln
//Time complexity:- O(n)
//Space complexity:- O(n)

vector<int> Solution::preorderTraversal(TreeNode* root) 
{
    stack<TreeNode*> st;
        vector<int> ans;
        if(root==NULL)
           return ans;
        st.push(root);
        while(1)
        {
            if(st.size()==0)
                break;
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            if(curr->right!=NULL)
                st.push(curr->right);
            if(curr->left!=NULL)
                st.push(curr->left);
        }
        return ans;

}

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


