// BFS solution

int getRem(string s, int A)
{
    int l = s.length();
    int ans=0;
    for(int i=0;i<l;i++)
    {
        ans = ans*10+(s[i]-'0');
        ans = ans%A;
    }
    return ans;
}

string Solution::multiple(int A) 
{
    queue<string> q;
    q.push("1");
    
    string curr;
    set<int> st;
    while(q.empty()==0)
    {
        curr=q.front();
        q.pop();
        
        int rem = getRem(curr,A);
        if(rem==0)
            return curr;
       
        if(st.find(rem)==st.end())
        {
            q.push(curr+"0");
            q.push(curr+"1");
            st.insert(rem);
        }
    }
    return "";
}
