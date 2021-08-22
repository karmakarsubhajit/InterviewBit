// https://www.interviewbit.com/problems/excel-column-number/
/*
Problem Description

Given a column title A as appears in an Excel sheet, return its corresponding column number.
Problem Constraints
1 <= |A| <= 100

Input Format
First and only argument is string A.

Output Format
Return an integer

Example Input
Input 1:
 1
 
Input 2:
 28


Example Output
Output 1:
 "A"
 
Output 2:
 "AB"

Example Explanation
Explanation 1:
 1 -> "A"
 
Explanation 2:
A  -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
*/

// Time complexity:- O(n), n is length of string
// Space complexity:- O(1)

string Solution::convertToTitle(int A) 
{
    string ans = "";
    while(A)
    {        
        ans+=((A-1)%26+'A');
        A=(A-1)/26;
       
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
