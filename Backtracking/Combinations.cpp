// https://www.interviewbit.com/problems/combinations/

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :

If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

*/


// Time complexity:- O(k*n^n)
// Space complexity:- O(n)

    void getComb(vector<vector<int>>& ans, vector<int>& v, int i, int k, int n )
    {
        if(v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        if(i>n)
            return;
        for(int p=i;p<=n;p++)
        {
            v.push_back(p);
            getComb(ans,v,p+1,k,n);
            v.pop_back();
        }
    }
    

vector<vector<int> > Solution::combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        getComb(ans,v,1,k,n);
      
    sort(ans.begin(), ans.end());
        return ans;
    }


// More optimal approach
// Time complexity:- O(k*2^n)
// Space complexity:- O(n)

void getComb(vector<vector<int>>& ans, vector<int>& v, int i, int n, int k)
{
    if(v.size()==k)
    {
        ans.push_back(v);
        return;
    }
    if(i>n)
        return;
    getComb(ans,v,i+1,n,k);
    v.push_back(i);
    getComb(ans,v,i+1,n,k);
    v.pop_back();
}


vector<vector<int> > Solution::combine(int n, int k) 
{
    vector<vector<int>> ans;
    vector<int> v;
    getComb(ans,v,1,n,k);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}
