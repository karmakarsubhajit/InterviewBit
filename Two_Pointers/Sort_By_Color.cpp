//https://www.interviewbit.com/problems/sort-by-color/

/*
Given an array with n objects colored red, white or blue, 

sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]

*/

// Time complexity:- O(n)
// Space complexity:- O(1)

void swap(vector<int>& A, int i, int j)
{
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void Solution::sortColors(vector<int> &A) 
{
    int n = A.size();
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid<=high)
    {
        if(A[mid]==0)
        {
            swap(A,mid,low);
            
            low++;
            mid++;
        }
        else if(A[mid]==1)
        {
            mid++;   
        }
        else
        {
            swap(A,mid,high);
            high--;
        }
    }

}
