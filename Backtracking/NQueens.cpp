// https://www.interviewbit.com/problems/nqueens/

/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,

There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

// Time complexity:- O(n^n)
// Space complexity:- O(n)

bool isValid( vector<int>& cols)
{
    int rId =cols.size()-1;
    for(int i=0;i<rId;i++)
    {
        int diff = abs(cols[rId]-cols[i]);
        if((diff==0) || (diff==(rId-i)))
            return false;
    }   
    return true;
}
void getAns(vector<vector<string>>& ans, int i, int A, vector<string>& temp, vector<int>& cols)
{
    if(i==A)
    {
        ans.push_back(temp);
        return;
    }
    for(int c=0;c<A;c++)
    {
        
        temp[i][c] = 'Q';
        cols.push_back(c);
        if(isValid(cols)==true)
        {
            getAns(ans, i+1,A,temp,cols);
        }
        cols.pop_back();
        temp[i][c]= '.';
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    string st="";
    vector<string> temp;
    vector<vector<string>> ans;
    
    for(int i=1;i<=A;i++)
    {
        st+=".";
    }
    for(int i=1;i<=A;i++)
    {
        temp.push_back(st);
    }
    vector<int> cols;
    getAns(ans, 0, A, temp, cols);
    return ans;
}

