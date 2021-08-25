//First Repeating element

/*
Problem Description

Given an integer array A of size N, find the first repeating element in it.

We need to find the element that occurs more than once and whose index of first occurrence is smallest.

If there is no repeating element, return -1.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 109



Input Format
First and only argument is an integer array A of size N.

Output Format
Return an integer denoting the first repeating element.

Example Input
Input 1:
 A = [10, 5, 3, 4, 3, 5, 6]

Input 2:
 A = [6, 10, 5, 4, 9, 120]

Example Output

Output 1:
 5

Output 2:
 -1

Example Explanation

Explanation 1:
 5 is the first element that repeats
Explanation 2:
 There is no repeating element, output -1

*/

// Brute Force solution
// Time complexity:- O(n^2)
// Space complexity:- O(1)

int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]==A[j])
                return A[i];
        }
    }
    return -1;
    
}



// Two pass solution
// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    map<int,int> mp;
    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]++;
    }
   for(int i=0;i<A.size();i++)
    {
        if(mp[A[i]]>=2)
            return A[i];
    }
   
    return -1;
}

// One pass solution
// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    map<int,int> mp;
    int mn = INT_MAX;
    for(int i=A.size()-1;i>=0;i--)
    {
        mp[A[i]]++;
        if(mp[A[i]]>=2)
        {
            mn = min(mn,i);
        }
    }
   return (mn==INT_MAX)?-1:A[mn];
   
}
