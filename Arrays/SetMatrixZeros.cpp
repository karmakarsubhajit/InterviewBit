// https://www.interviewbit.com/problems/set-matrix-zeros/

/*
Problem Description

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]


Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]

*/





// Brute Force
// Time complexity:- O(m*n*(m+n))
// Space complexity:- O(m*n)

void setZeroHelp(int i, int j, int m, int n, vector<vector<int>>& matrix)
{
    for(int a=0;a<m;a++)
    {
        matrix[a][j] = 0; 
    }
    for(int b=0;b<n;b++)
    {
        matrix[i][b] = 0; 
    }
    

}
void Solution::setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> temp = matrix;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(temp[i][j]==0)
                {
                   setZeroHelp(i,j,m,n,matrix);
                }
            }
        }
}



// Extra linear space
// Time complexity:- O(m*n)
// Space complexity:- O(m+n)

void Solution::setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> isRow(m, 0);
        vector<int> isCol(n, 0);
        
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    isRow[i]=1;
                    isCol[j]=1;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((isRow[i]==1) || (isCol[j]==1))
                {
                    matrix[i][j]=0;
                }
            }
        }

}
