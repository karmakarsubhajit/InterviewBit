// DFS solution
// Time complexity:- O(V+E)
// Space complexity:- O(V) 

bool dfs(int i, int parent, vector<int>& visited, vector<vector<int>>& graph)
{
    visited[i]=1;
    bool ans=false;
    for(auto p:graph[i])
    {
        if(p!=parent)
        {
            if(visited[p]==1)
                return true;
            else
            {
                ans = ans || dfs(p,i,visited,graph);
                if(ans)
                    return true;
            }
        }
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<vector<int>> graph;
    graph.resize(A);
    for(auto i:B)
    {
        graph[i[0]-1].push_back(i[1]-1);
        graph[i[1]-1].push_back(i[0]-1);
    }
    vector<int> visited(A,0);
    for(int i=0;i<A;i++)
    {
        if(visited[i]==0)
        {
            bool ans = dfs(i,-1,visited,graph);
            if(ans==true)
                return true;
        }
    }   
    return false;
}
