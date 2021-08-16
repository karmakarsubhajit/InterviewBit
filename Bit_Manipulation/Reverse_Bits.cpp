// https://www.interviewbit.com/problems/reverse-bits/
/*
Problem Description

Reverse the bits of an 32 bit unsigned integer A.

Problem Constraints
0 <= A <= 232

Input Format
First and only argument of input contains an integer A.

Output Format
Return a single unsigned integer denoting the decimal value of reversed bits.

Example Input
Input 1:
 0

Input 2:
 3

Example Output
Output 1:
 0

Output 2:
 3221225472

Example Explanation
Explanation 1:
        00000000000000000000000000000000

=>      00000000000000000000000000000000
Explanation 2:
        00000000000000000000000000000011    
=>      11000000000000000000000000000000
*/

// Time complexity:- O(32) ~ O(1)
// Space complexity:- O(32) ~ O(1)
// Two passes over the 32 bits


unsigned int Solution::reverse(unsigned int A) {
  
    if(A==0)
        return A;
    unsigned int temp = A;
    string tm = "";
    while(temp!=0)
    {
        if((temp&1)==0)
            tm+="0";
        else
            tm+="1";
        temp = temp>>1;
    }
    if(tm.length()==0)
        return 0;
    int l = tm.length();
    int p = 32-l;
    for(int i=1;i<=p;i++)
    {
        tm = tm+"0";
    }
    unsigned int ans = 0;
    unsigned int bt = 1;
    for(int i=31;i>=0;i--)
    {
         if(tm[i]=='1')
            ans+=bt;
        bt=bt<<1;
    }
    return ans;
}

// Time complexity:- O(32) ~ O(1)
// Space complexity:- O(1) ~ O(1)
// One pass over the 32 bits


unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==0)
        return A;
    unsigned ans = 0;
    for(int i=0;i<32;i++)
    {
        ans = (ans<<1)+A%2;
        A=A>>1;
    }
    return ans;
}
