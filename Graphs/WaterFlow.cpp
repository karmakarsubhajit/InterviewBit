//https://www.interviewbit.com/problems/water-flow/

//DFS solution 
//Space complexity:- O(m*n)
//Time complexity:- O(m*n)

void dfs(int i, int j, vector<vector<int>>& A, vector<vector<int>>& color)
{
    int m = A.size();
    int n = A[0].size();
   
    color[i][j]=1;
    if(i>0 && A[i-1][j]>=A[i][j] && color[i-1][j]==0)
        dfs(i-1,j,A,color);
    if(i<m-1 && A[i+1][j]>=A[i][j] && color[i+1][j]==0)
        dfs(i+1,j,A,color);
    if(j>0 && A[i][j-1]>=A[i][j] && color[i][j-1]==0)
        dfs(i,j-1,A,color);
    if(j<n-1 && A[i][j+1]>=A[i][j] && color[i][j+1]==0)
        dfs(i,j+1,A,color);
}


int Solution::solve(vector<vector<int> > &A) 
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> blueLake(m,vector<int>(n,0));
    vector<vector<int>> redLake(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        dfs(i,0,A,blueLake);
    }
    for(int j=1;j<n;j++)
    {
        dfs(0,j,A,blueLake);
    }
    for(int i=0;i<m;i++)
    {
        dfs(i,n-1,A,redLake);
    }
    for(int j=0;j<n-1;j++)
    {
        dfs(m-1,j,A,redLake);
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(blueLake[i][j]==1 && redLake[i][j]==1)
                ans++;
        }
    }   
    return ans;

}



// BFS solution
// Time complexity:-  O(m*n)
// Space complexity:- O(m*n)
