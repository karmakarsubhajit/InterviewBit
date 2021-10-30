//https://www.interviewbit.com/problems/find-duplicate-in-array/

/*
Problem Description

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/

// Hashing soln
// Time complexity:- O(n)
// Space complexity:- O(n)

int Solution::repeatedNumber(const vector<int> &A) 
{
    unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]++;
        if(mp[A[i]]>=2)
            return A[i];
    }
    return -1;
}

// Modifying the array
// Time complexity:- O(n)
// Space complexity:- O(1)


int Solution::repeatedNumber(vector<int> A) 
{
    for(int i=0;i<A.size();i++)
    {
        int idx = abs(A[i])-1;
        if(A[idx]<0)
            return idx+1;
        A[idx] = -1*A[idx];
    }
    return -1;
}

// Without modifying the array
// Time complexity:- O(n)
// Space complexity:- O(1)



vector<int> Solution::repeatedNumber(const vector<int> &A) 
{   
    long long int sm = 0;
    long long int sm_sq = 0;

    long long int p =1;

    for(int i=0;i<A.size();i++)
    {
        p=A[i];
        sm+=p;
        sm-=(i+1);
        sm_sq +=p*p;
        sm_sq-=((long long int)(i+1)*(long long int)(i+1));
    }

    sm_sq=sm_sq/sm;

    
    int a = (int)(sm+sm_sq)/2; 
    int b = sm_sq-a;
        
    vector<int> ans;
    ans.push_back((int)a);
    ans.push_back((int)b);
    return ans;
}
