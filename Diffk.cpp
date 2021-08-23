// https://www.interviewbit.com/problems/diffk/
/*
Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example:
Input :
    A : [1 3 5] 
    k : 4
    
Output : YES
as 5 - 1 = 4
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
Try doing this in less than linear space complexity.
*/

// Using Hash table
// Time complexity:-O(nlogn)
// Space complexity:- O(n)
int Solution::diffPossible(vector<int> &A, int B) 
{
    if(A.size()<=1)
        return 0;
    map<int,int> mp;
    for(auto i:A)
        mp[i]++;
    for(auto i:A)
    {
        if(B==0)
        {
            if(mp[i]>=2)
            {
                return 1;
            }    
        }
            
        else 
        {
            if(mp[i+B]>=1)
            {
                return 1;
            }
        }  
    }
    return 0;
}
