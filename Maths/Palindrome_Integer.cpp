// https://www.interviewbit.com/problems/palindrome-integer/
/*
Problem Description

Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed. Negative numbers are not palindromic.

Example :

Input : 12121
Output : True


Input : 123
Output : False
*/

// Time complexity:- O(log10(A))
// Space complexity:- O(1)

int Solution::isPalindrome(int A) 
{
    if(A<0)
        return 0;
    if(A==0)
        return 1;
    int res=0;

    int temp = A;
    while(temp!=0)
    {
        int d = temp%10;
        res=res*10+d;
        temp = temp/10;

    }


    return res==A;
}
