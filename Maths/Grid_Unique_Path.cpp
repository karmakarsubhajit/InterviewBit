//https://www.interviewbit.com/problems/grid-unique-paths/
/*
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
How many possible unique paths are there?
Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
*/

// Time complexity:- O(min(m,n))
// Space complexity:- O(1)

int Solution::uniquePaths(int A, int B) 
{
    if((A==1) || (B==1))
        return 1;
    A--;
    B--;
    int mx = max(A,B);
    int mn = min(A,B);
    double ans= 1;
    int j = 1;
    for(int i=mx+1;i<=(mx+mn);i++,j++)
    {   
        ans = ans*(double)i;
        ans = ans/(double)j;
    }
    return (int)ans;
}
