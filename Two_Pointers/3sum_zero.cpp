//https://www.interviewbit.com/problems/3-sum-zero/
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
  (-1, 0, 1)
  (-1, -1, 2)

*/

// Using set to remove duplicates
// Time complexity:- O(n^2)
// Space complexity:- O(n)

vector<vector<int> > Solution::threeSum(vector<int> &A) 
{
    int i = 0;
    int n = A.size();
    sort(A.begin(), A.end());
    set<vector<int>> ans;
    vector<vector<int>> ans1;
    
    for(int i=0;i<n-2;i++)
    {
        int l = i+1;
        int r = n-1;
        while(l<r)
        {
            long long int temp = (long long int)A[i]+(long long int)A[l]+(long long int)A[r];
            if(temp==0)
            {
                vector<int> t{A[i],A[l],A[r]};
                l++;
                r--;
                ans.insert(t);
            }
            else if(temp>0)
            {
                r--;
            }
            else
                l++;
        }
    }
    for(auto it:ans)
        ans1.push_back(it);
    return ans1;
}

// Using while loops to remove duplicates
// Time complexity:- O(n^2)
// Space complexity:- O(1)



vector<vector<int>> Solution::threeSum(vector<int>& nums) 
{
    int n = nums.size();
    vector<vector<int>> res;
    if(n<=2)
        return res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++)
    {
        if(i>0 && (nums[i]==nums[i-1]))
            continue;
        int l = i+1;
        int r = n-1;
        while(l<r)
        {
            int sm = nums[l]+nums[r]+nums[i];
            if(sm<0)
                l++;
            else if(sm>0)
                r--;
            else
            {
                vector<int> ans{nums[i],nums[l],nums[r]};
                res.push_back(ans);
                if(l+1<n && nums[l]==nums[l+1])
                {
                    while(l+1<n && nums[l]==nums[l+1])
                        l++;
                }
                l++;
                if(r-1>l && nums[r]==nums[r-1])
                {
                    while(r-1>l && nums[r]==nums[r-1])
                        r--;
                }
                r--;
            }
        }
        while(i+1<n && nums[i]==nums[i+1])
            i++;
    }
    return res;
}
