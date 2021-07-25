// BFS solution
//Time complexity:- O(mnC)     ----- m is no of rows, n is no of cols, C is no of circles
// Space complexity:- O(mn)


bool isValid(int x, int y, int m, int n, int C, int R, vector<int> &E, vector<int> &F)
{
    if(x<0 ||x>m || y<0 ||y>n)
        return false;
    for(int k=0;k<C;k++)
    {
        int xc = E[k];
        int yc = F[k];
        double dist = sqrt((xc-x)*(xc-x) + (yc-y)*(yc-y));
        if(dist<=R)
        {
            return false;
        }
    }
    return true;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) 
{
    vector<int> dx{-1,1,0,0,1,-1,1,-1};
    vector<int> dy{0,0,1,-1,1,-1,-1,1};

    if(!isValid(0,0,A,B,C,D,E,F) || !isValid(A,B,A,B,C,D,E,F))
        return "NO";
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    vector<vector<int>> visited(A+1,vector<int>(B+1,0));
    visited[0][0]=1;

    while(q.empty()==0)
    {
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if(x==A && y==B)
            return "YES";
        for(int ind = 0;ind<8;ind++)
        {
            int X = x+dx[ind];
            int Y = y+dy[ind];
            if((isValid(X,Y,A,B,C,D,E,F)==true) && (visited[X][Y]==0))
            {
                visited[X][Y]=1;
                q.push(make_pair(X,Y));
            }
        }

    }

    return "NO";
}




/********** DFS solution *********/
// BFS solution
//Time complexity:- O(mnC)     ----- m is no of rows, n is no of cols, C is no of circles
// Space complexity:- O(mn)

bool isValid(int x, int y, int m, int n, int C, int R, vector<int> &E, vector<int> &F)
{
    if(x<0 ||x>m || y<0 ||y>n)
        return false;
    for(int k=0;k<C;k++)
    {
        int xc = E[k];
        int yc = F[k];
        double dist = sqrt((xc-x)*(xc-x) + (yc-y)*(yc-y));
        if(dist<=R)
        {
            return false;
        }
    }
    return true;
}

bool dfs(int x, int y, int A, int  B, int C, int D, vector<int> &E, vector<int> &F, vector<vector<int>> &visited)
{
    if((x==A) && (y==B))
        return true;
    visited[x][y]=1;

    vector<int> dx{-1,1,0,0,1,-1,1,-1};
    vector<int> dy{0,0,1,-1,1,-1,-1,1};
        
    
    for(int ind = 0;ind<8;ind++)
    {
        int X = x+dx[ind];
        int Y = y+dy[ind];
        if((isValid(X,Y,A,B,C,D,E,F)==true) && (visited[X][Y]==0))
        {
            bool  ans = dfs(X,Y,A,B,C,D,E,F,visited);
            if(ans==true)
                return true;
        }
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) 
{
    

    if(!isValid(0,0,A,B,C,D,E,F) || !isValid(A,B,A,B,C,D,E,F))
        return "NO";
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    vector<vector<int>> visited(A+1,vector<int>(B+1,0));
    visited[0][0]=1;
    if(!isValid(0,0,A,B,C,D,E,F) || !isValid(A,B,A,B,C,D,E,F))
        return "NO";
    bool ans = dfs(0,0,A,B,C,D,E,F,visited);

    return ans?"YES":"NO";
}
