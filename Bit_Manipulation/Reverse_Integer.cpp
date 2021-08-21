// https://www.interviewbit.com/problems/reverse-integer/
/*
Problem Description

You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer
Look at the example for clarification.

Problem Constraints
N belongs to the Integer limits.

Input Format
Input an Integer.

Output Format
Return a single integer denoting the reverse of the given integer.


Example Input
Input 1:
 x = 123

Input 2:
 x = -123

Example Output
Output 1:
 321
 
Ouput 2:
 -321

Example Explanation
 If the given integer is negative like -123 the output is also negative -321.
*/

// Time complexity:- O(log10(A))
// Space complexity:- O(1)

int Solution::reverse(int A) 
{
    int res = 0;
    while(A!=0)
    {
        int d = A%10;
        if((res>INT_MAX/10) || (res==INT_MAX/10 && d>7))
            return 0;
        if((res<INT_MIN/10) || (res==INT_MAX/10 && d<-8))
            return 0;
        res = res*10+d;
        A=A/10;
    }
    return res;
}
