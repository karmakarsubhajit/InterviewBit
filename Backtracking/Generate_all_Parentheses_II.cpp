// https://www.interviewbit.com/problems/generate-all-parentheses-ii/

// Recursice backtracking
// Time complexity:- O(n*2^(2n))
// Space complexity:- O(n) , stack space

void getParenthesis(int op, int cl, int n, string temp, vector<string>& ans)
{
    if(cl==n)
    {
        ans.push_back(temp);
        return;
    }
    if((op==0) || (op==cl))
    {
        temp+='(';
        getParenthesis(op+1,cl,n,temp,ans);
    }
    else if(op==n)
    {
        temp+=')';
        getParenthesis(op,cl+1,n,temp,ans);
    }
    else if(op>cl)
    {
        temp+='(';
        getParenthesis(op+1,cl,n,temp,ans);
        temp.pop_back();
        temp+=')';
        getParenthesis(op,cl+1,n,temp,ans);
        temp.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int A) 
{
    vector<string> ans;
    if(A==0)
      return ans;
    string temp ="";
    int op = 0;
    int cl = 0;
    getParenthesis(op,cl,A,temp,ans);
    return ans;
}


