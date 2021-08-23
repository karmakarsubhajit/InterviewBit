// https://www.interviewbit.com/problems/pair-with-given-difference/
/*
Problem Description

Given an one-dimensional unsorted array A containing N integers.
You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.
Return 1 if any such pair exists else return 0.

Problem Constraints
1 <= N <= 105
-103 <= A[i] <= 103
-105 <= B <= 105

Input Format
First argument is an integer array A of size N.
Second argument is an integer B.

Output Format
Return 1 if any such pair exists else return 0.

Example Input
Input 1:
 A = [5, 10, 3, 2, 50, 80]
 B = 78
 
Input 2:
 A = [-10, 20]
 B = 30

Example Output
Output 1:
 1
 
Output 2:
 1

Example Explanation
Explanation 1:
 Pair (80, 2) gives a difference of 78.
 
Explanation 2:
 Pair (20, -10) gives a difference of 30 i.e 20 - (-10) => 20 + 10 => 30
*/

//Brute force solution
// Ordered map is used
// Time complexity:- O(n^2)
// Space complexity:- O(1)

int Solution::solve(vector<int> &A, int B) 
{
   for(int i=0;i<A.size();i++)
   {
       int sm = A[i]+B;
       for(int j=0;j<A.size();j++)
       {
           if(i!=j)
           {
               if(sm==A[j])
                   return 1;
           }
       }
   }
   
    return 0;
}


// Binary Search is used
// Time complexity:- O(nlogn+nlogn)= O(nlogn)
// Space complexity:- O(1)

int binarySearch(vector<int> arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
  

        if (arr[m] == x)
            return 1;

        if (arr[m] < x)
            l = m + 1;
  
        else
            r = m - 1;
    }

    return 0;
}
  

int Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    if(n<=1)
        return 0;
    sort(A.begin(), A.end());
    if(B<0)
        B=-1*B;
    for(int i=0;i<n;i++)
    {
        int t = A[i]+B;
        int ans = binarySearch(A,i+1,n-1,t);
        if(ans)
            return 1;
    }
    return 0;
}


// Sorting
// Time complexity:- O(nlogn+n) = O(nlogn)
// Space complexity:- O(1)

int Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    if(n<=1)
        return 0;
    sort(A.begin(), A.end());
    int i=0;
    int j=1;
    while(i<n && j<n)
    {
        int diff = A[j]-A[i];
        if((i!=j) && (diff==B))
            return 1;
        else if(diff>B)
            i++;
        else
            j++;
    }
    return 0;
}



// Ordered map is used
// Time complexity:- O(nlogn+n) = O(nlogn)
// Space complexity:- O(n)

int Solution::solve(vector<int> &A, int B) 
{
    map<int,int> mp;
    for(int i=0;i<A.size();i++)
        mp[A[i]]++;
    
    for(int i=0;i<A.size();i++)
    {
        if(B==0)
        {
            if(mp[A[i]]>=2)
                return 1;
        }
        else if(mp[A[i]+B]>=1)
            return 1;
    }
    return 0;
}

// Unordered map is used
// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::solve(vector<int> &A, int B) 
{
    unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++)
        mp[A[i]]++;
    
    for(int i=0;i<A.size();i++)
    {
        if(B==0)
        {
            if(mp[A[i]]>=2)
                return 1;
        }
        else if(mp[A[i]+B]>=1)
            return 1;
    }
    return 0;
}


