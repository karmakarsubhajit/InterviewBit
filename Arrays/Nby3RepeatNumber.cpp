// https://www.interviewbit.com/problems/n3-repeat-number/

/*
Problem Description

You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example:

Input: [1 2 3 1 1]
Output: 1 
1 occurs 3 times which is more than 5/3 times.
*/


// Sorting soln
// Time complexity:- O(nlogn)
// Space complexity:- O(1)

int Solution::repeatedNumber(vector<int> A)
 {
    sort(A.begin(),A.end());
    int count = 0;
    for(int i=0;i<A.size();i++)
    {
        count=1;
        int num = A[i];
        if((i+1<A.size()) && (A[i]==A[i+1]))
        {
            while(i+1<A.size() && A[i]==A[i+1])
            {
                i++;
                count++;
            }
        }
        if(count>A.size()/3)
        {
            return num;
        }
    }
    return -1;
}




// Hashing soln
// Time complexity:- O(n)
// Space complexity:- O(n)


int Solution::repeatedNumber( vector<int> A)
 {
    unordered_map<int,int> mp;

    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]++;
        
        if(mp[A[i]]>(A.size()/3))
        {
            return A[i];
        }
    }
    return -1;
}
