// https://www.interviewbit.com/problems/merge-k-sorted-arrays/
/*
Problem Description

You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.
You need to merge them into a single array and return it.

Problem Constraints
1 <= K, N <= 103
0 <= A[i][j] <= 108
A[i][j] <= A[i][j+1]


Input Format
First and only argument is an 2D integer matrix A.

Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.


Example Input
Input 1:

 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]]

Example Output
Output 1:
 [0, 1, 2, 2, 3, 4, 6, 9, 10]

Example Explanation
Explanation 1:
 You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
 so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]

*/

// Brute Force
// Time Complexity:- O(nk+nk(log(nk)) = O(nk(log(nk)) 
// Space Complexity:- O(nk)

vector<int> Solution::solve(vector<vector<int>> &A) 
{
    int n = A.size();
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            pq.push(A[i][j]);
        }
    }
    while(pq.size()!=0)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}



class compare{
    public:
    bool operator()(pair<int,int> &p1, pair<int,int> &p2){
        return p1.first > p2.first;
    }
};

// Optimal Soln
// Time Complexity:- O(n+nk(log(k)) = O(nk(log(k)) 
// Space Complexity:- O(k+n)


vector<int> Solution::solve(vector<vector<int>> &A) 
{
    int n = A.size();
    int k = A[0].size();
    vector<int> ans;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    vector<int> col(n,1);
    
    for(int i=0;i<n;i++)
    {
        pq.push(make_pair(A[i][0],i));
    }
    while(pq.size()!=0)
    {
        pair<int,int> curr = pq.top();
        pq.pop();
        int ele = curr.first;
        int row = curr.second;
        ans.push_back(ele);
        if(col[row]<k)
        {
            pq.push(make_pair(A[row][col[row]], row));
            col[row]++;
        }
    }
    return ans;
}
