//https://www.interviewbit.com/problems/find-duplicate-in-array/

/*
Problem Description

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/


// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::repeatedNumber(const vector<int> &A) 
{
    unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]++;
        if(mp[A[i]]>=2)
            return A[i];
    }
    return -1;
}
