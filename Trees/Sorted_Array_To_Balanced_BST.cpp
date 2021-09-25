//https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3

*/

// Dividing the array at midpoint and recursively calling left and right subtree
// Time complexity:- O(n), n is length of array A
// Space complexity:- O(log2(n))

TreeNode* makeTree(int l, int r, const vector<int>& A)
{
    if(l>r)
        return NULL;
    if(l==r)
        return new TreeNode(A[l]);
    int md = l+(r-l)/2;
    TreeNode* root = new TreeNode(A[md]);
    root->left = makeTree(l,md-1,A);
    root->right = makeTree(md+1,r,A);
    return root;
}


TreeNode* Solution::sortedArrayToBST(const vector<int> &A) 
{
    int l = A.size();
    return makeTree(0,l-1,A);

}
