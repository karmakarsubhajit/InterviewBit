//https://www.interviewbit.com/problems/clone-graph/

//DFS solution
// Time Complexity:- O(V+E)
// Space Complexity:- O(V)


void dfs(UndirectedGraphNode* node, map<UndirectedGraphNode*, UndirectedGraphNode*>& mp)
{
    mp[node] = new UndirectedGraphNode(node->label);
    for(auto p:node->neighbors)
    {
        if(!mp[p])
        {
            dfs(p,mp);
        }
        mp[node]->neighbors.push_back(mp[p]);
    }
}
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) 
{
 
    map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    dfs(node,mp);
    return mp[node];
}



/***********************/

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
    map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    mp[node] =  new UndirectedGraphNode(node->label);
    while(q.empty()==0)
    {
        UndirectedGraphNode* temp = q.front();
        q.pop();
        for(auto p:temp->neighbors)
        {
            if(!mp[p])
            {
                q.push(p);
                mp[p] = new UndirectedGraphNode(p->label);
            }
                
            mp[temp]->neighbors.push_back(mp[p]);
        }
    }

    return mp[node];
}


