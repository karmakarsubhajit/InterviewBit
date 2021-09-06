//https://www.interviewbit.com/problems/max-depth-of-binary-tree/
/*
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
max depth = 2.

*/

// Recursive soln
// Time complexity:- O(n)
// Space complexity:- O(n), stack space

int Solution::maxDepth(TreeNode* A) 
{
   if(A==NULL)
      return 0;
    if(A->left==NULL && A->right==NULL)
       return 1;
    return 1+max(maxDepth(A->left),maxDepth(A->right));
}



// Iterative soln
// Time complexity:- O(n)
// Space complexity:- O(n/2) = O(n)


int Solution::maxDepth(TreeNode* A) 
{
   if(A==NULL)
      return 0;
    queue<TreeNode*> q;
    q.push(A);
    int depth = 0;
    while(q.size()!=0)
    {
        int n = q.size();
        for(int i=1;i<=n;i++)
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        depth++;
    }
    return depth;
    
}

