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

// Brute Force
// Time complexity:- O(n^2)
// Space complexity:- O(n)


bool checkBST_from_preorder(vector<int> &preorder, int l, int r)
{
    if(l>r)
        return true;
    int val = preorder[l];
    if(l==r)
        return true;
    bool ans = true;

    int ind=l;
    int k=l+1;
    for(;k<=r;k++)
    {
        if(preorder[k]>val) 
        {
            break;
        }
    } 
    
    if(k>r)
        return true;
    else
    {
        ind = k;
        k++;
        for(;k<=r;k++)
        {
            if(preorder[k]<val)
            {
                return false;
            }
        }
        ans = ans ||  checkBST_from_preorder(preorder,l+1,ind-1) ||  checkBST_from_preorder(preorder,ind,r);
    }
    
    return ans;
}


int Solution::solve(vector<int> &preorder) 
{

    return checkBST_from_preorder(preorder, 0, preorder.size()-1);
}


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




