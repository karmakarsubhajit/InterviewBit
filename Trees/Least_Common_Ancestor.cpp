// https://www.interviewbit.com/problems/least-common-ancestor/
/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

LCA = Lowest common ancestor

Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

*/


// DFS solution || 2 pass
// Time complexity:- O(n)
// Space complexity:- O(h)

void nodeSearch(TreeNode* root, int B, int C, bool &sB, bool &sC)
{
    if(root==NULL)
        return;
    if(root->val==B)
    {
        sB=true;
    }
    if(root->val==C)
    {
        sC=true;
    }
    
    nodeSearch(root->left, B, C,sB,sC);
    nodeSearch(root->right, B, C,sB,sC);
     
}




TreeNode* findLCA(TreeNode* root, int B, int C)
{
    if(root==NULL)
        return NULL;
    if((root->val==B) || (root->val==C))
        return root;
    TreeNode* lf = findLCA(root->left, B, C);
    TreeNode* rt = findLCA(root->right, B, C);
    if((lf==NULL)&&(rt==NULL))
        return NULL;
    else if((lf!=NULL)&&(rt!=NULL))
        return root;
    else if(lf!=NULL)
        return lf;

    return rt;
     
}

int Solution::lca(TreeNode* A, int B, int C) 
{
    bool sB=false;
    bool sC=false;
    nodeSearch(A,B,C,sB,sC);
    if((sB==false)||(sC==false))
        return -1;
    TreeNode* lc = findLCA(A, B, C);
    if(lc==NULL)
        return -1;
    return lc->val;
}
