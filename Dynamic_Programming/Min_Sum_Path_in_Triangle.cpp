// https://www.interviewbit.com/problems/min-sum-path-in-triangle/

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/




// Recursive || Brute Force
// Time Complexity:- O(2^(m*n)), m,n are no of rows and cols in triangle
// Space Complexity:- O(m)

int minimumSum(vector<vector<int>> &A,int i, int j)
{
    if(i==(A.size()-1))
        return A[i][j];
    int ans = A[i][j]+min(minimumSum(A,i+1,j),minimumSum(A,i+1,j+1));
    return ans;

}


int Solution::minimumTotal(vector<vector<int> > &A) {
 
    return minimumSum(A,0,0);
}

// Memoization soln 
// Time Complexity:- O(n*n), m,n are no of rows and cols in triangle
// Space Complexity:- O(n*n)

int minimumSum(vector<vector<int>> &A,int i, int j,vector<vector<int>> dp)
{
    if(i>=(A.size()-1))
        return A[i][j];
    if(dp[i][j]!=INT_MIN)
        return dp[i][j];
    int ans = A[i][j]+min(minimumSum(A,i+1,j,dp),minimumSum(A,i+1,j+1,dp));
    dp[i][j]=ans;
    return ans;

}


int Solution::minimumTotal(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(),vector<int>(A.size(),INT_MIN));
    return minimumSum(A,0,0,dp);
}




// Bottom Up || Optimal soln || Modifying matrix
// Time Complexity:- O(m*n), m,n are no of rows and cols in triangle
// Space Complexity:- O(1)

int Solution::minimumTotal(vector<vector<int> > &A) {
  
  
    int m = A.size();
    for(int i=m-2;i>=0;i--)
    {
        int n = A[i].size();
        for(int j=n-1;j>=0;j--)
        {
            A[i][j]+=min(A[i+1][j],A[i+1][j+1]);
        }
    }
    return A[0][0];
}




// Bottom Up || Optimal soln
// Time Complexity:- O(m*n), m,n are no of rows and cols in triangle
// Space Complexity:- O(n)


int Solution::minimumTotal(vector<vector<int> > &A) {
   
    int m = A.size();
    vector<int> dp(A.back());

    for(int i=m-2;i>=0;i--)
    {
        int n = A[i].size();
        for(int j=0;j<=n-1;j++)
        {
            dp[j]=A[i][j]+min(dp[j],dp[j+1]);
        }
    }
    return dp[0];
}
