//https://www.interviewbit.com/problems/construct-bst-from-preorder/
/*
Problem Description
 

Given an integer array A with distinct elements, which represents the preorder traversal of a binary search tree,
construct the tree and return its root.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

**Problem Constraints**
1 <= |A| <= 105
1 <= A.val <= 109
The given array is a valid preorder traversal of a BST.

**Input Format**
The first argument is an integer array denoting the preorder traversal.


**Output Format**
Return the root of the Binary Search Tree.


**Example Input**
Input 1:
A = [2, 1, 4, 3, 5]

Input 2:
A = [1, 2, 3]



**Example Output**
Output 1:

    2
   / \
  1   4
     / \
    3   5

Output 2:

      1
     /
    2
   /
  3


**Example Explanation**
Explanation 1:
We can see that is the tree created by the given pre order traversal.

Explanation 2:
We can see that is the tree created by the given pre order traversal.

*/

// Using lower bound and upper bound of a node in BST
// Time complexity:- O(n)
// Space complexity:- O(n)

TreeNode* buildTree(vector<int>& preorder, int &i, int upper_limit)
{
    if(i==preorder.size() || preorder[i]>upper_limit)
    {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[i]);
    i++;
    root->left = buildTree(preorder,i,root->val-1);
    root->right = buildTree(preorder,i,upper_limit);
    return root;
}

TreeNode* Solution::constructBST(vector<int> &preorder) 
{
    int i = 0;
    return buildTree(preorder,i,INT_MAX);
}




// Using insert node function of BST
// Time complexity:- O(n^2)
// Space complexity:- O(n)



TreeNode* insertNode(TreeNode* root, int val)
    {
        if(root==NULL)
        {
            TreeNode* root = new TreeNode(val);
            return root;
        }
        if(root->val>val)
        {
           root->left = insertNode(root->left,val);
            
        }
        else if(root->val<val)
        {
            root->right = insertNode(root->right,val);
        }
        
        return root;
    }
    
    


TreeNode* Solution::constructBST(vector<int> &preorder) 
{
    TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
        {
              root = insertNode(root,preorder[i]);
        }
        return root;
}

