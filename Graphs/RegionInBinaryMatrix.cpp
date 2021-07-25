// BFS solution
// Time Complexity:- O(m*n)
// Space Complexity:- O(m*n)

int Solution::solve(vector<vector<int> > &A) 
{
    int m = A.size();
    int n = A[0].size();
    int ans=0;
    vector<int> dx{-1,1,0,0,1,-1,1,-1};
    vector<int> dy{0,0,1,-1,1,-1,-1,1};

    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c=0;
            if((vis[i][j]==0) && (A[i][j]==1))
            {
                c++;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                vis[i][j]=1;
                while(q.empty()==0)
                {
                    pair<int,int> p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    for(int k=0;k<8;k++)
                    {
                        int X = x+dx[k];
                        int Y = y+dy[k];
                        if((X>=0) && (X<m) && (Y>=0) && (Y<n) && (vis[X][Y]==0) && (A[X][Y]==1))
                        {
                            c++;
                            vis[X][Y]=1;
                            q.push(make_pair(X,Y));
                        }
                    }

                }
            }
            ans= max(ans,c);
        }
    }
    return ans;
}
