// https://www.interviewbit.com/problems/maximum-absolute-difference/
/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]
f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/

// Brute Force soln
// Time complexity:- O(n^2)
// Space complexity:- O(1)

int Solution::maxArr(vector<int> &A) 
{
    int n = A.size();
    int sm = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sm=max(sm, abs(A[j]-A[i])+abs(j-i));
        }
    }
    return sm;
}
