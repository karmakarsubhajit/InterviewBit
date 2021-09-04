//https://www.interviewbit.com/courses/programming/topics/hashing/
/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

Note:

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

// Time complexity:- O(n*n) // n is length of sudoku board
// Space complexity:- O(n*n)

int Solution::isValidSudoku(const vector<string> &A) 
{
    int n = A.size();
    vector<vector<int>> row(n, vector<int>(n,0));
    vector<vector<int>> col(n, vector<int>(n,0));
    vector<vector<int>> block(n, vector<int>(n,0));
    int sq = sqrt(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]=='.')
              continue;
            int ch = A[i][j]-'1';
            int X = i/sq;
            int Y = j/sq;
            if((row[i][ch]==0) && (col[j][ch]==0) && (block[X*sq+Y][ch]==0))
            {
                row[i][ch]=1;
                col[j][ch]=1;
                block[X*sq+Y][ch] =1;
            }
            else
            {
                return 0;
            }
        }
    } 
    return 1;
}
