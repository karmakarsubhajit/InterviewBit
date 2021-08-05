//https://www.interviewbit.com/problems/highest-product/

//Greedy Solution

//Time complexity:- O(nlogn)
//Space complexity:- O(1)


int Solution::maxp3(vector<int> &A) 
{
    int n = A.size();
    if(n==1)
        return A[0];
    if(n==2)
        return A[0]*A[1];
    if(n==3)
        return A[0]*A[1]*A[2];
    sort(A.begin(), A.end());
    return max(A[A.size()-3]*A[A.size()-1]*A[A.size()-2],A[0]*A[1]*A[A.size()-1]);
}
