// https://www.interviewbit.com/problems/merge-two-binary-tree/
/*
Problem Description

Given two Binary Trees A and B, you need to merge them in a single binary tree.

The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.

Otherwise, the non-null node will be used as the node of new tree.



Problem Constraints
1 <= Number of Nodes in A , B <= 105



Input Format
First argument is an pointer to the root of binary tree A.

Second argument is an pointer to the root of binary tree B.



Output Format
Return a pointer to the root of new binary tree.



Example Input
Input 1:

 A =   2

      / \

     1   4

    /

   5


B =   3
      / \
      6  1
      \   \
       2   7

Input 2:

 A =   12

      / \

     11  14            


B =   3
      / \
      6  1



Example Output
Output 1:

     5
    / \
   7   5
  / \   \ 
 5   2   7
Output 2:

   15
  / \
 17  15


Example Explanation
Explanation 1:

 After merging both the trees you get:
     5
    / \
   7   5
  / \   \ 
 5   2   7
Explanation 2:

 After merging both the trees we get:
   15
  / \
 17  15
*/

// Recursive soln
// Time complexity:- O(m+n)  m,n no of nodes in both trees
// Space complexity:- O(max(h1,h2)) , h1,h2 heights of two trees

TreeNode* mergeTree(TreeNode* r1, TreeNode* r2)
{
    if(r1==NULL)
        return r2;
    if(r2==NULL)
        return r1;
    int sm = r1->val + r2->val;
    
    TreeNode* l = mergeTree(r1->left,r2->left);
    TreeNode* r = mergeTree(r1->right, r2->right);
    r1->val = sm;
    r1->left = l;
    r1->right = r;
    return r1;
}

TreeNode* Solution::solve(TreeNode* A, TreeNode* B) 
{
    TreeNode* ans = NULL;
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;
    return mergeTree(A, B);
}


