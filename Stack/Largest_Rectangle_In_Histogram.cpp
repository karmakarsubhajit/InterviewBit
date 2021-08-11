// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

/*
Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.
Find the area of the largest rectangle formed by the histogram.

Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000

Input Format
The only argument given is the integer array A.

Output Format
Return the area of largest rectangle in the histogram.

Example Input
Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]

Example Output
Output 1:

 10
Output 2:

 2
*/

// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::largestRectangleArea(vector<int> &A) 
{
    stack<int> st;
    int i = 0;
    int mx = -1;
    int l = A.size();
    while(i<l)
    {
        if((st.empty()) || (A[i]>=A[st.top()]))
        {
            st.push(i);
            i++;
        }
        else
        {
            while((!st.empty()) && (A[i]<A[st.top()]))
            {
                int ind = st.top();
                st.pop();
                int ar;
                if(st.empty())
                {
                    ar = i*A[ind];
                }
                else
                {
                    ar = (i-st.top()-1)*A[ind];
                }
                mx = max(ar, mx);
            }
            st.push(i);
            i++;
        }
    }
    while(!st.empty())
    {
        int ind = st.top();
        st.pop();
        int ar;
        if(st.empty())
        {
            ar = i*A[ind];
        }
        else
        {
            ar = (i-st.top()-1)*A[ind];
        }
        mx = max(ar, mx);
    }
    return mx;
}
