// https://www.interviewbit.com/problems/generate-all-parentheses/


/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/
// Time complexity:- O(n)
// Space complexity:-  O(n)

int Solution::isValid(string A) 
{
    stack<char> st;
    map<char,char> mp;
    mp[')'] = '(';
    mp['}'] = '{';
    mp[']'] = '[';
    int l = A.size();
    int i  = 0;
    while(i<l)
    {
        char ch = A[i++];
        if(ch=='(' || ch=='[' || ch=='{')
            st.push(ch);
        else
        {
            if(st.empty()==1)
                return 0;
            else
            {
                if(st.top()!=mp[ch])
                    return 0;
                else
                {
                    st.pop();
                }
            }
        }
    }
    return (st.empty()==1);
}
