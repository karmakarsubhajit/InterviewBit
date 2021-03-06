//https://www.interviewbit.com/problems/cousins-in-binary-tree/
/*
Problem Description

Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.


Problem Constraints
 1 <= N <= 105 

 1 <= B <= N



Input Format
First Argument represents the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [6, 7]
Output 2:

 []


Example Explanation
Explanation 1:

 Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
 Remember Node 4 is sibling of Node 5 and do not need to return this.
Explanation 2:

 Since Node 1 is the root so it doesn't have any cousin so we will return an empty array.

*/


// DFS || Two pass
// Time Complexity:- O(n)
// Space Complexity:- O(n)


int findLevel(TreeNode* root, int B,int lev)
{
    if(root==NULL)
        return 0;
    if(root->val==B)
        return lev;
    int ans = findLevel(root->left, B, lev+1);
    if(ans!=0)
        return ans;
    return findLevel(root->right, B, lev+1);
}

void getCousins(TreeNode* A, int B, vector<int>& ans , int lev)
{
    if(A==NULL || lev<=1)
        return;
    if(lev==2)
    {
        if((A->left!=NULL && A->left->val==B)||(A->right!=NULL && A->right->val==B))
            return;
        if(A->left!=NULL)
            ans.push_back(A->left->val);
        if(A->right!=NULL)
            ans.push_back(A->right->val);
    }
    getCousins(A->left,B,ans,lev-1);
    getCousins(A->right,B,ans,lev-1);
}

vector<int> Solution::solve(TreeNode* A, int B) 
{
   int lev = findLevel(A,B,1);
   vector<int> ans;
   getCousins(A,B,ans,lev);
   return ans;
}


// BFS || Level Order || One pass || Optimal
// Time Complexity:- O(n)
// Space Complexity:- O(n)

vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int> v;
    if(A->val==B)
        return v;
    if(A->left!=NULL && A->left->val==B)
        return v;
    if(A->right!=NULL && A->right->val==B)
        return v;
    queue<TreeNode*> q;
    q.push(A);
    bool found=false;
    while((q.size()!=0) && (found==false))
    {
        int n = q.size();
        for(int i=1;i<=n;i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if((curr->left!=NULL && curr->left->val==B)||(curr->right!=NULL && curr->right->val==B))
            {
                found=true;
            }
            else
            {
                if(curr->left) 
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }   
    }
    while(q.size()!=0)
    {
        v.push_back(q.front()->val);
        q.pop();
    }
    return v;

}
