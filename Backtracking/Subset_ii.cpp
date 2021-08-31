//https://www.interviewbit.com/problems/subsets-ii/
/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :

If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/

//Using sets
// Time complexity:- O(n*2^n)
// Space complexity:- O(n*2^n)

void getAns(int i, int n, vector<int>& v, set<vector<int>>& ans, vector<int> A)
{
     ans.insert(v);
    if(i==n)
    {
        return;
    }
    
    for(int k=i;k<n;k++)
    {
        v.push_back(A[k]);
        getAns(k+1,n,v,ans,A);
        v.pop_back();
    }
}


vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    sort(A.begin(),A.end());
    set<vector<int>> ans;
    vector<vector<int>> s;
    vector<int> v;
    getAns(0,A.size(),v,ans,A);
    
    for(auto i:ans)
        s.push_back(i);
    return s;
}
