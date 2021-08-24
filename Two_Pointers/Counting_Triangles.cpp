//https://www.interviewbit.com/problems/counting-triangles/
/*
You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:
You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.
For example,
A = [1, 1, 1, 2, 2]
Return: 4
*/

// Brute Force solution
// Time complexity:- O(n^3)
// Space complexity:- O(1)

int Solution::nTriang(vector<int> &A) 
{
    int ans=0;
    int n = A.size();
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if((i!=j)&&(j!=k))
                {
                    int a = A[i];
                    int b = A[j];
                    int c = A[k];
                    if(a+b>c && b+c>a && c+a>b)
                        ans++;
                }
            }
        }
    }
    return ans;
}

// Sorting + two nested loop solution
// Time complexity:- O(n^2)
// Space complexity:- O(1)

int Solution::nTriang(vector<int> &A) 
{
    int ans=0;
    int n = A.size();
    if(n<=2)
        return 0;

    sort(A.begin(), A.end());
    for(int i=0;i<n-2;i++)
    {
        int k = i+2;
        for(int j=i+1;j<n-1;j++)
        {
            while(k<n && (A[i]+A[j])>A[k])
                k++;
            ans= (ans%1000000007+(k-j-1)%1000000007)%1000000007;    
        }
    }
    return ans%1000000007;
}

