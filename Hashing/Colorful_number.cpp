//https://www.interviewbit.com/problems/colorful-number/

/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

*/

// Time complexity:- O(n^2), where n is number of digits in the number A
// Space complexity:- O(9)=O(1)

int Solution::colorful(int A) 
{
    if(A==0)
        return 0;
    map<int,int> mp;
    int temp = A;
    string st = to_string(temp);
    int n = st.length();
    for(int len=1;len<=st.length();len++)
    {
        int mul = 1;
        for(int i=0;i<len;i++)
        {
            if(st[i]=='0')
                return 0;
            mul*=(st[i]-'0');
        }
        mp[mul]++;
        if(mp[mul]>1)
            return 0;
        for(int i=len;i<n;i++)
        {
            if(st[i]=='0')
                return 0;
            mul*=(st[i]-'0');
            mul/=(st[i-len]-'0');
            mp[mul]++;
            if(mp[mul]>1)
                return 0;
        }
    }
    return 1;
}
