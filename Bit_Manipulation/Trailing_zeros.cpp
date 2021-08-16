// https://www.interviewbit.com/problems/trailing-zeroes/
/*
Problem Description
Given an integer A, count and return the number of trailing zeroes.

Problem Constraints
1 <= A <= 109

Input Format
First and only argument is an integer A.

Output Format
Return an integer denoting the count of trailing zeroes.



Example Input
Input 1:
 A = 18

Input 2:
 A = 8

Example Output
Output 1:
 1

Output 2:
 3

Example Explanation
Explanation 1:
18 in binary is represented as: 10010, there is 1 trailing zero.

Explanation 2:
8 in binary is represented as: 1000, there are 3 trailing zeroes.
*/

// Time complexity:- O(logA)
// Space complexity:- O(1)

int Solution::solve(int A) 
{
    int t = A;
    int c = 0;
    int i=0;
    while(A!=0)
    {
        int t = (A>>i)&(1);
        if(t==0)
        {
            c++;
            i++;
        }
        else
            return c;
    }
}

// Time complexity:- O(1)
// Space complexity:- O(1)
// A&(-A) gives the rightmost set bit in the number A
// Ex:- A= 1001100, then A&(-A) gives 0000100
// log2(100) gives 2

int Solution::solve(int A) 
{
    return log2(A&(-A));
}


