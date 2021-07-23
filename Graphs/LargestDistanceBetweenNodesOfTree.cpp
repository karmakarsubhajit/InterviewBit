//DFS solution
//Time Complexity -- O(2*n)+O(n) = O (n)
//Space Complexity -- O(n) + O(n) = O(n)


void findNode(int root, int parent, int dist, vector<vector<int>>& graph, int& node,int& mx_dist)
{
    dist++;
    if(graph[root].size()==1)
    {
        if(dist>mx_dist)
        {
            mx_dist = dist;
            node = root;
        }
    }
    for(auto i:graph[root])
    {
        if(i!=parent)
        {
            findNode(i,root,dist,graph,node,mx_dist);
        }
    }

}

int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    vector<vector<int>> graph;
    graph.resize(n);
    int root=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==-1)
        {
            root=i;
            continue;
        }   
        graph[A[i]].push_back(i);
        graph[i].push_back(A[i]);
    }
    int node=-1;
    int mx_dist=-1;

    findNode(root, -1, -1, graph, node, mx_dist);
    int mx_dist2=-1;
    int node2=-1;
    findNode(node,-1,-1,graph,node2, mx_dist2);
    return mx_dist2;
}
