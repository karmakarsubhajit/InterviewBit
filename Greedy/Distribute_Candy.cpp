// https://www.interviewbit.com/problems/distribute-candy/
/*
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
Example:

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1]
*/

// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::candy(vector<int> &A) 
{
    int n = A.size();
    vector<int> B;
    for(int i=0;i<n;i++)
    {
        B.push_back(1);
    }
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[i-1])
            B[i] = B[i-1]+1;
    }
    int sm = 0;
    sm = B[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]>A[i+1])
            B[i] = max(B[i],B[i+1]+1);
        sm+=B[i];
    }
    return sm;
}

// Time complexity:- O(n)
// Space complexity:- O(1)

int Solution::candy(vector<int> &A) 
{
    int n = A.size();
    if((n==0) || (n==1))
        return n;
    int cand = 1;
    int sm = 1;
    int i = 1;
    while(i<n)
    {
        if(A[i]<A[i-1])
        {
            int c = 0;
            while(A[i]<A[i-1] && (i<n))
            {
                c++;
                i++;
            }
            if(c>=cand)
            {
                sm = sm - (cand) +(c+1);
            }
            sm+=(c*(c+1))/2;
            cand = 1;
        }
        else if(A[i]>A[i-1])
        {
            cand++;
            sm+= cand;
            i++;
        }
        else
        {
            cand = 1;
            sm+= cand;
            i++;
        }
    }
    return sm;
}

