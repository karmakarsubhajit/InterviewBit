
// https://www.interviewbit.com/problems/stepping-numbers/

/* DFS Solution */

void stepNumDFS(int A, int B, vector<int>& ans, int num)
{
    if(num>=A && num<=B)
        ans.push_back(num);
    if(num>B)
        return;
    int lastDig = num%10;
    if(lastDig==0)
        stepNumDFS(A,B,ans,num*10+1);
    else if(lastDig==9)
        stepNumDFS(A,B,ans,num*10+8);
    else
    {
        stepNumDFS(A,B,ans,num*10+lastDig+1);
        stepNumDFS(A,B,ans,num*10+lastDig-1);
    }
}


vector<int> Solution::stepnum(int A, int B) 
{
    vector<int> ans;

    if(A>B)
        return ans;

    if(A==0)
        ans.push_back(0);
    
    for(int i=1;i<=9;i++)
    {
        stepNumDFS(A,B,ans,i);
    }
    sort(ans.begin(), ans.end());
    return ans;
    
}


/* BFS Solution */




vector<int> Solution::stepnum(int A, int B) 
{
    vector<int> ans;

    if(A>B)
        return ans;

    if(A==0)
        ans.push_back(0);
    queue<int> q;
    

    for(int i=1;i<=9;i++)
    {
        q.push(i);    
    }
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if(curr>=A && curr<=B)
            ans.push_back(curr);
        if(curr>B)
            continue;
        int lastDig = curr%10;
        if(lastDig==0)
        {
            q.push(curr*10 + 1);   
        }
        else if(lastDig==9)
        {
            q.push(curr*10 + 8);
        }
        else 
        {
            q.push(curr*10 + lastDig+1);
            q.push(curr*10 + lastDig-1);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
    
}

