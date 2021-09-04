// https://www.interviewbit.com/problems/remove-element-from-array/

/*
Remove Element

Given an array and a value, remove all the instances of that value in the array. 

Also return the number of elements left in the array after the operation.

It does not matter what is left beyond the expected length.

Example:

If array A is [4, 1, 1, 2, 1, 3]

and value elem is 1, 

then new length is 3, and A is now [4, 2, 3]

Try to do it in less than linear additional space complexity.
*/


// Time complexity:- O(n)
// Space complexity:- O(1)

int Solution::removeElement(vector<int> &A, int B) {
    int l = A.size();
    int p = 0;
    int i=-1;
    int j=0;
    int c = 0;
    while(j<l)
    {
        
        if(A[j]==B)
        {
            if(i==-1)
                i=j;
            c++;
        }
        else 
        {
            if(i!=-1)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
            }
        }
        j++;
    }
    return l-c;
}
