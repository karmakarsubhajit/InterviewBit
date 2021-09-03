// https://www.interviewbit.com/problems/permutations/
/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
NOTE

No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.

*/

// Backtracking + Swapping
// Time complexity:- O(n*n!)
// Space complexity:- O(n), stack space


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;

}
void getAns(int i, int n, vector<vector<int>>& ans, vector<int>& A)
{
   if(i==n)
   {
       ans.push_back(A);
       return;
   }
   for(int j=i;j<n;j++)
   {
      swap(&A[i], &A[j]);
      getAns(i+1,n,ans,A);
      swap(&A[i], &A[j]);
   }
   
}

vector<vector<int>> Solution::permute(vector<int> &A) 
{
    vector<vector<int>> ans;
    int n = A.size();
    if(n<=0)
      return ans;
     
    int i = 0;
    getAns(0,n,ans,A);
    return ans;
}
