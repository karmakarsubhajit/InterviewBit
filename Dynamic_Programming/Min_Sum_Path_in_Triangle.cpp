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
