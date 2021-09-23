//https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.

The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

*/


// DFS approach
// Time complexity:- O(n)
// Space complexity:- O(h), h is height of tree

void getSum(TreeNode* root, int val, int& ans)
{
    if(root==NULL)
        return;
    int curr = (((val)%1003*10)%1003 + (root->val)%1003)%1003;
    if((root->left==NULL)&&(root->right==NULL))
    {
        ans= (ans%1003+curr%1003)%1003;
        return;
    }
    getSum(root->left,curr,ans);
    getSum(root->right,curr,ans);
}


int Solution::sumNumbers(TreeNode* A) 
{
    if(A==NULL)
        return 0;
    if((A->left==NULL)&&(A->right==NULL))
    {
        return A->val%1003;
    }
    int ans = 0;
    getSum(A,0,ans);
    return ans;
}



// BFS approach
// Time complexity:- O(n)
// Space complexity:- O(n/2)

int Solution::sumNumbers(TreeNode* A) 
{
    if(A==NULL)
        return 0;
    if((A->left==NULL)&&(A->right==NULL))
    {
        return A->val%1003;
    }
    int ans = 0;
    queue<pair<TreeNode*,int>> q;
    q.push(make_pair(A , 0));
    while(q.empty()!=1)
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            int curr_val =  ((((curr.second)%1003)*10)%1003 + (curr.first->val)%1003)%1003;
            if((curr.first->left==NULL)&&(curr.first->right==NULL))
            {
                ans =(ans%1003+curr_val%1003)%1003;
                continue;
            }
            if(curr.first->left!=NULL)
                q.push(make_pair(curr.first->left,curr_val));
            if(curr.first->right!=NULL)
                q.push(make_pair(curr.first->right,curr_val));
        }
    }
    
    return ans;
}
