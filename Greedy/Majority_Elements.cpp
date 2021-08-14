// https://www.interviewbit.com/problems/majority-element/
/*
Problem Description

Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.

*/

// Using Hash Map
// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::majorityElement(const vector<int> &A) 
{
    map<int,int> mp;
 
    int n = A.size();
    
    if(n==1)
        return A[0];
    for(auto i:A)
    {
        mp[i]++;
    }
    for(auto i:A)
    {
        if(mp[i]>(n/2))
            return i;
    }
}

// Time complexity:- O(n)
// Space complexity:- O(1)

int Solution::majorityElement(const vector<int> &A) 
{
    int c = 0;
    int ele = 0;
 
    int n = A.size();
    
    if(n==1)
        return A[0];
    for(auto i:A)
    {
        if(c==0)
            ele = i;
        if(ele==i)
            c++;
        else
          c--;
    }
    return ele;
}