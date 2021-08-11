// https://www.interviewbit.com/problems/simplify-directory-path/

/*
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.




Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"

*/
//Time complexity:- O(n)
//Space complexity:- O(n)

string Solution::simplifyPath(string A) 
{
    int l = A.length();
    if(l==1)
        return A;
    if(A[l-1]!='/')
        A+='/';
    int i = 1;
    string temp ="";
    stack<string> st;
    l = A.length();
    
    while(i<l)
    {
        if(A[i]=='/')
        {
            if(temp.length()==0)
            {
                i++;
                continue;
            }
            else
            {
                if(temp==".")
                {
                    i++;
                    temp="";
                    continue;
                }
                else if(temp=="..")
                {
                    i++;
                    temp="";
                    if(st.empty()!=1)
                        st.pop();
                    continue;
                }
                else
                {
                    i++;
                    st.push(temp);
                    temp = "";
                    continue;
                }
            }
        }
        else
        {
            temp+=A[i];
            i++;
        }
    }
    stack<string> st1;
    while(!st.empty())
    {
        st1.push(st.top());
        st.pop();
    }
    string ans = "";
    while(!st1.empty())
    {
        ans+="/";
        ans+=st1.top();
        st1.pop();
    }
    if(ans=="")
        ans+="/";
    return ans;
}
