https://www.interviewbit.com/problems/level-order/

//DFS Solution

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
