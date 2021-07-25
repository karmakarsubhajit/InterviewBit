//BFS solution
//Space complexity:- O(n)     ----->n is no of cells on the board
//Time complexity:- O(n)

struct queueN{
    int dist;
    int ind;
};

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) 
{
    vector<int> hasJump(100,-1);
    vector<int> visited(100,0);
    for(auto i:A)
        hasJump[i[0]-1] = i[1]-1;
    for(auto i:B)
        hasJump[i[0]-1] = i[1]-1;
    queue<queueN> q;
    queueN s;
    s.dist = 0;
    s.ind = 0;
    q.push(s);
    visited[0]=1;
    while(q.empty()==0)
    {
        queueN curr = q.front();
        q.pop();
        int distance = curr.dist;
        int index = curr.ind;
        if(index==99)
            return distance;
        for(int i=index+1;i<=(index+6) && (i<100);i++)
        {   
            if(visited[i]==0)
            {
                queueN temp;
                temp.dist = distance+1;
                visited[i]=1;
                if(hasJump[i]==-1)
                    temp.ind = i;
                else
                    temp.ind = hasJump[i];
                q.push(temp);
            }
        }
    }
    return -1;    
    
}
