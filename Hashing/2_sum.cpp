// https://www.interviewbit.com/problems/2-sum/

/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
*/


// Brute Force soln
// Time complexity:- O(n^2)
// Space complexity:- O(n^2)

bool compare(vector<int>& A, vector<int>& B)
{
    if(A[1]<B[1])
        return true;
    else if(A[1]==B[1])
    {
        return A[0]<B[0];
    }
    else
        return false;
}
vector<int> Solution::twoSum(const vector<int> &A, int B) 
{
    int n = A.size();
    if(n<=1)
        return {};
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((A[i]+A[j])==B)
            {
                v.push_back({i+1,j+1});
            }
        }
    }
    if(v.size()==0)
        return {};
    sort(v.begin(), v.end(), compare);
    return v[0];
}
