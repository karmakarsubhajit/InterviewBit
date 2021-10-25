// https://www.interviewbit.com/problems/noble-integer/

/*
Problem Description

Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.



Input Format
First and only argument is an integer array A.



Output Format
Return 1 if any such integer p is found else return -1.



Example Input
Input 1:

 A = [3, 2, 1, 3]
Input 2:

 A = [1, 1, 3, 3]


Example Output
Output 1:

 1
Output 2:

 -1


Example Explanation
Explanation 1:

 For integer 2, there are 2 greater elements in the array. So, return 1.
Explanation 2:

 There is no such integer exists.
*/


// Time complexity:- O(nlogn)
// Space complexity:- O(1)

int Solution::solve(vector<int> &A) 
{
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++)
    {
        int curr = A[i];
        if(i+1<A.size() && A[i+1]==curr)
        {
            continue;
        }
        int number_of_int_greater = A.size()-i-1;
        if(number_of_int_greater==curr)
            return 1;
    }
    return -1;
}
