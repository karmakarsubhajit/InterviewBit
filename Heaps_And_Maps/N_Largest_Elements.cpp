//https://www.interviewbit.com/problems/k-largest-elements/
/*
Problem Description

Given an 1D integer array A of size N you have to find and return the B largest elements of the array A.

NOTE:
Return the largest B elements in any order you like.

Problem Constraints
1 <= N <= 105
1 <= B <= N
1 <= A[i] <= 103

Input Format
First argument is an 1D integer array A

Second argument is an integer B.



Output Format
Return a 1D array of size B denoting the B largest elements.

Example Input
Input 1:
 A = [11, 3, 4]
 B = 2

Input 2:
 A = [11, 3, 4, 6]
 B = 3

Example Output
Output 1:
 [11, 4]

Output 2:
 [4, 6, 11]

Example Explanation
Explanation 1:
 The two largest elements of A are 11 and 4

Explanation 2:
 The three largest elements of A are 11, 4 and 6
*/

// Time complexity:- O(nlogn+k)
// Space complexity:- O(1)

vector<int> Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    sort(A.begin(),A.end());
    vector<int> ans;
    for(int i=n-B;i<n;i++)
        ans.push_back(A[i]);
    return ans;
}

// Time complexity:- O(n+klogn)
// Space complexity:- O(n)

vector<int> Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    priority_queue<int> pq;
    for(auto i:A)
        pq.push(i);
    int sm = 0;
    vector<int> v;
    while(B--)
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}

// Time complexity:- O(k+klogk)
// Space complexity:- O(k)

vector<int> Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    priority_queue<int,vector<int>, greater<int>> pq;
    for(auto i:A)
    {
        if(pq.size()<B)
        {
            pq.push(i);
        }
        else
        {
            int mn = pq.top();
            if(mn<i)
            {
                pq.pop();
                pq.push(i);
            }
        }

    }
        
    
    vector<int> v;
    while(B--)
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}