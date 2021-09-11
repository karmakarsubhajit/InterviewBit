//https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/
/*
Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

Return the maximum possible profit.

Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



Input Format:

The first and the only argument is an integer array, A.
Output Format:

Return an integer, representing the maximum possible profit.
Constraints:

1 <= length(A) <= 7e5
1 <= A[i] <= 1e7
Examples:

Input 1:
    A = [1, 2, 1, 2]

Output 1:
    2

Explanation 1: 
    Day 0 : Buy 
    Day 1 : Sell
    Day 2 : Buy
    Day 3 : Sell

Input 2:
    A = [7, 2, 4, 8, 7]

Output 2:
    6

Explanation 2:
    Day 1 : Buy
    Day 3 : Sell
*/

// Three pass soln
// Time complexity :- O(n)
// Space complexity:- O(n)


int Solution::maxProfit(const vector<int> &A) 
{
    int n = A.size();
    if(n<=1)
        return 0;
    vector<int> profitFromTransactionsBefore(n,0);
    vector<int> profitFromTransactionsAfter(n,0);
    int max_Current = 0;
    int max_tillCurrent = 0;
    int mn = A[0];
    for(int i=0;i<n;i++)
    {
        max_Current = max(max_Current, A[i]-mn);
        max_tillCurrent = max(max_Current, max_tillCurrent);
        mn = min(mn,A[i]);
        profitFromTransactionsBefore[i] = max_tillCurrent;
    }
    int max_Current1 = 0;
    int max_tillCurrent1=0;
    int mx = A[n-1];
   for(int j=n-1;j>=0;j--)
    {
        max_Current1 = max(max_Current1, mx-A[j]);
        max_tillCurrent1 = max(max_Current1, max_tillCurrent1);
        mx = max(mx, A[j]);
        profitFromTransactionsAfter[j] = max_tillCurrent1;
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {


// Optimal soln || Two pass
// Time complexity :- O(n)
// Space complexity:- O(n)

int Solution::maxProfit(const vector<int> &A) 
{
    int n = A.size();
    if(n<=1)
        return 0;
    vector<int> profitFromTransactionsBefore(n,0);
    vector<int> profitFromTransactionsAfter(n,0);
    int max_Current = 0;
    int max_tillCurrent = 0;
    int mn = A[0];
    int max_Current1 = 0;
    int max_tillCurrent1=0;
    int mx = A[n-1];
    int j;
    for(int i=0;i<n;i++)
    {
        j=n-1-i;
        max_Current = max(max_Current, A[i]-mn);
        max_tillCurrent = max(max_Current, max_tillCurrent);
        mn = min(mn,A[i]);
        profitFromTransactionsBefore[i] = max_tillCurrent;
         max_Current1 = max(max_Current1, mx-A[j]);
        max_tillCurrent1 = max(max_Current1, max_tillCurrent1);
        mx = max(mx, A[j]);
        profitFromTransactionsAfter[j] = max_tillCurrent1;
    }
 
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans = max(ans,profitFromTransactionsAfter[i]+profitFromTransactionsBefore[i]);
    }
    return ans;
}
