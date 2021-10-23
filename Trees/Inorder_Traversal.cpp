//https://www.interviewbit.com/problems/inorder-traversal/
/*
Given a binary tree, return the inorder traversal of its nodes values.

NOTE: Using recursion is not allowed.



Problem Constraints
 1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return an integer array denoting the inorder traversal of the given binary tree.



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

 [1, 3, 2]
Output 2:

 [6, 1, 3, 2]


Example Explanation
Explanation 1:

 The Inorder Traversal of the given tree is [1, 3, 2].
Explanation 2:

 The Inorder Traversal of the given tree is [6, 1, 3, 2].
*/



//Iterative soln || Stack 
//Time complexity:- O(n)
//Space complexity:- O(n)


 
  vector<int> Solution::inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        TreeNode* curr = root;
        if(root==NULL)
            return ans;
        stack<TreeNode*> st;
        st.push(curr);
        curr=curr->left;
        while(1)
        {
            if(curr==NULL)
            {
                if(st.size()==0)
                    break;
                TreeNode* tp = st.top();
                st.pop();
                ans.push_back(tp->val);
                curr = tp->right;
            
            }
            else
            {
                st.push(curr);
                curr=curr->left;
            }
        }
        return ans;
    }

//Recursive soln
//Time complexity:- O(n)
//Space complexity:- O(n)


void inorder(TreeNode* root, vector<int>& ans)
{
    if(!root)
       return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans); 
}

vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    inorder(A,ans);
    return ans;
}



//Morris Inorder Traversal soln || Constant Space
//Time complexity:- O(n)
//Space complexity:- O(1)

 
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    TreeNode* curr= A;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else
        {
            TreeNode* temp = curr->left;
            TreeNode* prev = curr->left;
            while(prev->right!=NULL)
            {
                prev=prev->right;
            }
            prev->right = curr;
            curr->left=NULL;
            curr = temp;
        }
    }
 
    return ans;
}
