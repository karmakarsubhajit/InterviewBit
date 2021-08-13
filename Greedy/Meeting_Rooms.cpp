// https://www.interviewbit.com/problems/meeting-rooms/

/*
Problem Description
Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:
A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.

Problem Constraints
1 <= N <= 10

0 <= A[i][0] < A[i][1] <= 2 * 109

Input Format
The only argument given is the matrix A.

Output Format
Return the minimum number of conference rooms required so that all meetings can be done.

Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:
 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]

Example Output
Output 1:
 2

Output 2:
 4

Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
Explanation 2:

 Meeting one can be done in conference room 1 from 1 - 18.
 Meeting five can be done in conference room 2 from 2 - 11.
 Meeting four can be done in conference room 3 from 4 - 15.
 Meeting six can be done in conference room 4 from 5 - 13.
 Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
 Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.
*/

// Min Heap solution
// Time complexity:- O(nlogn)
// Space complexity:- O(n)

bool compare(vector<int>& a, vector<int>& b)
{
    return a[0]<b[0];
}

int Solution::solve(vector<vector<int> > &A) 
{
    sort(A.begin(),A.end(),compare);
    
    int c = 1;
    int n = A.size();
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(A[0][1]);
    for(int j=1;j<n;j++)
    {
        if(A[j][0]>=pq.top())
        {
            pq.pop();
        }
        else
        {
            c++;
        }
        pq.push(A[j][1]);
    }
    return c;
}

// Faster solution involving array of size 2*n
// Time complexity:- O(nlogn)
// Space complexity:- O(n)


int Solution::solve(vector<vector<int> > &A) 
{
    vector<pair<int,int>> p;
    
    
    for(auto i:A)
    {
        p.push_back(make_pair(i[0],1));
        p.push_back(make_pair(i[1],0));
    }    
    sort(p.begin(), p.end());
   
    int n = p.size();
    int c = 0;
    int i = 0;
    int mx = 0;
    while(i<p.size())
    {
        if( p[i].second==1)
        {
            c++;
            i++;
        }
        else
        {
            c--;
            i++;
        }
        mx = max(mx,c);
    }
    return mx;
}