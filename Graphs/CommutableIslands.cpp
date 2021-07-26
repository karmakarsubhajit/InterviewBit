//https://www.interviewbit.com/problems/commutable-islands/

// Using Kruskals Algo
// Union Find (Naive)
// Time complexity:- O(ElogE)+O(EV) = O(EV)
// Space complexity:- O(E+v)

bool compareEdge(vector<int>&  A , vector<int>& B)
{
    return A[2]<B[2];
}

int findParent(vector<int>& parent, int node)
{
    if(parent[node]==node)
        return node;
    return findParent(parent, parent[node]);
}

void makeunion(vector<int>& parent, int parA, int parB)
{
    parent[parA]=parB;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    int m = B.size();
    int ans=0;
    vector<int> parent(A,-1);
    for(int i=0;i<A;i++)
        parent[i]=i;
    sort(B.begin(), B.end(), compareEdge);
    for(int i=0;i<m;i++)
    {
        int src = B[i][0]-1;
        int dest = B[i][1]-1;
        int weight = B[i][2];
        int parentA = findParent(parent, src);
        int parentB = findParent(parent, dest);
        if(parentA==parentB)
            continue;
        else
        {
            makeunion(parent,parentA,parentB);
            ans+=weight;
        }
    }
    return ans;
}




// Using Kruskals Algo
// Union by Rank
/*  Time Complexity:- O(ElogE)+O(ElogV) 
    E can be atmost V^2 so O(logE) = O(logV)
    Therefore the time complexity is O(ElogV)
*/
// Space complexity:- O(E+V)



struct node
{
    int par;
    int rank;
};

bool compareEdge(vector<int>&  A , vector<int>& B)
{
    return A[2]<B[2];
}

int findParent(vector<node>& vertices, int root)
{
    if(vertices[root].par==root)
        return root;
    return findParent(vertices, vertices[root].par);
}

void makeunion(vector<node>& vertices, int parA, int parB)
{
    if(vertices[parA].rank==vertices[parB].rank)
    {
        vertices[parA].par = parB;
        vertices[parB].rank++;
    }
    else if(vertices[parA].rank<vertices[parB].rank)
    {
        vertices[parA].par = parB;
    }
    else if(vertices[parB].rank<vertices[parA].rank)
    {
        vertices[parB].par = parA;
    }
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    int m = B.size();
    int ans=0;
    vector<node> vertices;
    vertices.resize(A);
    for(int i=0;i<A;i++)
    {
        vertices[i].par = i;  
        vertices[i].rank =  0;
    }


    sort(B.begin(), B.end(), compareEdge);

    for(int i=0;i<m;i++)
    {
        int src = B[i][0]-1;
        int dest = B[i][1]-1;
        int weight = B[i][2];
        int parentA = findParent(vertices, src);
        int parentB = findParent(vertices, dest);
        if(parentA==parentB)
            continue;
        else
        {
            makeunion(vertices,parentA,parentB);
            ans+=weight;
        }
    }
    return ans;
}



// Union by Rank with Path compression
/*  Time Complexity:- O(ElogE)+O(ElogV) 
    E can be atmost V^2 so O(logE) = O(logV)
    Therefore the time complexity is O(ElogV)
*/
// Space complexity:- O(E+V)



struct node
{
    int par;
    int rank;
};

bool compareEdge(vector<int>&  A , vector<int>& B)
{
    return A[2]<B[2];
}

int findParent(vector<node>& vertices, int root)
{
    if(vertices[root].par!=root)
        vertices[root].par = findParent(vertices, vertices[root].par);
    return vertices[root].par;
}

void makeunion(vector<node>& vertices, int parA, int parB)
{
    if(vertices[parA].rank==vertices[parB].rank)
    {
        vertices[parA].par = parB;
        vertices[parB].rank++;
    }
    else if(vertices[parA].rank<vertices[parB].rank)
    {
        vertices[parA].par = parB;
    }
    else if(vertices[parB].rank<vertices[parA].rank)
    {
        vertices[parB].par = parA;
    }
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    int m = B.size();
    int ans=0;
    vector<node> vertices;
    vertices.resize(A);
    for(int i=0;i<A;i++)
    {
        vertices[i].par = i;  
        vertices[i].rank =  0;
    }


    sort(B.begin(), B.end(), compareEdge);

    for(int i=0;i<m;i++)
    {
        int src = B[i][0]-1;
        int dest = B[i][1]-1;
        int weight = B[i][2];
        int parentA = findParent(vertices, src);
        int parentB = findParent(vertices, dest);
        if(parentA==parentB)
            continue;
        else
        {
            makeunion(vertices,parentA,parentB);
            ans+=weight;
        }
    }
    return ans;
}
