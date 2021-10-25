// https://www.interviewbit.com/problems/wave-array/
/*
Problem Description

Given an array of integers A, sort the array into a wave like array and return it, In other words, arrange the elements into a sequence such that 

a1 >= a2 <= a3 >= a4 <= a5.....
NOTE : If there are multiple answers possible, return the one that's lexicographically smallest.

Problem Constraints
1 <= len(A) <= 106
1 <= A[i] <= 106


Input Format
First argument is an integer array A.
*/


//  sorting
// Time Complexity:- O(nlogn)
// Space Complexity:- O(1)

vector<int> Solution::wave(vector<int> &A) 
{
    sort(A.begin(), A.end());
    for(int i=0;i<A.size()-1;i+=2)
    {
        int t = A[i];
        A[i] = A[i+1];
        A[i+1] = t;
    }
    return A;
}



// Time Complexity:- O(n)
// Space Complexity:- O(1)

vector<int> Solution::wave(vector<int> &A) 
{
    for(int i=0;i<A.size();i+=2)
    {
        if(i!=0 && A[i]<A[i-1])
        {
            int t = A[i];
            A[i] = A[i-1];
            A[i-1]=t;
        }
        if((i!=A.size()-1) && A[i]<A[i+1])
        {
            int t = A[i];
            A[i] = A[i+1];
            A[i+1]=t;
        }
    }
    return A;
}
