// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

//Time complexity:- O(n) ---n is no of points in question
//Space complexity:- O(1)

int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    int l = A.size();
    if(l<=1)
        return 0;

    int x = A[0];
    int y = B[0];
    int dis=0;
    
    for(int i=1;i<l;i++)
    {
        int dx = abs(A[i]-x);
        int dy = abs(B[i]-y);
        dis+=min(dx,dy)+abs(dy-dx);
        x=A[i];
        y=B[i];
    }
    return dis;
}

