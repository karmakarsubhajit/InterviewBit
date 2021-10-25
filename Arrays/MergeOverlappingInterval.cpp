// https://www.interviewbit.com/problems/merge-overlapping-intervals/

/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

*/


// Time complexity:- O(nlogn)
// Space complexity:- O(n)

bool compare(Interval& a, Interval& b)
{
    return a.start<b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) 
{
    sort(A.begin(), A.end(),compare);
    vector<Interval> ans;
    int start = -1;
    int end = -1;
    for(auto it:A)
    {
        if(start==-1)
        {
            start = it.start;
            end = it.end;
        }
        else
        {
            if(end<it.start)
            {
                Interval temp;
                temp.start = start;
                temp.end = end;
                ans.push_back(temp);
                start = it.start;
                end = it.end;
            }
            else
            {
                end = max(end, it.end);
            }
        }

    }
    Interval temp;
    temp.start = start;
    temp.end = end;
    ans.push_back(temp);

    return ans;

}



// Optimal Solution
// Time complexity:- O(nlogn)
// Space complexity:- O(n)


bool compare(Interval& a, Interval& b)
{
    return a.start<b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) 
{
    sort(A.begin(), A.end(),compare);
    vector<Interval> ans;
    
    for(auto it:A)
    {
        if(ans.size()==0 || ans.back().end<it.start)
        {
            ans.push_back(it);
        }   
        else
        {
            ans.back().end = max(ans.back().end, it.end);
        }
    }
    return ans;
}
