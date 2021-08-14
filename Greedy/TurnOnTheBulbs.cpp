// https://www.interviewbit.com/problems/turn-on-the-bulbs/
/*
Problem Description

There are A bulbs lined in a row numbered 1 to A, which are off initially. In one step, you can choose any bulb and turn it on.

If you turn a particular bulb on, the bulb 2 places to the right and 2 places to the left of this bulb would also turn on. Bulbs that are already on will not be affected. 

Formally, if you turn on the bulb numbered X, it will also turn on the bulb numbered X - 2 (if it exists) and bulb numbered X + 2 (if it exists).

Find the minimum number of steps required to turn on all the bulbs.

Problem Constraints
1 <= A <= 109

Input Format
The first and only argument contains an integer A.

Output Format
Return a single integer denoting the answer.


Example Input

  Input 1:
  3
  
Input 2:
  1


Example Output
  Output 1:
  2
  
Output 2:
  1

Example Explanation

  Explanation 1:

  One of the optimal way is to -

  1. Turn on bulb numbered 1. It will also turn on bulb numbered 3.
  2. Turn on 2.
Explanation 2:

  We need to turn on the only bulb.
*/

// Time complexity:- O(1)
//Space complexity:- O(1)

int Solution::solve(int A) 
{
    map<int,int> mp;
    mp[1]=1;
    mp[2]=2;
    mp[3]=2;
    mp[4]=2;
    mp[5]=2;
    
    if(A%6==0)
    {
        return (A/6)*2;
    }
    else
        return (A/6)*2+mp[A%6];       
}
