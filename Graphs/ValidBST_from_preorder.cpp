// https://www.interviewbit.com/problems/valid-bst-from-preorder/
/*
Problem Description

You are given a preorder traversal A, of a Binary Search Tree.
Find if it is a valid preorder traversal of a BST.

Problem Constraints

1 <= A[i] <= 106
1 <= |A| <= 105

Input Format
First and only argument is an integer array A denoting the pre-order traversal.

Output Format

Return an integer:
0 : Impossible preorder traversal of a BST
1 : Possible preorder traversal of a BST

Example Input

Input 1:
A = [7, 7, 10, 10, 9, 5, 2, 8]

Example Output

Output 1:
 1
 
*/

// Using lower bound and upper bound of a BST node
// Time complexity:- O(n)
// Space complexity:- O(n)


void checkBST_from_preorder(vector<int> &preorder, int& i, int lower_limit, int upper_limit)
{
    if(i==preorder.size())
        return;
    if(preorder[i]<lower_limit || preorder[i]>upper_limit)
        return;
    int val = preorder[i];
    i++;
    checkBST_from_preorder(preorder,i,lower_limit,val);
    checkBST_from_preorder(preorder,i,val,upper_limit);

    return;
}


int Solution::solve(vector<int> &preorder) 
{
    int i = 0;
    checkBST_from_preorder(preorder, i, INT_MIN, INT_MAX);
    return i==preorder.size();
}
