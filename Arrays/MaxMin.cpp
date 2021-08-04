// https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

// Time  Complexity:- O(n)
// Space Complexity:- O(1)

int Solution::solve(vector<int> &A) 
{
    int l = A.size();
    if(l==1)
        return A[0];
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i=0;i<l;i++)
    {
        mn = min(mn,A[i]);
        mx = max(mx,A[i]);
    }
    return mx+mn;
}
