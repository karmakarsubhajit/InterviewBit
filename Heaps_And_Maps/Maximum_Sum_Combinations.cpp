// https://www.interviewbit.com/problems/maximum-sum-combinations/
/*
Problem Description

Given two equally sized 1-D arrays A, B containing N integers each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum C valid sum combinations from all the possible sum combinations.

Problem Constraints
 1 <= N <= 105
 1 <= A[i] <= 103
 1 <= C <= N

Input Format
First argument is an one-dimensional integer array A of size N.

Second argument is an one-dimensional integer array B of size N.

Third argument is an integer C.


Output Format
Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

NOTE:
The returned array must be sorted in non-increasing order.


Example Input
Input 1:
 A = [3, 2]
 B = [1, 4]
 C = 2

Input 2:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4

Example Output
Output 1:
 [7, 6]

Output 1:
 [10, 9, 9, 8]


Example Explanation
Explanation 1:
 7     (A : 3) + (B : 4)
 6     (A : 2) + (B : 4)

Explanation 2:
 10   (A : 4) + (B : 6)
 9   (A : 4) + (B : 5)
 9   (A : 3) + (B : 6)
 8   (A : 3) + (B : 5)
*/

// Time complexity:- O(n^2)
// Space complexity:- O(n^2)

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = B.size();
    priority_queue<int> pq;
    
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            pq.push(A[i]+B[j]);
        }
    }
    while(C--)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}

// Space complexity:- O(C)
// Time complexity:- O(ClogC)  if C ~ O(n), then O(nlogn)

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> pairCheck;
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    pairCheck.insert({n-1,n-1});
    vector<int> ans;
    

    while(C--)
    {
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();
        int sm = p.first;
        int x = p.second.first;
        int y = p.second.second;
        ans.push_back(sm);
        pair<int,int> a= make_pair(x-1,y);
        if(pairCheck.find(a)==pairCheck.end())
        {
            pq.push({A[x-1]+B[y],a});
            pairCheck.insert(a);
        }
        pair<int,int> b= make_pair(x,y-1);
        if(pairCheck.find(b)==pairCheck.end())
        {
            pq.push({A[x]+B[y-1],b});
            pairCheck.insert(b);
        }
    }
    return ans;
}

