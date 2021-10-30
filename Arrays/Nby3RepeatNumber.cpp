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



// Moore's Voting Algorithm | Optimal soln
// Time complexity:- O(n)
// Space complexity:- O(1)


int Solution::repeatedNumber( vector<int> A)
 {
     
    int count1 =0;
    int count2=0;
    int num1 = INT_MAX;
    int num2 = INT_MAX;

    for(int i=0;i<A.size();i++)
    {
        if(num1==A[i])
        {
            count1++;
        }
        else if(num2==A[i])
        {
            count2++;
        }
        else if(count1==0)
        {
            num1 = A[i];
            count1++;
        }
        else if(count2==0)
        {
            num2 = A[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==num1)
            count1++;
        else if(A[i]==num2)
            count2++;
    }
    if(count1>A.size()/3)
        return num1;
    if(count2>A.size()/3)
        return num2;
    return -1;
    
}
