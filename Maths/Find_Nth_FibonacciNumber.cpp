// https://www.interviewbit.com/problems/find-nth-fibonacci/
/*
Problem Description

Given an integer A you need to find the Ath fibonacci number modulo 109 + 7.
The first fibonacci number F1 = 1
The first fibonacci number F2 = 1
The nth fibonacci number Fn = Fn-1 + Fn-2 (n > 2)


Problem Constraints
1 <= A <= 109.



Input Format
First argument is an integer A.

Output Format
Return a single integer denoting Ath fibonacci number modulo 109 + 7.

Example Input
Input 1:
 A = 4
 
Input 2:
 A = 3


Example Output
Output 1:
 3
 
Output 2:
 2

Example Explanation
Explanation 1:
 F3 = F2 + F1 = 1 + 1 = 2
 F4 = F3 + F2 = 2 + 1 = 3

Explanation 2:
 F3 = F2 + F1 = 1 + 1 = 2
*/

//Time complexity:- O(n)
// Space complexity:- O(1)

int Solution::solve(int A) 
{
    if(A==1)
        return 1;
    if(A==2)
        return 1;
    long long int a =1;
    long long int b= 1;
    long long int ans;
    for(int i=3;i<=A;i++)
    {
        ans=(a%1000000007+b%1000000007)%1000000007;
        a=b;
        b=ans;
    }
    return (int)ans;
}
