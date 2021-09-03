// https://www.interviewbit.com/problems/letter-phone/
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

The digit 0 maps to 0 itself.

The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

*/

// Recursive soln
// Time complexity:- (n*3^n)
// Space complexity:- O(n), stack space
void getAns( string temp, vector<string>& ans, int i, string A, int l, map<char,vector<char>> mp)
{
   if(temp.length()==l)
   {
       ans.push_back(temp);
       return;
   }
   if(i==l)
     return;
   for(auto ch:mp[A[i]])
   {
       temp.push_back(ch);
       getAns(temp,ans,i+1,A,l,mp);
       temp.pop_back();
   }

}

vector<string> Solution::letterCombinations(string A) 
{
        if(A.length()==0)
          return {};
        map<char,vector<char>> mp;
        mp['0']={'0'};
        mp['1']={'1'};
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        vector<string> ans;
        string temp="";
        getAns(temp, ans, 0, A,A.size(),mp);
        return ans;
}



// Iterative soln
// Time complexity:- (n*3^n)
// Space complexity:- O(1)


vector<string> Solution::letterCombinations(string A) 
{
        if(A.length()==0)
          return {};
        map<char,vector<char>> mp;
        mp['0']={'0'};
        mp['1']={'1'};
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        vector<string> ans;
        ans.push_back("");
        for(auto i:A)
        {
            vector<string> temp;
            for(auto ch:mp[i])
            {
                for(auto item:ans)
                {
                    temp.push_back(item+ch);
                }
            }
            ans.swap(temp);
        }
       
        return ans;
}

