// https://www.interviewbit.com/problems/sudoku/

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.' 

You may assume that there will be only one unique solution.
A sudoku puzzle,
and its solution numbers marked in red.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

*/

// Optimised sudoku validity check
// Time complexity:- O(n^m), where n is the no of pissibility of numbers to be filled and m is the number of blank spaces in the matrix
// Space complexity:- O(n*n)


void solve(bool& check, vector<vector<char>>& A,int n, int sq, int x, int y, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& block)
{
    if((x==n) && (y==0))
    {
        check = true;
        return;
    }
    if(A[x][y]!='.')
    {
        if(y==(n-1))
            solve(check,A,n,sq,x+1,0,row,col,block);
        else 
            solve(check,A,n,sq,x,y+1,row,col,block);
        if(check==true)
            return;
    }
    else
    {
        if(check==true)
            return;
        for(int i=0;i<9;i++)
        {
            int X = x/sq;
            int Y = y/sq;
            if(check==true)
                return;
        
            if((row[x][i]==0) && (col[y][i]==0) && (block[X*sq +Y][i]==0))
            {
                row[x][i] = 1;
                col[y][i] = 1;
                block[X*sq+Y][i] = 1;
                A[x][y]=i+1+'0';
                
                if(y==(n-1))
                    solve(check,A,n,sq,x+1,0,row,col,block);
                else 
                    solve(check,A,n,sq,x,y+1,row,col,block);
                if(check==true)
                    return;
                row[x][i] = 0;
                col[y][i] = 0;
                block[X*sq+Y][i] = 0;
                A[x][y]='.';
                
            }
        }
    }

}

void Solution::solveSudoku(vector<vector<char> > &A) 
{
    int n = A.size();
    vector<vector<int>> row(n,vector<int>(n,0));
    vector<vector<int>> col(n,vector<int>(n,0));
    vector<vector<int>> block(n,vector<int>(n,0));
    bool chck = false;
    int sq =sqrt(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int X = i/sq;
            int Y = j/sq;
            if(A[i][j]!='.')
            {
                row[i][A[i][j]-'1'] = 1;
                col[j][A[i][j]-'1'] = 1;
                block[X*sq+Y][A[i][j]-'1'] = 1;
            }
        }
    }

    solve(chck, A ,n,sq, 0, 0, row, col, block);
    
}
