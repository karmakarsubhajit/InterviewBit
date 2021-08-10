//https://www.interviewbit.com/problems/redundant-braces/


/*
Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.

Input Format

The only argument given is string A.
Output Format

Return 1 if string has redundant braces, else return 0.
For Example

Input 1:
    A = "((a + b))"
Output 1:
    1
    Explanation 1:
        ((a + b)) has redundant braces so answer will be 1.
*/

//Time complexity:- O(n)
//Space complexity:- O(n)

int Solution::braces(string A) 
{
    int l = A.size();
    int i = 0;
    stack<char> st;
    while(i<l)
    {
        char ch = A[i++];
        if(ch==')')
        {
            bool f = false;
            while((st.empty()==0) && (st.top()!='('))
            {
                char temp = st.top();
                st.pop();
                if(temp=='+' || temp=='-' || temp=='*' || temp=='/')
                    f = true;
            }
            st.pop();
            if(f==false)
                return true;
        }
        else
        {
            st.push(ch);
        }

    }
    return false;
}
