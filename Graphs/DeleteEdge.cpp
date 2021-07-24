// https://www.interviewbit.com/problems/delete-edge/

//Time complexity -- O(n)
//Space Complexity -- O(n)



long long int getSumTree(int i, int parent, long long int& maxProd, long long int total_sum, 
vector<int>& A, vector<vector<int>>& graph)
{
        long long int currSum = A[i];
        for(auto child:graph[i])
        {
            if(child!=parent)
            {
                currSum+=getSumTree(child, i, maxProd, total_sum, A, graph);
            }
        }
        long long int currProd = ((total_sum-currSum)%(1000000007)*currSum%(1000000007))%(1000000007);
        if(currProd>maxProd)
            maxProd=currProd;
        return currSum; 
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) 
{
    int n = A.size();
    vector<vector<int>> graph;
    graph.resize(n);
    for(auto i:B)
    {
        graph[i[0]-1].push_back(i[1]-1);
        graph[i[1]-1].push_back(i[0]-1);
    }
    long long int total_sum = 0;
    for(auto i:A)
        total_sum+=i;
    long long int maxProd = -1;
    getSumTree(0, -1, maxProd, total_sum, A, graph);
    return (int)(maxProd%(1000000007));
    
}
