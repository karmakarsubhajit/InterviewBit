// https://www.interviewbit.com/problems/burn-a-tree/
// https://www.geeksforgeeks.org/minimum-time-to-burn-a-tree-starting-from-a-leaf-node/

/*
Problem Description

Given a binary tree denoted by root node A and a leaf node B from this tree.

 It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree.



Problem Constraints
2 <= number of nodes <= 105

1 <= node value, B <= 105

node value will be distinct



Input Format
First argument is a root node of the binary tree, A.

Second argument is an integer B denoting the node value of leaf node.



Output Format
Return an integer denoting the minimum time required to burn the complete binary tree.



Example Input
Input 1:

 Tree :      1 
            / \ 
           2   3 
          /   / \
         4   5   6
 B = 4
Input 2:

 Tree :      1
            / \
           2   3
          /     \
         4       5 
 B = 5 


Example Output
Output 1:

 4
Output 2:

 4


Example Explanation
Explanation 1:

 After 1 sec: Node 4 and 2 will be burnt. 
 After 2 sec: Node 4, 2, 1 will be burnt.
 After 3 sec: Node 4, 2, 1, 3 will be burnt.
 After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.
 
Explanation 2:

 After 1 sec: Node 5 and 3 will be burnt. 
 After 2 sec: Node 5, 3, 1 will be burnt.
 After 3 sec: Node 5, 3, 1, 2 will be burnt.
 After 4 sec: Node 5, 3, 1, 2, 4(whole tree) will be burnt.

*/

// DFS approach || Two pass || (One pass)Construct Graph from Tree + (One pass) DFS traversal to find max depth of tree starting from B
// Time Complexity:- O(n)
// Space Complexity:- O(n)

void dfsGetTime(unordered_map<int,vector<TreeNode*>>& mp, int par, int src, int h, int& ans)
{
    ans=max(h,ans);
    for(auto p:mp[src])
    {
        if(p->val==par)
            continue;
        dfsGetTime(mp,src,p->val,h+1,ans);
    }
}

int Solution::solve(TreeNode* A, int B) 
{
    if(A==NULL)
        return 0;
    
    unordered_map<int,vector<TreeNode*>> mp;
    dfs(A,mp);
    int ans=0;
    dfsGetTime(mp,-1,B,0,ans);
    return ans;
}

// DFS approach || One pass 
// Time Complexity:- O(n)
// Space Complexity:- O(n)

struct subTree
{
    int ld=0;
    int rd=0;
    bool contains=false;
    int time = -1;
};

void burnTree(TreeNode* root, int B, subTree &r, int &ans)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->val==B)
        {
            r.contains=true;
            r.time=0;
        }
        return;
    }
    subTree left_subTree;
    burnTree(root->left,B,left_subTree,ans);
    subTree right_subTree;
    burnTree(root->right,B,right_subTree,ans);
    if(root->left!=NULL)
    {
        r.ld = 1+max(left_subTree.ld,left_subTree.rd);
    }
    if(root->right!=NULL)
    {
        r.rd = 1+max(right_subTree.rd , right_subTree.ld);
    }
    if((root->right!=NULL && right_subTree.contains==true)||(root->left!=NULL && left_subTree.contains==true))
        r.contains=true;
    if(root->left!=NULL && left_subTree.contains==true)
    {
        r.time=1+left_subTree.time;
    }
    else if(root->right!=NULL && right_subTree.contains==true)
    {
        r.time=1+right_subTree.time;
    }
    if(r.contains)
    {
        if(root->left!=NULL && left_subTree.contains==true)
        {
            ans=max(ans,r.time+r.rd);
        }
        else if(root->right!=NULL && right_subTree.contains==true)
        {
            ans=max(ans,r.time+r.ld);
        }
    }
}

int Solution::solve(TreeNode* A, int B) 
{
    if(A==NULL)
        return 0;
    
    subTree r;
    int ans=0;
    burnTree(A,B,r,ans);
    return ans;
}
