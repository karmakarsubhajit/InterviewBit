// https://www.interviewbit.com/problems/edit-distance/
/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
*/

// Recursive Brute Force Solution
// Time complexity:- O(3^(m+n))
// Space complexity:- O(min(m,n))


int editDistance(string A, string B, int i, int j, int m, int n)
{
    if(i==m)
        return n-j;
    if(j==n)
        return m-i;
    if(A[i]==B[j])
    {
        return editDistance(A, B, i+1, j+1, m, n);
    }
    else
    {
        return 1+min(min(editDistance(A, B, i+1,j , m ,n ), editDistance(A, B, i,j+1,m ,n)), editDistance(A, B, i+1,j+1,m,n));
    }
 
}
int Solution::minDistance(string A, string B) 
{
    int m = A.size();
    int n = B.size();
    if(m==0)
        return n;
    if(n==0)
        return m;
    int i=0;
    int j=0;
    
    return editDistance(A,B,i,j,m,n);
}

// Memoization Solution
// Time complexity:- O(m*n)
// Space complexity:- O(m*n)


int editDistance(string A, string B, int i, int j, int m, int n, vector<vector<int>>& dp)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==m)
    {
        dp[i][j] = n-j;
        return n-j;
    }
    
    if(j==n)
    {
        dp[i][j] = m-i;
        return m-i;
    }    
    if(A[i]==B[j])
    {
        dp[i][j] = editDistance(A, B, i+1, j+1, m, n, dp);
    }
    else
    {
        dp[i][j]= 1+min(min(editDistance(A, B, i+1,j , m ,n, dp ), editDistance(A, B, i,j+1,m ,n, dp)), editDistance(A, B, i+1,j+1,m,n, dp));
    }
    return dp[i][j];
}
int Solution::minDistance(string A, string B) 
{
    int m = A.size();
    int n = B.size();
    if(m==0)
        return n;
    if(n==0)
        return m;
    int i=0;
    int j=0;
    vector<vector<int>> dp(m+1 , vector<int>(n+1,-1));
    return editDistance(A, B, i, j, m, n, dp);
}

// Tabular Solution
// Time complexity:- O(m*n)
// Space complexity:- O(m*n)


int Solution::minDistance(string A, string B) 
{
    int m = A.size();
    int n = B.size();
    if(m==0)
        return n;
    if(n==0)
        return m;
    int i=0;
    int j=0;
    vector<vector<int>> dp(m+1 , vector<int>(n+1,0));
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int j=0;j<=n;j++)
        dp[0][j]=j;
        

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                int ins = 1+dp[i][j-1];
                int del = 1+dp[i-1][j];
                int rem = 1+dp[i-1][j-1];
                dp[i][j] = min(min(ins,del),rem);
            }
        } 
    }
    return dp[m][n];
}

