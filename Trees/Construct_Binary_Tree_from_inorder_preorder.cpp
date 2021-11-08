// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

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

TreeNode* buildBinaryTree(vector<int> &preorder, vector<int> &inorder, int &ind, int l, int h)
{
    if(l>h)
        return NULL;
    TreeNode* root = new TreeNode(preorder[ind]);
    ind++;
    if(l==h)
        return root;
    int index = searchInorder(inorder,root->val,l,h);
    root->left = buildBinaryTree(preorder,inorder, ind, l,index-1);
    root->right = buildBinaryTree(preorder,inorder,ind,index+1,h);
    return root;
}


TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) 
{
    int ind = 0;
    return buildBinaryTree(preorder,inorder,ind,0,preorder.size()-1);
}
