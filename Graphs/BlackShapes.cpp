//https://www.interviewbit.com/problems/black-shapes/

//DFS solution
//Space Complexity:- O(m*n)
//Time Complexity:- O(m*n)


void dfs(int i, int j, int m, int n, vector<string>& A, vector<vector<int>>& visited)
{
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,1,-1};
    visited[i][j]=1;
    for(int k=0;k<4;k++)
    {
        int X = i + dx[k];
        int Y = j + dy[k];
        if(X>=0 && X<m && Y>=0 && Y<n && A[X][Y]=='X' && !visited[X][Y])
            dfs(X,Y,m,n,A,visited);
    }
}


int Solution::black(vector<string> &A) 
{
    int m = A.size();
    int n = A[0].length();
    int ans=0;
    vector<vector<int>> visited(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((visited[i][j]==0)&&(A[i][j]=='X'))
            {
                dfs(i,j,m,n,A,visited);
                ans++;
            }
        }
    }
    return ans;
}
