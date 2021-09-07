// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/


// Recursive soln || DFS
// Time complexity:- O(h*n/2) = O(nh)
// Space complexity:- O(height of tree)

void dfs(TreeNode* A, int B, int sm, vector<vector<int>>& ans, vector<int>& p)
{
    if(A==NULL)
    {
        return;
    }
    sm+=A->val;
    if((A->left==NULL) && (A->right==NULL))
    {
       if(sm==B)
       {
           p.push_back(A->val);
           ans.push_back(p);
           p.pop_back();
           return;
       } 
    }
    else
    {
        p.push_back(A->val);
        
        if(A->left)
            dfs(A->left, B, sm, ans,p);
        if(A->right)
            dfs(A->right,B,sm,ans,p);
        p.pop_back();
    }
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<int>> ans;
    vector<int> p;
    dfs(A, B, 0 , ans, p);
    return ans;
}



// Iterative soln || BFS || Level Order
// Time complexity:- O(h*n/2) = O(nh)
// Space complexity:- O(h*n/2) = O(nh)


struct node{
    TreeNode* n;
    int sm;
    vector<int> v;
};

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<int>> ans;
    vector<int> p;
    queue<node> q;
    node i;
    i.n = A;
    i.sm = 0;
    i.v = p;
    q.push(i);
    while(q.size()!=0)
    {
        int sz = q.size();
        for(int c=1;c<=sz;c++)
        {
            node curr = q.front();
            q.pop();
            TreeNode* n = curr.n;
            int sm = curr.sm;
            vector<int> v = curr.v;
            sm+=n->val;
            v.push_back(n->val);
            if((sm==B)&& (n->left==NULL) && (n->right==NULL))
            {
                ans.push_back(v);
            }
            if(n->left)
            {
                node tm;
                tm.n = n->left;
                tm.sm = sm;
                tm.v = v;
                q.push(tm);
            }
            if(n->right)
            {
                node tm;
                tm.n = n->right;
                tm.sm = sm;
                tm.v = v;
                q.push(tm);
            }
        }
    }

  
    return ans;
}

