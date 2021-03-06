// https://www.interviewbit.com/problems/0-1-knapsack/

/*
Problem Description

Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.
Also given an integer C which represents knapsack capacity.
Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

NOTE:
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Problem Constraints
1 <= N <= 103
1 <= C <= 103
1 <= A[i], B[i] <= 103

Input Format
First argument is an integer array A of size N denoting the values on N items.
Second argument is an integer array B of size N denoting the weights on N items.
Third argument is an integer C denoting the knapsack capacity.

Output Format
Return a single integer denoting the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

Example Input
Input 1:
 A = [60, 100, 120]
 B = [10, 20, 30]
 C = 50
 
Input 2:
 A = [10, 20, 30, 40]
 B = [12, 13, 15, 19]
 C = 10


Example Output
Output 1:
 220
 
Output 2:
 0

Example Explanation
Explanation 1:
 Taking items with weight 20 and 30 will give us the maximum value i.e 100 + 120 = 220
 
Explanation 2:
 Knapsack capacity is 10 but each item has weight greater than 10 so no items can be considered in the knapsack therefore answer is 0.
*/



// Recursive Brute Force soln
// Time complexity:- O(2^n), where n is the no of items
// Space complexity:- O(n)


int getKnapsackValue(vector<int>& values, vector<int>& weights, int W, int n)
{
    if(W==0)
        return 0;
    if(n=0)
        return 0;
    int ans;
    ans = getKnapsackValue(values, weights, W, n-1);    
    if(W>=weights[n-1])
        ans = max(ans, values[n-1]+getKnapsackValue(values, weights, W-weights[n-1] ,n-1));
    return ans;
}
 
int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size();
    return getKnapsackValue(A,B,C,n);
}

// DP-Memoization soln
// Time complexity:- O(C*n), where C is the capacity and n is the no of items
// Space complexity:- O(C*n)

int getKnapsackValue(vector<int>& values, vector<int>& weights, int W, int n, vector<vector<int>>& dp)
{
    if(n==0)
    {
        dp[n][W]=0;
        return 0;
    }
    if(W==0)
    {
        dp[n][W]=0;
        return 0;
    }
 
    if(dp[n][W]!=-1)
        return dp[n][W];    
    int ans;
    ans = getKnapsackValue(values, weights, W, n-1, dp);    
    if(W>=weights[n-1])
        ans = max(ans, values[n-1]+getKnapsackValue(values, weights, W-weights[n-1] ,n-1, dp));
    dp[n][W] = ans;
    return ans;
}
 
int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(C+1,-1));
    return getKnapsackValue(A,B,C,n,dp);
}


// DP-Tabular soln
// Time complexity:- O(C*n), where C is the capacity and n is the no of items
// Space complexity:- O(C*n)


int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(C+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=C;j++)
        {
            int ans;
            ans = dp[i-1][j];
            if(j>=B[i-1])
                ans = max(ans,A[i-1]+dp[i-1][j-B[i-1]]);
            dp[i][j] = ans;
        }
    }
    return dp[n][C];    
}


// DP-Tabular soln
// Time complexity:- O(C*n), where C is the capacity and n is the no of items
// Space complexity:- O(C)


int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size();
    vector<int> dp(C+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=C;j>=1;j--)
        {
            int ans;
            ans = dp[j];
            if(j>=B[i-1])
                ans = max(ans,A[i-1]+dp[j-B[i-1]]);
            dp[j] = ans;
        }
    }
    return dp[C];    
}
