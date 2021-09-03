//https://www.interviewbit.com/problems/gray-code/
/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.

Return any such sequence.
*/


// Time complexity:- O(2^n)
// Space complexity:- O(n), stack space

void getNum(vector<int>& ans, int n, int& num)
{
    if(n==0)
    {
        ans.push_back(num);
        return;
    }
    getNum(ans,n-1,num);
    num = num^(1<<(n-1));
    getNum(ans,n-1,num);

}

vector<int> Solution::grayCode(int A) 
{
    vector<int> ans;
    int num = (1<<A)-1;
    getNum(ans,A,num);
    return ans;
}
