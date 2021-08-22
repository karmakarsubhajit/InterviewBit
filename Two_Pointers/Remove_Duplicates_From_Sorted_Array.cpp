// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
/*
Problem Description

Given a sorted array A consisting of duplicate elements.
 Your task is to remove all the duplicates and return a sorted array of distinct elements consisting of all distinct elements present in A.
But, instead of returning an answer array, you have to rearrange the given array in-place such that it resembles what has been described above.
Hence, return a single integer, the index(1-based) till which the answer array would reside in the given array A.
Note: This integer is the same as the number of integers remaining inside A had we removed all the duplicates.
Look at the example explanations for better understanding.



Input Format
First and only argurment containing the integer array A.



Output Format
Return a single integer, as per the problem given.


Example Input
Input 1:
A = [1, 1, 2]

Input 2:
A = [1, 2, 2, 3, 3]


Example Output
Output 1:
2

Output 2:
3


Example Explanation
Explanation 1:
Updated Array: [1, 2, X] after rearranging. Note that there could be any number in place of x since we dont need it.
We return 2 here.
Explanation 2:
Updated Array: [1, 2, 3, X, X] after rearranging duplicates of 2 and 3.
We return 3 from here.
*/

// Time complexity:- O(n)
// Space complexity:- O(1)

int Solution::removeDuplicates(vector<int> &A) {

    int n = A.size();
    if(n<=1)
        return n;
    bool t = false;
    if(A[n-1]==A[n-2])
        t=true;
    int k = 0;
    int i=0;
    int j=0;
    while(i<(n-1))
    {
        if(A[i]==A[i+1])
        {
            j = i;
            while((j<n-1) && (A[j]==A[j+1]))
            {
                j++;
            }
            A[k] = A[j];
            k++;
            i=j+1;   
        }
        else
        {
            A[k] = A[i];
            k++;
            i++;
        }            
    }
    if(t==false)
    {
        A[k]=A[i];
        k++;
    }
 
    return k;
}


// CLeaner code
// Time complexity:- O(n)
// Space complexity:- O(1)


int Solution::removeDuplicates(vector<int> &A) {

    int cnt = 0;
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        if((i<(n-1)) && (A[i]==A[i+1]))
        {
            continue;

        }
        else
        {
            A[cnt] = A[i];
            cnt++; 
        }
    }
    return cnt;
}
