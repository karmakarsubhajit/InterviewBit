// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

// Sum of Fibonacci Numbers
// Brute Force

void compute(int i, vector<int>& v, int A, int count, int& mn)
{
    if(A<0)
        return;
    if(A==0)
    {
        mn=min(mn, count);
        return;
    }
    for(int k=i;k<v.size();k++)
    {
        int p = A-v[k];
        compute(k, v, p, count+1,mn);
    }
}
 
int Solution::fibsum(int A) 
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    if(A==1)
        return 1;
    if(A==2)
        return 1;
    int i=2;
    while(1)
    {
        int a = v[i-2];
        int b = v[i-1];
        int nextTerm = a+b;
        if(nextTerm>A)
            break;
        v.push_back(nextTerm);
        i++;
    }
    //return v[i-1];
    int mn = INT_MAX;
    compute(0, v, A, 0,mn);
    return mn;
}

//Optimised Approach Iterative
// Space Complexity:- O(m) --no of fibonacci numbers less than A 
// Time Complexity:- O(m) -- no of fibonacci numbers less than A


int Solution::fibsum(int A) 
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    if(A==1)
        return 1;
    if(A==2)
        return 1;
    int i=2;
    while(A>0)
    {
        int a = v[i-2];
        int b = v[i-1];
        int nextTerm = a+b;
        if(nextTerm>A)
            break;
        v.push_back(nextTerm);
        i++;
    }

    int ans=0;
    i = v.size()-1;
    while(A>0)
    {
        ans+=(A/v[i]);
        A=A%v[i];
        i--;
    }
    return ans;
}
