// https://www.interviewbit.com/problems/symmetric-binary-tree/
/*
Problem Description
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).


Problem Constraints
1 <= number of nodes <= 105

Input Format
First and only argument is the root node of the binary tree.

Output Format
Return 0 / 1 ( 0 for false, 1 for true ).


Example Input
Input 1:

    1
   / \
  2   2
 / \ / \
3  4 4  3
Input 2:

    1
   / \
  2   2
   \   \
   3    3


Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explanation 1:
 The above binary tree is symmetric. 
 
Explanation 2:
The above binary tree is not symmetric.
*/

//Recursive approach
// Time complexity:- O(n)
// Space complexity:- O(h), h is max height of tree

bool getAns(TreeNode* r1, TreeNode* r2)
{
    if(r1==NULL && r2!=NULL)
        return false;
    else if(r1!=NULL && r2==NULL)
        return false;
    else if(r1==NULL && r2==NULL)
        return true;
    else
    {
        if(r1->val==r2->val)
        {
            return getAns(r1->left,r2->right)&&getAns(r1->right,r2->left);
        }
        else
            return false;
    }
}

int Solution::isSymmetric(TreeNode* A) 
{
    if(A==NULL)
        return true;
    return getAns(A->left,A->right);
}
