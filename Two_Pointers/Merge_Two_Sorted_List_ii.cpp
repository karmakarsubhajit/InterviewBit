//https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result.

If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n
Example :
Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]
*/
// Time complexity:- O(m+n)
// Space complexity:- O(m+n)

void Solution::merge(vector<int> &A, vector<int> &B) {

    int m = A.size();
    int n = B.size();
    vector<int> v(m+n,0);
    int i=0;
    int j=0;
    int k=0;
    while((i<m) && (j<n))
    {
        if(A[i]<B[j])
        {
            v[k++]=A[i++];
        }
        else
            v[k++]=B[j++];
    }
    while(i<m)
    {
        v[k++]=A[i++];
    }
     while(j<n)
    {
        v[k++]=B[j++];
    }
    for(i=0;i<m;i++)
    {
        A[i]=v[i];
    }
    for(i=m;i<m+n;i++)
    {
        A.push_back(v[i]);
    }

}
