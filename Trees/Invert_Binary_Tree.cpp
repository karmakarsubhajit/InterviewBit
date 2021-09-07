// https://www.interviewbit.com/problems/invert-the-binary-tree/
/*
Problem Description

Given a binary tree A, invert the binary tree and return it. 

 Inverting refers to making left child as the right child and vice versa.



Problem Constraints
1 <= size of tree <= 100000



Input Format
First and only argument is the head of the tree A.



Output Format
Return the head of the inverted tree.



Example Input
Input 1:

 
     1
   /   \
  2     3
Input 2:

 
     1
   /   \
  2     3
 / \   / \
4   5 6   7


Example Output
Output 1:

 
     1
   /   \
  3     2
Output 2:

 
     1
   /   \
  3     2
 / \   / \
7   6 5   4


Example Explanation
Explanation 1:

Tree has been inverted.
Explanation 2:

Tree has been inverted.
*/

// Time complexity:- O(n)
// Space complexity:- O(height)

TreeNode* invertedRoot(TreeNode* A)
{
    if(A==NULL)
        return A;
    TreeNode* lft = invertedRoot(A->left);
    TreeNode* rgt = invertedRoot(A->right);
    TreeNode* temp = lft;
    lft = rgt;
    rgt=temp;
    A->left = lft;
    A->right = rgt;
    return A;
}

TreeNode* Solution::invertTree(TreeNode* A) 
{
    return invertedRoot(A);
}

// Iterative level order approach
// Time complexity:- O(n)
// Space complexity:- O(n/2) = O(n)

void swapNode(TreeNode** a, TreeNode** b)
{
    TreeNode* temp = *a;
    *a = *b;
    *b = temp;
}

TreeNode* Solution::invertTree(TreeNode* A) 
{
    if(A==NULL)
        return A;
    queue<TreeNode*> q;
    q.push(A);
    while(q.size()!=0)
    {
        TreeNode* curr = q.front();
        q.pop();
        TreeNode* p = curr->left;
        curr->left = curr->right;
        curr->right = p;
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    return A;
}
