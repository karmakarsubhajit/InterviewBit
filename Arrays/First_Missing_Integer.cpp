//https://www.interviewbit.com/problems/first-missing-integer/
/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

*/



// Brute Force soln 
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)



int Solution::firstMissingPositive(vector<int> &A) 
{
    
    for(int i=1;i<=A.size();i++)
    {
        bool isPresent = false;
        for(int j=0;j<A.size();j++)
        {
            if(A[j]==i)
            {
                isPresent=true;
                break;
            }
        }    
        if(isPresent==false)
            return i;
    }

    return A.size()+1;
}

// Sorting based soln || 1 pass solution
// Time Complexity:- O(nlogn)
// Space Complexity:- O(1)

int Solution::firstMissingPositive(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int c=1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<=0)
            continue;
        else if(A[i]==c)
        {
            c++;
        }    
        else
            return c;
    }

    return c;
}


// Hashing Solution || 2 pass solution
// Time Complexity:- O(n)
// Space Complexity:- O(n)

int Solution::firstMissingPositive(vector<int> &A) 
{
    vector<bool> isNumberPresent(A.size()+1,false);
    for(auto i:A)
    {
        if(i>0 && i<=A.size())
            isNumberPresent[i]=true;
    }
    for(int i=1;i<=A.size();i++)
    {
        if(isNumberPresent[i]==0)
            return i;
    }
    return A.size()+1;
}

// Constant Space || 3 pass solution
// Time Complexity:- O(n)
// Space Complexity:- O(1)


int Solution::firstMissingPositive(vector<int> &nums) 
{
    bool flag=false;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                flag=true;
            if(nums[i]<=0 || nums[i]>n)
                nums[i]=1;
        }
        if(flag==false)
            return 1;
        for(int i=0;i<n;i++)
        {
            int index = abs(nums[i]);
            nums[index-1]=-1*abs(nums[index-1]);
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
}


// Constant Space | Optimal Soln | 2 pass solution
// Time Complexity:- O(n)
// Space Complexity:- O(1)


int Solution::firstMissingPositive(vector<int> &nums) 
{
    
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            while((nums[i]>0) && (nums[i]<=n) && (nums[i]!=nums[nums[i]-1]))
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=(i+1))
                return i+1;
        }
        return n+1;
}


