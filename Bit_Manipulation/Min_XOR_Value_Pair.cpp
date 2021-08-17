// https://www.interviewbit.com/problems/min-xor-value/
/*
Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Input Format:

    First and only argument of input contains an integer array A
Output Format:

    return a single integer denoting minimum xor value
Constraints:

2 <= N <= 100 000  
0 <= A[i] <= 1 000 000 000
For Examples :

Example Input 1:
    A = [0, 2, 5, 7]
Example Output 1:
    2
Explanation:
    0 xor 2 = 2
Example Input 2:
    A = [0, 4, 7, 9]
Example Output 2:
    3
*/

// Brute Force soln
// Time complexity:- O(n^2)
// Space complexity:- O(1)


int Solution::findMinXor(vector<int> &A) 
{
    int n = A.size();
    sort(A.begin(), A.end());
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
         for(int j=i+1;j<n;j++)
         {
              ans = min(ans,A[i]^A[j]);   
         }
    }
    
    return ans;
}


// Optimal soln
// Elements which are closer to each other have more no of same bits at similar position and on xoring them, they become zero
// Time complexity:- O(nlogn)
// Space complexity:- O(1)

int Solution::findMinXor(vector<int> &A) 
{
    int n = A.size();
    sort(A.begin(), A.end());
    int ans = INT_MAX;
    for(int i=1;i<n;i++)
    {
        ans = min(ans,A[i]^A[i-1]);
    }
    
    return ans;
}
