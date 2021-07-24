//https://www.interviewbit.com/problems/two-teams/

// BFS solution
// Time complexity:- O(V+E)
// Space complexity:- O(V)


int Solution::solve(int A, vector<vector<int> > &B) 
{
 
    vector<vector<int>> graph;
    graph.resize(A);
    for(auto i:B)
    {
        graph[i[0]-1].push_back(i[1]-1);
        graph[i[1]-1].push_back(i[0]-1);
    }
 
    vector<int> color(A,-1);
    
    for(int i=0;i<A;i++)
    {   
        if(color[i]==-1)
        {
            queue<pair<int,int>> player;
            color[i]=0;
            player.push(make_pair(i,0));
            while(player.empty()==0)
            {
                pair<int,int> curr = player.front();
                player.pop();
                int par_player = curr.first;
                int par_color = curr.second;
                
                for(auto child:graph[par_player])
                {
                    if(color[child]==par_color)
                        return 0;
                    else if(color[child]==-1)
                    {
                        int ch = (par_color)?0:1;
                        color[child] = ch;
                        player.push(make_pair(child,ch));
                    }
                }
            }
        }
    }
    return 1;
}
