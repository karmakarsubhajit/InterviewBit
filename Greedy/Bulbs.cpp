//https://www.interviewbit.com/problems/interview-questions/

//Time Complexity:- O(n)
//Space Complexity:- O(1)

int Solution::bulbs(vector<int> &A) 
{
    int n = A.size();
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==1)
        {
            if(c%2==1)
                c++;
        }
        else
        {
            if(c%2==0)
                c++;
        }
    }
    return c;
}
