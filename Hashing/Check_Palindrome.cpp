//https://www.interviewbit.com/problems/check-palindrome/
/*
Problem Description

Given a string A consisting of lowercase characters.
Check if characters of the given string can be rearranged to form a palindrome.
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.


Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.

Input Format
First argument is an string A.

Output Format
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.

Example Input
Input 1:
 A = "abcde"
 
Input 2:
 A = "abbaee"

Example Output
Output 1:
 0
 
Output 2:
 1

Example Explanation
Explanation 1:
 No possible rearrangement to make the string palindrome.
 
Explanation 2:
 Given string "abbaee" can be rearranged to "aebbea" to form a palindrome.
*/

// Time complexity:- O(n)
// Space complexity:- O(1)

int Solution::solve(string A) 
{
    vector<int> v(26,0);
    for(int i=0;i<A.size();i++)
    {
        v[A[i]-'a']++;
    }
    int odd = 0;
    for(int i=0;i<26;i++)
    {
        if((v[i]%2)==1)
        {
            odd++;
            if(odd>=2)
                return 0;
        }
    }
    return 1;
}
