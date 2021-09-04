// https://www.interviewbit.com/problems/maximal-string/

/*
Problem Description
Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost B swaps.

Problem Constraints
1 <= |A| <= 9
A contains only digits from 0 to 9.
1 <= B <= 5

Input Format
First argument is string A.
Second argument is integer B.

Output Format
Return a string, the naswer to the problem.

Example Input
Input 1:
A = "254"
B = 1

Input 2:
A = "254'
B = 2

Example Output
Output 1:
 524
 
Output 2:
 542


Example Explanation
Explanation 1:

 Swap 2 and 5.
Explanation 2:
Swap 2 and 5 then swap 4 and 2.
*/



// Time complexity:- O(n!)
// Space complexity:- O(B), stack space

void swap(string& A, int i , int j)
{
    char temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void getAns(string& ans, string& A, int i, int l, int B)
{
    if((i==(l-1)) ||(B==0))
    {
        if(stoi(A)>stoi(ans))
        {
            ans = A;
        }
        return;
    }
    getAns(ans,A,i+1,l,B);
    for(int p=i+1;p<l;p++)
    {
        swap(A,i,p);
        getAns(ans,A,i+1,l,B-1);
        swap(A,i,p);
    }
}

string Solution::solve(string A, int B) 
{
    string ans=A;
    int i = 0;
    int l = A.length();
    getAns(ans,A,i,l,B);
    return ans;
}
