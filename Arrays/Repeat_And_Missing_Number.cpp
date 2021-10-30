// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
/*
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.

This is one of those problems.

Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

// Time complexity:- O(n) 
// Space complecity:- O(1)

vector<int> Solution::repeatedNumber( vector<int> A) 
{
    long long int n = A.size();
    long long int sum_till_n = n*(n+1)/2;
    long long sm = 0;
    for(auto i:A)
        sm+=i;
    int d  = A[0];
    for(int i=0;i<A.size();i++)
    {
        int idx = abs(A[i])-1;
        if(A[idx]<0)
        {
            d = idx+1;
            break;
        }
        A[idx] = -1*A[idx];
    }
    vector<int> ans;
    ans.push_back(d);
    ans.push_back(sum_till_n-sm+d);
    return ans;
}
