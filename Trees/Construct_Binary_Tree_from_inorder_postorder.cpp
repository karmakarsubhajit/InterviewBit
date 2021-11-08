// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3
*/


// Time complexity:- O(n^2)
// Space complexity:- O(n)

int searchInorder(vector<int>& inorder, int val, int x, int y)
{
    for(int i=x;i<=y;i++)
    {
        if(inorder[i]==val)
            return i;
    }
    return x;
}

TreeNode* buildBinaryTree(vector<int>& postorder, vector<int> &inorder,int &i,  int l, int h)
{
    if(l>h)
        return NULL;

    TreeNode* root = new TreeNode(postorder[i]);
    i--;
    if(l==h)
        return root;
    int ind = searchInorder(inorder, root->val,l,h);
    root->right = buildBinaryTree(postorder,inorder,i,ind+1,h); 
    root->left = buildBinaryTree(postorder,inorder,i,l,ind-1);
    return root;
}


TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) 
{
    int i = inorder.size()-1;
    return buildBinaryTree(postorder,inorder,i,0,inorder.size()-1);
}


// Optimal solution using map
// Time complexity:- O(n)
// Space complexity:- O(n)

TreeNode* buildBinaryTree(vector<int>& postorder, unordered_map<int,int> &mp,int &i,  int l, int h)
{
    if(l>h)
        return NULL;

    TreeNode* root = new TreeNode(postorder[i]);
    i--;
    if(l==h)
        return root;
    int ind = mp[root->val];
    root->right = buildBinaryTree(postorder,mp,i,ind+1,h); 
    root->left = buildBinaryTree(postorder,mp,i,l,ind-1);
    return root;
}


TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) 
{
    int i = inorder.size()-1;
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
    return buildBinaryTree(postorder,mp,i,0,inorder.size()-1);
}
