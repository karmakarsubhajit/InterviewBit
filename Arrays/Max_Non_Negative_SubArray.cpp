
//https://www.interviewbit.com/problems/max-non-negative-subarray/

//Time complexity:- O(nlogn)
//Space complexity:- O(n)

bool compare(vector<long long int>& A, vector<long long int>& B)
{
    if(A[0]>B[0])
        return true;
    else if (A[0]==B[0])
    {
        if(A[1]>B[1])
            return true;
        else if(A[1]==B[1])
        {
            if(A[2]<A[2])
                return true;
            else
                return false;
        }
        else
           return false;
    }
    else
        return false;
}

vector<int> maxset(vector<int> &A)
{
    int l = A.size();
    vector<vector<long long int>> v;
    long long int curr_len=0;
    long long int curr_sum=0;
    long long int i = 0;
    while(i<l)
    {
        if(A[i]<0)
        {
            if(curr_len==0)
            {
                i++;
                continue;
            }
            else
            {
                vector<long long int> temp;

                temp.push_back(curr_sum);
                temp.push_back(curr_len);
                temp.push_back(i-curr_len);
                v.push_back(temp);
                curr_sum=0;
                curr_len=0;
                i++;
            }
        }
        else
        {
            curr_len++;
            curr_sum+=A[i];
            i++;
            if(i==l)
            {
                vector<long long int> temp;
                temp.push_back(curr_sum);
                temp.push_back(curr_len);
                temp.push_back(i-curr_len);
                v.push_back(temp);
            }
        }
    }
    vector<int> ans;
   
   
    if(v.size()==0)
        return ans;
    sort(v.begin(), v.end(), compare);
    for(long long int j=v[0][2];j<(v[0][2]+v[0][1]);j++)
        ans.push_back(A[j]);
    return ans;
}



//Optimal solution

//Time Complexity :- O(n)
//Space complexity:- O(1)

vector<int> Solution::maxset(vector<int> &A) 
{
    int l = A.size();
   
    long long int curr_sum=0;
    long long int start = 0;
    long long int end = 0; 
    long long int maxSum = -1;
    long long int maxLen = INT_MIN;
    long long int ansStart=-1;
    long long int ansEnd =-1;

    long long int i = 0;
    while(i<l)
    {
        if(A[i]>=0)
        {
            start = i;
            curr_sum=0;
            while(A[i]>=0 && i<l)
            {
                curr_sum+=A[i];
                i++;
            }
            end = i-1;
            if((curr_sum>maxSum)|| ((curr_sum==maxSum)&&((end-start+1)>maxLen)))
            {
                ansStart=start;
                ansEnd=end;
                maxSum=curr_sum;
                maxLen = end-start+1;
            }
        }
        
        i++;
    }
    vector<int> ans;
    if(ansStart==-1)
        return ans;
    for(int i=ansStart;i<=ansEnd;i++)
        ans.push_back(A[i]);
    return ans;
}

