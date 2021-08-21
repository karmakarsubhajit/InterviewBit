//https://www.interviewbit.com/problems/total-moves-for-bishop/
/*
Problem Description

Given the position of a Bishop (A, B) on an 8 * 8 chessboard.
Your task is to count the total number of squares that can be visited by the Bishop in one move.
The position of the Bishop is denoted using row and column number of the chessboard.

Problem Constraints
1 <= A, B <= 8

Input Format
First argument is an integer A denoting the row number of the bishop.
Second argument is an integer B denoting the column number of the bishop.

Output Format
Return an integer denoting the total number of squares that can be visited by the Bishop in one move.

Example Input
Input 1:

 A = 4
 B = 4


Example Output
Output 1:
 13
*/

//Time complexity:- O(1)
//Space complexity:- O(1)

int Solution::solve(int A, int B) 
{
    int mn = min(A, B);
    int mx = max(A, B);
    int ans = 8-mx;
    ans+= mn-1;
    ans+= min(mn-1, 8-mx);
    ans+= min(8-mn, mx-1);
    return ans;
}
