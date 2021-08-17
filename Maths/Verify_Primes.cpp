// https://www.interviewbit.com/problems/verify-prime/
/*
Given a number N, verify if N is prime or not.

Return 1 if N is prime, else return 0.

Example :

Input : 7
Output : True
*/

// Time complexity:- O(sqrt(n))
// Space complexity:- O(1)

int Solution::isPrime(int A) 
{
    if(A<=1)
        return 0;
    for(int i=2;i<=sqrt(A);i++)
    {
        if(A%i==0)
            return 0;
    }
    return 1;
}


