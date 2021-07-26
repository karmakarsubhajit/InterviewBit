//https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

//DFS solution
//Time Complexity:- O(V+E)
//Space Complexity:- O(V)


int dfs(int src, vector<vector<int>>& graph, vector<int>& visited,vector<int>& recStack)
{
    recStack[src]=1;
    visited[src]=1;

    for(auto i:graph[src])
    {
        if(recStack[i]==1)
            return 1;
        else if((visited[i]==0)&&(dfs(i,graph,visited,recStack)==1))
            return 1;
    }

    recStack[src]=0;
    return 0;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) 
{
    vector<int> visited(A,0);
    vector<int> recStack(A,0);
    vector<vector<int>> graph;
    graph.resize(A);

    
    for(int i=0;i<B.size();i++)
    {
        int src = B[i]-1;
        int dest = C[i]-1;
        graph[src].push_back(dest);
    }
    for(int i=0;i<A;i++)
    {
        if((visited[i]==0) && (dfs(i,graph,visited,recStack)==1))
            return 0;
    }
    return 1;
}
