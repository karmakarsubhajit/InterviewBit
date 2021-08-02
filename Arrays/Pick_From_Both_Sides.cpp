//https://www.interviewbit.com/problems/pick-from-both-sides/

//Time complexity:- O(B)
//Space compleity:- O(1)

int Solution::solve(vector<int> &A, int B) 
{
    int l = A.size();

    int curr_sum = 0;
    for(int i=0;i<B;i++)
        curr_sum+=A[i];
    
    int maxSum = curr_sum;
    
    for(int i=0;i<B;i++)
    {
        curr_sum-=A[B-1-i];
        curr_sum+=A[l-1-i];
        maxSum=max(curr_sum, maxSum);
    }
    
    return maxSum;
}
