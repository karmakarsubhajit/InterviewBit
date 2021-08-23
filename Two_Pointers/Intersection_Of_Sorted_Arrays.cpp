// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

/*
Problem Description

Find the intersection of two sorted arrays. OR in other words, Given 2 sorted arrays, find all the elements which occur in both the arrays.
Example:
Input:
    A: [1 2 3 3 4 5 6]
    B: [3 3 5]
Output: [3 3 5]

Input:
    A: [1 2 3 3 4 5 6]
    B: [3 5]

Output: [3 5]
*/

// Time complexity:- O(n+m)
// Space complexity:- O(1)

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) 
{
    int m = A.size();
    int n = B.size();
    int i = 0;
    int j = 0;
    
    vector<int> v;
    while(i<m && j<n)
    {
        if(A[i]<B[j])
        {
            i++;
        }
        else if(A[i]>B[j])
        {
            j++;
        }
        else
        {
            v.push_back(A[i]);
            i++;
            j++;
        }
    }
    return v;
}
