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
// Space complexity:- O(m*n)

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



// Tabulation soln
// Time complexity:- O(m*n)
// Space complexity:- O(m*n)


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

int Solution::solve(string A, string B) 
{
    int m = A.length();
    int n = B.length();
    if(A==B)
        return m;
    if(m==0 || n==0)
        return 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

// Tabulation soln | Space optimized two row vectors used
// Time complexity:- O(m*n)
// Space complexity:- O(n)

int Solution::solve(string A, string B) 
{
    int m = A.length();
    int n = B.length();
    if(A==B)
        return m;
    if(m==0 || n==0)
        return 0;
    vector<vector<int>> dp(2, vector<int>(n+1,0));
    int curr, prev;
    for(int i=1;i<=m;i++)
    {
        curr = i%2;
        prev = 1-curr;
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
            {
                dp[curr][j]=1+dp[prev][j-1];
            }
            else
            {
                dp[curr][j]=max(dp[prev][j],dp[curr][j-1]);
            }
        }
    }
    return dp[curr][n];
}



// Tabulation soln | Space optimized one vectors used | Linear space soln
// Time complexity:- O(m*n)
// Space complexity:- O(n)


int Solution::solve(string A, string B) 
{
    int m = A.length();
    int n = B.length();
    if(A==B)
        return m;
    if(m==0 || n==0)
        return 0;
    vector<vector<int>> dp(1, vector<int>(n+1,0));
    int prev_j, corner;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j==0)
            {
                prev_j = 0;
                corner = 0;
            }
            else if(A[i-1]==B[j-1])
            {
                int temp = dp[0][j];                
                dp[0][j] = 1+corner;
                prev_j = dp[0][j];
                corner = temp;
            }
            else
            {
                corner = dp[0][j];
                dp[0][j] = max(dp[0][j], prev_j);
                prev_j = dp[0][j];
            }
        }
    }
    return dp[0][n];
}

