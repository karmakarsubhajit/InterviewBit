//https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 

Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]
*/

// BFS traversal
// Time complexity:- O(n)
// Space complexity:- O(n)

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* A) 
{
    vector<vector<int>> ans;
    if(A==NULL)
        return ans;
    queue<TreeNode*> q;
    q.push(A);
    int c = 0;
    while(q.size()!=0)
    {
        int n = q.size();
        vector<int> v(n,0); 
        for(int i=0;i<n;i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(c==0)
                v[i] = curr->val;
            else
                v[n-1-i] = curr->val;
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        c = 1-c;
        ans.push_back(v);
    }
    return ans;
}
