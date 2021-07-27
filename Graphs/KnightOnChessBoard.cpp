// https://www.interviewbit.com/problems/knight-on-chess-board/

// BFS approach
//Time complexity:- O(rows*col)
//Space complexity:- O(rows*col)

bool isValid(int X, int Y, int m, int n, vector<vector<int>>& visited)
{
    if((X>=0) && (Y>=0) && (X<m) && (Y<n) && (visited[X][Y]==0))
        return true;
    return false;
}


int Solution::knight(int A, int B, int C, int D, int E, int F) 
{
    
    vector<int> dx{-1, -2, -1,-2, 1,2, 1,2 };
    vector<int> dy{2, 1, -2, -1, -2,-1 ,2,1};
    vector<vector<int>> visited(A,vector<int>(B,0));
    queue<vector<int>> q;
    vector<int> t{C-1,D-1,0};
    q.push(t);
    visited[C-1][D-1]=1;
    while(q.empty()==0)
    {
        vector<int> curr = q.front();
        q.pop();
        int x = curr[0];
        int y = curr[1];
        int dis = curr[2];
        
        if((x==(E-1)) && (y==(F-1)))
        {
            return dis;
        }
        for(int k=0;k<8;k++)
        {
            int X = x+dx[k];
            int Y = y+dy[k];
            if(isValid(X,Y,A,B,visited)==1)
            {
                visited[X][Y]=1;
                vector<int> temp{X,Y,dis+1};
                q.push(temp);
            }
        }
    }

    return -1;
}

