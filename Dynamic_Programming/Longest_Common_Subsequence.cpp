// https://www.interviewbit.com/problems/longest-common-subsequence/
/* Problem Description
Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.
You need to return the length of such longest common subsequence.

Problem Constraints
1 <= |A|, |B| <= 1005

Input Format
First argument is an string A.
Second argument is an string B.

Output Format
Return the length of such longest common subsequence between string A and string B.

Example Input
Input 1:
A = "abbcdgf"
B = "bbadcgf"


Example Output
Output 1:
 5

Example Explanation
Explanation 1:
 The longest common subsequence is "bbcgf", which has a length of 5
*/
// m,n are lengths of string

// Brute force recursive soln
// Time complexity:- O(2^(m+n))
// Space complexity:- O(max(m,n))

int getLCS(string A, string B, int i, int j, int m, int n, vector<vector<int>>& dp)
{
    if((i==m) || (j==n))
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(A[i]==B[j])
    {
        dp[i][j] = 1+getLCS(A, B, i+1, j+1, m, n, dp);
    }
    else
    {
        dp[i][j] = max(getLCS(A, B, i+1, j, m, n, dp), getLCS(A, B, i, j+1, m, n, dp)); 
    }
    return dp[i][j];
}

int Solution::solve(string A, string B) 
{
    int m = A.length();
    int n = B.length();
    if(A==B)
        return m;
    if(m==0 || n==0)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return getLCS(A, B, 0, 0, m, n, dp);
}

// Memoization soln
// Time complexity:- O(m*n)
// Space complexity:- O(max(m,n))

int getLCS(string A, string B, int i, int j, int m, int n, vector<vector<int>>& dp)
{
    if((i==m) || (j==n))
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(A[i]==B[j])
    {
        dp[i][j] = 1+getLCS(A, B, i+1, j+1, m, n, dp);
    }
    else
    {
        dp[i][j] = max(getLCS(A, B, i+1, j, m, n, dp), getLCS(A, B, i, j+1, m, n, dp)); 
    }
    return dp[i][j];
}

int Solution::solve(string A, string B) 
{
    int m = A.length();
    int n = B.length();
    if(A==B)
        return m;
    if(m==0 || n==0)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return getLCS(A, B, 0, 0, m, n, dp);
}

