//https://www.interviewbit.com/problems/rain-water-trapped/

/*
Problem Description
Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Problem Constraints
1 <= |A| <= 100000


Input Format
The only argument given is integer array A.


Output Format
Return the total water it is able to trap after raining.

Example Input
Input 1:
 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Input 2:
 A = [1, 2]

Example Output
Output 1:
 6
Output 2:
 0

*/

// Time complexity:- O(n)
// Space complexity:- O(n)
// Two arrays used

int Solution::trap(const vector<int> &A) 
{
    int l = A.size();
    vector<int> left(l,-1);
    vector<int> right(l,-1);
    left[0] = A[0];
    right[l-1] = A[l-1];
    int i=1;
    while(i<l-1)
    {
        left[i] = max(left[i-1],A[i]);
        right [l-1-i] = max(right[l-i],A[l-1-i]);
        i++;
    }

    int s = 0;
    for(int i=1;i<(l-1);i++)
    {
        if((left[i]>A[i]) && (right[i]>A[i]))
            s+= min(left[i],right[i])-A[i];
    }
    return s;
}
