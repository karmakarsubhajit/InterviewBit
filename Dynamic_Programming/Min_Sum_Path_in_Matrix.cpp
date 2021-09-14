//https://www.interviewbit.com/problems/min-sum-path-in-matrix/
/*
Problem Description

Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time. 



Input Format
First and only argument is an 2D integer array A of size M x N.

Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).

Example Input
Input 1:

 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]


Example Output

Output 1:
 9

Example Explanation
Explanation 1:

 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8

*/

// DP solution
// Time complexity:- O(m*n)
// Space complexity:- O(m*n)

int Solution::minPathSum(vector<vector<int> > &A) 
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    
    dp[m-1][n-1] = A[m-1][n-1];
    for(int i=m-2;i>=0;i--)
    {
        dp[i][n-1] = A[i][n-1]+dp[i+1][n-1];
    }
    
    for(int j=n-2;j>=0;j--)
    {
        dp[m-1][j] = A[m-1][j] + dp[m-1][j+1];  
    }
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            int mn = min(dp[i+1][j],dp[i][j+1]);
            dp[i][j]=A[i][j]+mn;
        }
    }
    return dp[0][0];
}




// Space optimised solution || Modifying the grid itself || No extra matrix
// Time complexity:- O(m*n)
// Space complexity:- O(1)

int Solution::minPathSum(vector<vector<int> > &A) 
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    
    
    for(int i=m-2;i>=0;i--)
    {
        A[i][n-1] = A[i][n-1]+A[i+1][n-1];
    }
    
    for(int j=n-2;j>=0;j--)
    {
        A[m-1][j] = A[m-1][j] + A[m-1][j+1];  
    }
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            int mn = min(A[i+1][j],A[i][j+1]);
            A[i][j]=A[i][j]+mn;
        }
    }
    return A[0][0];
}

