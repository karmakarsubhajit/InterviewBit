//BFS approach

bool isValid(int X, int Y, int m, int n, vector<vector<char>> &A)
{
    return ((X>=0) && (X<m) && (Y>=0) && (Y<n) && (A[X][Y]=='O'));
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = A[0].size();
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,1,-1};


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((A[i][j]=='O') && ((i==0) || (i==(m-1)) || (j==0) || j==(n-1))) 
            {
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                A[i][j] = 'P';
                while(!q.empty())
                {
                    pair<int,int> curr = q.front();
                    q.pop();
                    
                    for(int k=0;k<4;k++)
                    {
                        int X = curr.first + dx[k];
                        int Y = curr.second + dy[k];
                        if(isValid(X,Y,m,n,A))
                        {
                            A[X][Y] = 'P';
                            q.push(make_pair(X,Y));
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]=='O')
            {
                A[i][j]='X';
            }
            else if(A[i][j]=='P')
            {
                A[i][j]='O';
            }
        }
    }
}


//DFS approach

bool isValid(int X, int Y, int m, int n, vector<vector<char>> &A)
{
    return ((X>=0) && (X<m) && (Y>=0) && (Y<n) && (A[X][Y]=='O'));
}

void dfs(int x, int y, int m, int n, vector<vector<char>> &A)
{
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,1,-1};

    A[x][y]='P';
    for(int k=0;k<4;k++)
    {
        int X = x+dx[k];
        int Y = y+dy[k];
        if(isValid(X,Y,m,n,A))
            dfs(X,Y,m,n,A);
    }
}


void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = A[0].size();
    

    for(int k=0;k<n;k++)
    {
        if(A[0][k]=='O')
        {
            dfs(0,k,m,n,A);
        }
        if(A[m-1][k]=='O')
        {
            dfs(m-1,k,m,n,A);
        }
    }
    for(int k=0;k<m;k++)
    {
        if(A[k][0]=='O')
        {
            dfs(k,0,m,n,A);
        }
        if(A[k][n-1]=='O')
        {
            dfs(k,n-1,m,n,A);
        }
    }
    

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]=='O')
            {
                A[i][j]='X';
            }
            else if(A[i][j]=='P')
            {
                A[i][j]='O';
            }
        }
    }
}


//FloodFill approach(slight variation of DFS)




void floodFill(int x, int y, int m, int n, vector<vector<char>> &A, char prev, char pres)
{
    if(x==m || y==n || x==-1 || y==-1)
        return;
    if(A[x][y]!=prev)
        return;
    A[x][y]=pres;
    floodFill(x+1,y,m,n,A,prev,pres);
    floodFill(x-1,y,m,n,A,prev,pres);
    floodFill(x,y+1,m,n,A,prev,pres);
    floodFill(x,y-1,m,n,A,prev,pres);
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = A[0].size();
    

    for(int k=0;k<n;k++)
    {
        if(A[0][k]=='O')
        {
            floodFill(0,k,m,n,A,'O','P');
        }
        if(A[m-1][k]=='O')
        {
            floodFill(m-1,k,m,n,A,'O','P');
        }
    }
    for(int k=0;k<m;k++)
    {
        if(A[k][0]=='O')
        {
            floodFill(k,0,m,n,A,'O','P');
        }
        if(A[k][n-1]=='O')
        {
            floodFill(k,n-1,m,n,A,'O','P');
        }
    }
    

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]=='O')
            {
                A[i][j]='X';
            }
            else if(A[i][j]=='P')
            {
                A[i][j]='O';
            }
        }
    }
}
