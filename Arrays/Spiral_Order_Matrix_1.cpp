// https://www.interviewbit.com/problems/spiral-order-matrix-i/

// Time:- O(m*n)
//Space:- O(1)
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) 
{
    int m = A.size();
    int n = A[0].size();
    vector<int> v;
    int top = 0;
    int down = m-1;
    int left = 0;
    int right = n-1;
    int dir =0;
    while(1)
    {
        
        if(dir==0)
        {
            for(int j=left;j<=right;j++)
            {
                v.push_back(A[top][j]);
            }
            top++;
            dir=1;
        }
        else if(dir==1)
        {
            for(int i=top;i<=down;i++)
            {
                v.push_back(A[i][right]);
            }
            right--;
            dir=2;
        }
        else if(dir==2)
        {
            for(int j=right;j>=left;j--)
            {
                v.push_back(A[down][j]);
            }
            down--;
            dir=3;
        }
        else if(dir==3)
        {
            for(int i=down;i>=top;i--)
            {
                v.push_back(A[i][left]);
            }
            dir=0;
            left++;
        }
        if(v.size()==(m*n))
            break;
    }
    return v;
}
