// https://www.interviewbit.com/problems/combination-sum/

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 

Given candidate set 2,3,6,7 and target 7,

A solution set is:

[2, 2, 3]
[7]
*/

// Time complexity:- O(k*n^n)
// Space complexity:- O(n)

    void getComb(vector<vector<int>>& ans, vector<int>& v, vector<int> candidates, int n, int i, int sm, int target)
    {
        if(sm>target)
            return;
        if(sm==target)
        {
            ans.push_back(v);   
            return;
        }
        if(i>=n)
            return;
        for(int p=i;p<n;p++)
        {  
            while((p+1<n) && (candidates[p]==candidates[p+1]))
            {
                p++;
            }
            v.push_back(candidates[p]);
            getComb(ans, v, candidates,n,p,sm+candidates[p],target);
            v.pop_back();
        }
    }


vector<vector<int> > Solution::combinationSum(vector<int> &A, int target) 
{
    int n = A.size();    
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> v;
    int sm = 0;
    getComb(ans, v, A, n, 0, sm, target);
    sort(ans.begin(), ans.end());
    return ans;
}



// Optimal soln
// Time complexity:- O(k*2^n)
// Space complexity:- O(n)

void getComb(vector<vector<int>>& ans, vector<int>& v, vector<int> candidates, int n, int i, int sm, int target)
{
    if(sm>target)
        return;
    if(sm==target)
    {
        ans.push_back(v);   
        return;
    }
    if(i>=n)
        return;

    getComb(ans, v, candidates,n,i+1,sm,target);
    v.push_back(candidates[i]);
    getComb(ans, v, candidates,n,i,sm+candidates[i],target);
    v.pop_back();
    
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int target) 
{
    int n = A.size();    
    sort(A.begin(), A.end());
    vector<int> a;
    a.push_back(A[0]);
    for(int i=1;i<n;i++)
    {
        if(A[i-1]!=A[i])
            a.push_back(A[i]);
    }

    vector<vector<int>> ans;
    vector<int> v;
    int sm = 0;
    getComb(ans, v, a, a.size(), 0, sm, target);
    sort(ans.begin(), ans.end());
    return ans;
}
