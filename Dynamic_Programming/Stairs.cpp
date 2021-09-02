// https://www.interviewbit.com/problems/stairs/

/*
You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input Format:

The first and the only argument contains an integer A, the number of steps.
Output Format:

Return an integer, representing the number of ways to reach the top.
Constrains:

1 <= A <= 36
Example :

Input 1:

A = 2 
Output 1:
2 

Explanation 1:
[1, 1], [2] 

Input 2:
A = 3 

Output 2:
3 Explanation 2: 

[1 1 1], [1 2], [2 1]

*/

// Brute force recursive
// Time complexity:- O(2^n)
// Space complexity:- O(n), stack space

int Solution::climbStairs(int A) 
{
    if(A==1) 
       return 1;
    if(A==2)
       return 2;
    if(A==0)
       return 0;
    return climbStairs(A-1)+climbStairs(A-2);
}


// Memoize soln
// Time complexity:- O(n)
// Space complexity:- O(n)


int compute(vector<int>& dp, int A)
{
   if(A<=2)
     return A;
    if(dp[A]!=-1)
      return dp[A];
    dp[A] = compute(dp,A-1)+compute(dp,A-2);
    return dp[A];
}

int Solution::climbStairs(int A) 
{
    vector<int> v(A+1,-1);
    return compute(v,A);
}

