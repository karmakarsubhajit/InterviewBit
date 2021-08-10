// https://www.interviewbit.com/problems/balanced-parantheses/

/*
Problem Description

Given a string A consisting only of '(' and ')'.
You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.

Problem Constraints
1 <= |A| <= 105

Input Format
First argument is an string A.

Output Format
Return 1 if parantheses in string are balanced else return 0.

Example Input
Input 1:
 A = "(()())"

Input 2:
 A = "(()"

Example Output
Output 1:
 1

Output 2:
 0

*/

//Time complexity:- O(n)
//Space complexity:- O(n)

int Solution::solve(string A) 
{
    int l = A.length();
    stack<char> st;
    int i=0;
    while(i<l)
    {
        char ch = A[i++];
        if(ch=='(')
            st.push('(');
        else
        {
            if(st.empty()==1)
                return 0;
            else if(st.top()=='(')
                st.pop();
        }    
    }
    return(st.empty()==1);
}
