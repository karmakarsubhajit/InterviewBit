// https://www.interviewbit.com/problems/maximum-sum-triplet/

// Time complexity:- O(nlogn)
// Space complexity:- O(n)   --->2 arrays + 1 set

int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    vector<int> leftMax(n,0);
    vector<int> rightMax(n,0);
    rightMax[n-1]=A[n-1];
    leftMax[0]=A[0];
    
    for(int i=n-2;i>=0;i--)
    {
        rightMax[i]=max(rightMax[i+1],A[i]);
    }
    set<int> s;
    s.insert(A[0]);
    int mx = 0;
    for(int i=1;i<n;i++)
    {
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if(it==s.begin())
            leftMax[i]=A[i];
        else
        {
            --it;
            leftMax[i] = *it;
        }
    }
    for(int i=1;i<n-1;i++)
    {
        if(A[i]!=leftMax[i] && A[i]!=rightMax[i])
        {
            mx = max(mx,A[i]+leftMax[i]+rightMax[i]);
        }
    }
    return mx;
}



// Time complexity:- O(nlogn)
// Space complexity:- O(n)   --->1 array + 1 set




int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    
    vector<int> rightMax(n,0);
    rightMax[n-1]=A[n-1];
    
    
    for(int i=n-2;i>=0;i--)
    {
        rightMax[i]=max(rightMax[i+1],A[i]);
    }
    set<int> s;
    s.insert(A[0]);
    int mx = 0;
    for(int i=1;i<n-1;i++)
    {
        if(rightMax[i]<=A[i])
        {
            continue;
        }    
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if(it==s.begin())
            continue;
        it--;
        mx = max(mx,*it+A[i]+rightMax[i]);
    }
    
    return mx;
}
