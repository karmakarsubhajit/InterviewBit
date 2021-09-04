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

// Brute Force
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


// Optimised isValid function
// Time complexity:- O(n^n)
// Space complexity:- O(n)



void getAns(vector<vector<string>>& ans, int i, int A, vector<string>& temp, vector<int>& cols, vector<int>& ld, vector<int>& rd)
{
    if(i==A)
    {
        ans.push_back(temp);
        return;
    }
    for(int c=0;c<A;c++)
    {
        if((ld[A-1+i-c]!=1)&&(rd[i+c]!=1)&&(cols[c]!=1))
        {
            temp[i][c] = 'Q';
            ld[A-1+i-c]=1;
            rd[i+c]=1;
            cols[c]=1;
            getAns(ans, i+1,A,temp,cols,ld,rd);
            ld[A-1+i-c]=0;
            rd[i+c]=0;
            cols[c]=0;
            temp[i][c]= '.';
        }
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
    vector<int> cols(100,0);
    vector<int> ld(100,0);
    vector<int> rd(100,0);
    getAns(ans, 0, A, temp, cols,ld,rd);
    return ans;
}
