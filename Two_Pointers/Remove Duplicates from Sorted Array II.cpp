// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

/*
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,

Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].
*/

// Inplace update
// Time complexity:- O(n)
// Space complexity:- O(1)

int Solution::removeDuplicates(vector<int> &A) 
{

    int n = A.size();
    int i = -1;
    int j = 0;

    while(j<n)
    {
        int c = 1;
        int temp = A[j];
        while(((j+1)<n) && (A[j]==A[j+1]))
        {
            c++;
            j++;
        }
        c=min(c,2);
        while(c--)
        {
            A[i+1] = temp;
            i++;
        }
        j++;
    }
    return i+1;
}
