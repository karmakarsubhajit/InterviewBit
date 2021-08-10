// https://www.interviewbit.com/problems/maxspprod/

/*
Problem Description

You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

NOTE:  As the answer can be large, output your answer modulo 109 + 7.



Problem Constraints
1 <= N <= 105
 
1 <= A[i] <= 109



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum special product of any integer.



Example Input
Input 1:

 A = [1, 4, 3, 4]
Input 2:

 A = [10, 7, 100]


Example Output
Output 1:

 3
Output 2:

 0


Example Explanation
Explanation 1:

 For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
 So, the ans is 1*3 = 3.
 
Explanation 2:

 There is not any integer having maximum special product > 0. So, the ans is 0.

*/


//Time complexity:- O(n)
//Space complexity:- O(n)

int Solution::maxSpecialProduct(vector<int> &A) 
{
    long long int n = A.size();
    long long int i = 0;
    vector<long long int> L(n,0);
    vector<long long int> R(n,0);
    stack<long long int> st;
    while(i<n)
    {
        if(st.empty()!=1 && A[i]>A[st.top()])
        {
            while(st.empty()!=1 && A[i]>A[st.top()])
            {
                long long int t = st.top();
                st.pop();
                R[t] = i;
            }
            st.push(i);
        }
        else
            st.push(i);
        i++;
    }
    while(st.empty()==0)
    {
        R[st.top()]=0;
        st.pop();
    }
    stack<long long int> st1;
    st=st1;
    i=n-1;
    while(i>=0)
    {
        if(st.empty()!=1 && A[i]>A[st.top()])
        {
            while(st.empty()!=1 && A[i]>A[st.top()])
            {
                long long int t = st.top();
                st.pop();
                L[t] = i;
            }
            st.push(i);
        }
        else
            st.push(i);
        i--;
    }
    while(st.empty()==0)
    {
        L[st.top()]=0;
        st.pop();
    }
    long long int mx = 0;
    for(i=0;i<n;i++)
    {
        mx = max(mx,(L[i]*R[i]));
    }
    return (int)(mx%1000000007);   
}
