//https://www.interviewbit.com/problems/cycle-in-directed-graph/
// DFS solution
// Time complexity:- O(V+E)
// Space complexity:- O(V)

int dfs(int src, vector<vector<int>>& graph, vector<int>& visited, vector<int>& recStack )
{
    visited[src]=1;
    recStack[src]=1;

    for(auto i:graph[src])
    {
        if(recStack[i]==1)
            return 1;
        else if((visited[i]==0)&&(dfs(i,graph, visited, recStack)==1))
            return 1;
    }


    recStack[src]=0;
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<int> recStack(A,0);
    vector<int> visited(A,0);
    vector<vector<int>> graph;
    graph.resize(A);
    
    for(int i=0;i<B.size();i++)
    {
         int src = B[i][0]-1;
        int dest = B[i][1]-1;
        graph[src].push_back(dest);
    }
   
    for(int i=0;i<A;i++)
    {
        if((visited[i]==0)&&(dfs(i,graph,visited,recStack)==1))
            return 1;
            
    }
    return 0;
}
