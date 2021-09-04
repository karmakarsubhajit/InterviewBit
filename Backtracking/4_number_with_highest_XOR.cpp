// https://www.interviewbit.com/problems/4-number-with-highest-xor/

/*
Problem Description

R and X are two programs.
R takes an integer array as input and randomly chooses a subsequence of size 4 from it.
X takes an integer array as input and returns the bitwise XOR of all elements.
You pass an integer array A to R and pass the output from R to X. What's the maximum result you can get?

Problem Constraints
4 <= |A| <= 50
0 <= A[i] <= 1e9

Input Format
First and only argument is an integer array A.

Output Format
Return a single integer denoting maximum answer we can get.


Example Input
Input 1:
    A = [1, 2, 3, 4]
    
Input 2:
    A = [0, 2, 3, 1, 5]


Example Output
Output 1:
    4
    
Output 2:
    7

Example Explanation
Explanation 1:
    R must choose all the elements and X returns 4
    
Explanation 2:
    R can choose [0, 3, 1, 5]. X returns 7 

*/

// Brute Force approach
// Time complexity:- O(n^4)
// Space complexity:- O(1)

int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    int ans = 0;
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            for(int k=j+1;k<n-1;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    ans = max(ans,A[i]^A[j]^A[k]^A[l]);
                }
            }
        }
    }
    return ans;
}

// Backtrack
// Time complexity:- O(2^4)
// Space complexity:- O(n), stack space

void backtrack(vector<int>& A, int temp, int cnt, int i, int& ans)
{
  if(cnt==4)
  {
      ans=max(ans,temp);
      return;
  }    
  if(i==A.size())
    return; 
  backtrack(A,temp,cnt,i+1,ans);
  backtrack(A,temp^A[i],cnt+1,i+1,ans);
}

int Solution::solve(vector<int> &A) 
{
    int ans = 0;
    int cnt=0;
    backtrack(A,0,cnt,0,ans);
    return ans;
}
