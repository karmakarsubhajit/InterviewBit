// Palindrome Partioning
/*
Given a string s, partition s such that every string of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",

Return
  [
    ["a","a","b"]
    ["aa","b"],
  ]
Ordering the results in the answer :

Entry i will come before Entry j if :

len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,

   ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
*/



// Time complexity:- (n*2^n)
// Space complexity:- O(n)

bool isPalin(int l, int r, string A)
{
    while(l<=r)
    {
        if(A[l]==A[r])
        {
            l++;
            r--;
        }
        else
            return false;
    }
    return true;
}

void getAns(int i, int l, string A, vector<string>& temp, vector<vector<string>>& ans)
{
    if(i==l)
    {
        ans.push_back(temp);
        return;
    }
    for(int ind=i;ind<l;ind++)
    {
        if(isPalin(i,ind,A)==false)
            continue;
        else
        {
            temp.push_back(A.substr(i,ind-i+1));
            getAns(ind+1,l,A,temp,ans);
            temp.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> temp;

    int l = A.length();
    int i = 0;
    string p = "";
    getAns(i,l,A,temp,ans);
    return ans;
}
