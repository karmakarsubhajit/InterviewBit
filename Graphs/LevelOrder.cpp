https://www.interviewbit.com/problems/level-order/

//DFS Solution
// Time Complexity :- O(n) where n is no of nodes in binary tree
// Space Complexity  :- O(h) where h is height of the binary tree, in the worst case it will be O(n) for skewed binary tree.

void dfs(vector<vector<int>>& ans, int lev, TreeNode* A)
{
    if(A==NULL)
        return;
    if(ans.size()==lev)
    {
        vector<int> v1;
        ans.push_back(v1);
    }
    ans[lev].push_back(A->val);
    dfs(ans,lev+1,A->left);
    dfs(ans,lev+1,A->right);
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) 
{
    vector<vector<int>> ans;
    if(A==NULL)
        return ans;
    dfs(ans,0,A);
    return ans;
}


//BFS Solution
// Time Complexity :- O(n) where n is no of nodes in binary tree
//Space Complexity :- O(q) where q is maximum no of nodes in a level of the tree
// q = (n+1)/2 in last level of a full and complete binary tree
// So space complexity is O(n)                          
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

vector<vector<int> > Solution::levelOrder(TreeNode* A) 
{
    vector<vector<int>> ans;
    if(A==NULL)
        return ans;
    int level = 0;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty())
    {
        int sizeOfLevel = q.size();
        
        vector<int> temp;
    
        for(int i=0;i<sizeOfLevel;i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        ans.push_back(temp);
    }
    return ans;
}

