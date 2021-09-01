// https://www.interviewbit.com/problems/combination-sum-ii/
/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

*/

// Space complexity:- O(n)
// Time complexity:- O(n*2^n)

void getComb(int i, int n, int sm, int target, vector<int> A, vector<int>& v, vector<vector<int>>& ans)
{
    if(sm==target)
    {
        ans.push_back(v);
        return;
    }
    if(sm>target)
        return;
    if(i>=n)
        return;
    for(int k=i;k<n;k++)
    {
        if(k>i && A[k]==A[k-1])
            continue;
        v.push_back(A[k]);
        getComb(k+1,n,sm+A[k], target, A, v, ans);
        v.pop_back();
    }
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int target) {
    vector<vector<int>> ans;
    vector<int> v;
    sort(A.begin(), A.end());
    int n = A.size();
    int i = 0;
    getComb(0, n, 0, target, A, v ,ans);
    return ans;
}
