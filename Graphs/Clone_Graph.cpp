//https://www.interviewbit.com/problems/clone-graph/

//DFS solution
// Time Complexity:- O(V+E)
// Space Complexity:- O(V)

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

void dfs(UndirectedGraphNode* node, map<int, UndirectedGraphNode*>& mp)
{
    mp[node->label] = new UndirectedGraphNode(node->label);
    for(auto p:node->neighbors)
    {
        if(!mp[p->label])
        {
            dfs(p,mp);
        }
        mp[node->label]->neighbors.push_back(mp[p->label]);
    }
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) 
{

    map<int, UndirectedGraphNode*> mp;
    dfs(node,mp);
    return mp[node->label];
}



//BFS solution
// Time Complexity:- O(V+E)
// Space Complexity:- O(V)


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) 
{
    map<int, UndirectedGraphNode*> mp;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    mp[node->label] =  new UndirectedGraphNode(node->label);
    while(q.empty()==0)
    {
        UndirectedGraphNode* temp = q.front();
        q.pop();
        for(auto p:temp->neighbors)
        {
            if(!mp[p->label])
            {
                q.push(p);
                mp[p->label] = new UndirectedGraphNode(p->label);
            }
                
            mp[temp->label]->neighbors.push_back(mp[p->label]);
        }
    }

    return mp[node->label];
}

