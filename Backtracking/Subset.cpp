// https://www.interviewbit.com/problems/subset/
/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/

// Time complexity:- O(n*2^n)
// Space complexity:- O(n), stack space

void getSubset(int i, int n, vector<int>& A, vector<int>& a, vector<vector<int>>& ans)
{
    ans.push_back(a);
    for(int p=i;p<n;p++)
    {
        a.push_back(A[p]);
        getSubset(p+1,n,A,a,ans);
        a.pop_back();
    }    
}

vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int n = A.size();
    vector<vector<int>> ans;
    vector<int> v;
    getSubset(0,n,A,v,ans);
    return ans;
}





// Time complexity:- O(n*2^n)
// Space complexity:- O(n), stack space


void getSubset(int i, int n, vector<int>& A, vector<int>& a, vector<vector<int>>& ans)
{
    if(i==n)
    {
        ans.push_back(a);
        return;
    }
    getSubset(i+1,n,A,a,ans);
    a.push_back(A[i]);
    getSubset(i+1,n,A,a,ans);
    a.pop_back();
    
}

vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int n = A.size();
    vector<vector<int>> ans;
    vector<int> v;
    getSubset(0,n,A,v,ans);
    sort(ans.begin(), ans.end());
    return ans;
}
