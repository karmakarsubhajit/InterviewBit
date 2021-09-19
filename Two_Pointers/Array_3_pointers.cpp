// https://www.interviewbit.com/problems/array-3-pointers/
/*
You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :
Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]
Output : 5 
         With 10 from A, 15 from B and 10 from C. 
*/

// Brute Force solution
// Time complexity:- O(n^3)
// Space complexity:- O(1)

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int ans = INT_MAX;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            for(int k=0;k<n3;k++)
            {
                ans = min(ans,max(max(abs(A[i]-B[j]),abs(B[j]-C[k])),abs(A[i]-C[k])));
            }
        }
    }
    return ans;
}


// Optimal solution || Linear
// Time complexity:- O(n1+n2+n3), where n1, n2 and n3 are size of array
// Space complexity:- O(1)


int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    int ans =INT_MAX;
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while((i<n1) && (j<n2) && (k<n3))
    {
        int mn = min(min(A[i],B[j]),C[k]);
        int mx = max(max(A[i],B[j]),C[k]);
        ans = min(ans,mx-mn);
        if(ans==0)
           return ans;
        if(mn==A[i])
            i++;
        else if(mn==B[j])
            j++;
        else 
            k++;
    }
    return ans;
}
