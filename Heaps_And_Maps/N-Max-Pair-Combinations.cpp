// https://www.interviewbit.com/problems/n-max-pair-combinations/
/*
Problem Description

Given two integers arrays A and B of size N each.

Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.



Problem Constraints
1 <= N <= 2 * 105

-1000 <= A[i], B[i] <= 1000

Input Format
First argument is an integer array A.

Second argument is an integer array B.

Output Format
Return an intger array denoting the N maximum element in descending order.

Example Input

Input 1:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]

Input 2:
 A = [2, 4, 1, 1]
 B = [-2, -3, 2, 4]

Example Output
Output 1:
 [10, 9, 9, 8]
Output 2:
 [8, 6, 6, 5]


Example Explanation
Explanation 1:
 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).

Explanation 2:
 4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).
*/

// Time complexity:- O(nlogn)
// Space complexity:- O(n)

vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int sm = 0;
    set<pair<int,pair<int,int>>,greater<>> s;
    s.insert({A[n-1]+B[n-1],{n-1,n-1}});
    int K = n;
    vector<int> ans;
    while(K--)
    {
        auto it =  s.begin();
        int sm = (*it).first;
        int x = (*it).second.first;
        int y = (*it).second.second;
        ans.push_back(sm);
        s.erase(*it);
        if(x>=1)
        {
            s.insert({A[x-1]+B[y],{x-1,y}});
        }
        if(y>=1)
        {
            s.insert({A[x]+B[y-1],{x,y-1}});
        }
    }
    return ans;
}
