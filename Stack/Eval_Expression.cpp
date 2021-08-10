// https://www.interviewbit.com/problems/evaluate-expression/

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.


Input Format

The only argument given is character array A.
Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.
For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
*/

// Time complexity:- O(n)
// Space complexity:- O(n)

int calc (int a, int b, string sign)
{
    if(sign =="+")
        return a+b;
    else if(sign=="-")
        return a-b;
    else if(sign=="/")
        return a/b;
    else
        return a*b;
}


int Solution::evalRPN(vector<string> &A) 
{
    int l = A.size();
    stack<string> st;
    int i = 0;
    while(i<l)
    {
        string s = A[i++];
        if(s=="+" || s=="-" || s=="/" || s=="*")
        {
            int b = stoi(st.top());
            st.pop();
            int a = stoi(st.top());
            st.pop();
            int ans = calc(a,b,s);
            string p = to_string(ans);
            st.push(p);
        }
        else
        {
            st.push(s);
        }
    }
    return stoi(st.top());
}
