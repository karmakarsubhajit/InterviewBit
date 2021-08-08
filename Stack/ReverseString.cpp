// https://www.interviewbit.com/problems/reverse-string/


/*
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"

*/

//Time complexity:- O(n)
//Space complexity:- O(n)

string Solution::reverseString(string A) 
{
    stack<char> st;
    for(auto i:A)
        st.push(i);
    string ans="";
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
        
}
