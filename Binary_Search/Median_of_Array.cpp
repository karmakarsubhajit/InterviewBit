//https://www.interviewbit.com/problems/median-of-array/
/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. 

For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5

*/



// Optimal solution | Binary Search
// Time complexity:- O(log(m+n))
// Space complexity:- O(1)

double compute(const vector<int> &A, const vector<int> &B)
{
    int m = A.size();
    int n = B.size();

    int start = 0;
    int end = m;

    while(start<=end)
    {
        int partX = (start+end)/2;
        int partY = (m+n+1)/2-partX;

        int maxXleft = (partX==0)?INT_MIN:A[partX-1];
        int maxYleft = (partY==0)?INT_MIN:B[partY-1];

        int minXright = (partX==m)?INT_MAX:A[partX];
        int minYright = (partY==n)?INT_MAX:B[partY];

        if((maxXleft<=minYright)&&(maxYleft<=minXright))
        {
            if((m+n)%2==0)
            {
                return ((double)(max(maxXleft,maxYleft))+(double)(min(minXright,minYright)))/2;              ;
            }
            else
                return max(maxXleft,maxYleft);
        }
        else if(maxXleft>minYright)
        {
            end = partX-1;
        }
        else
        {
            start = partX+1;
        }
    }
    return 0.0;
}


double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()>B.size())
        return compute(B,A);
    return compute(A,B);
}
