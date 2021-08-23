// https://www.interviewbit.com/problems/3-sum/
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 

Return the sum of the three integers.
Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

// Time complexity:- O(n^2+nlogn)= O(n^2)
// Space complexity:- O(n)

int Solution::threeSumClosest(vector<int> &A, int B) 
{
    int n = A.size();
    if(n<3)
        return 0;
    sort(A.begin(), A.end());
    int ans = 0;
    long long int min_diff = INT_MAX;
    for(int i=0;i<(n-2);i++)
    {
        int l = i+1;
        int r = n-1;
        while(l<r)
        {
            long long int temp = A[i] + A[l] + A[r];
            long long int diff = abs(B-temp);
            
            if(diff<min_diff)
            {
                min_diff = diff;
                ans = temp;
            }
            if(diff==0)
            {
                return B;
            }
            else if(temp>B)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }  
    return ans; 
}
