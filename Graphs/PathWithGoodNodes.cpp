//DFS

// Time Complexity-> O(n)
// Space Complexity -> O(n)

void dfs(int node,  int count, int& ans, vector<vector<int>>& graph, vector<int>& A, int C)
{
    if(A[node]==1)
        count++;
    if(graph[node].size()==0)
    {
        if(count<=C)
            ans++;
        return;
    }
    if(count>C)
        return;
        
    for(auto i:graph[node])
    {
        dfs(i,count,ans,graph,A,C);
    }

}


int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) 
{
    vector<vector<int>> graph;
    int n=A.size();
    graph.resize(n);
    for(auto edge:B)
    {
        graph[min(edge[0]-1,edge[1]-1)].push_back(max(edge[0]-1,edge[1]-1));
    }
    int ans=0;
    dfs(0,0, ans, graph, A,C);
    return ans;
}
