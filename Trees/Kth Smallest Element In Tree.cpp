// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
NOTE : You may assume 1 <= k <= Total number of nodes in BST
*/

// Using priority queue
// Time complexity:- O(n+klogk)
// Space complexity:- O(max(h,k)), h is height of tree

void inorder(TreeNode* A, priority_queue<int, vector<int>>& pq, int k)
{
    if(A==NULL)
        return;
    inorder(A->left,pq,k);
    pq.push(A->val);
    if(pq.size()>k)
    {
        pq.pop();
    }
    inorder(A->right,pq,k);
}


int Solution::kthsmallest(TreeNode* A, int B) 
{
    priority_queue<int, vector<int>> pq;
    inorder(A,pq,B);
    return pq.top();
}
