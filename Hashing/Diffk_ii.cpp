//https://www.interviewbit.com/problems/diffk-ii/
/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :
A : [1 5 3]
k : 2

Output :
1
as 3 - 1 = 2

Return 0 / 1 for this problem.
*/



//Brute force soln
// Time complexity:- O(n^2)
// Space complexity:- O(1)



int Solution::diffPossible(const vector<int> &A, int B) 
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            if(abs(A[i]-A[j])==B)
                return 1;
        }
    }
    
    return 0;
}


// Using Hash Map
// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::diffPossible(const vector<int> &A, int B) 
{
    unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]++;
    }
    for(auto i:mp)
    {
        int a = i.first;
        if(B==0)
        {
            if(i.second>=2)
                return 1;
        }   
        else
        {
            if((mp.find(a-B)!=mp.end()) || (mp.find(a+B)!=mp.end()))
                return 1;
        }
    }
    return 0;
}
