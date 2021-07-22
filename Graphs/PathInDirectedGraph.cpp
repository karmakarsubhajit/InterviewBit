//BFS solution

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<vector<int>> graph;
    graph.resize(A+1);
    vector<int> visited(A+1,0);
    for(auto i:B)
    {
        graph[i[0]].push_back(i[1]);
    }
    queue<int> q;
    q.push(1);
    visited[1]=1;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if(curr==A)
            return true;
        for(auto i:graph[curr])
        {
            if(visited[i]==0)
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return false;
}
