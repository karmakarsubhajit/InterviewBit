bool search(vector<string> &A, string B,int p, int i, int j, int m, int n)
{
    if(p==(B.length()-1))
        return true;

    vector<int> dx{-1, 1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    bool ans=false;
    for(int k=0;k<4;k++)
    {
        int X = i+dx[k];
        int Y = j+dy[k];
        if((X>=0) && (X<m) & (Y>=0) && (Y<n) && (A[X][Y]==B[p+1]))
            ans = ans || search(A,B,p+1,X,Y,m,n);
            if(ans)
                return true;
    }    
    return false;
}

int Solution::exist(vector<string> &A, string B) 
{
    int m = A.size();
    int n = A[0].length();
    bool ans=false;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==B[0])
            {
                ans = ans || search(A,B,0,i,j,m,n);
                if(ans)
                    return ans;
            }
        }
    }
    return false;
}
