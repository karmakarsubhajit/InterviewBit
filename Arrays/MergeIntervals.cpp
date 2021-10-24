// https://www.interviewbit.com/courses/programming/topics/arrays/

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
*/


// Time Complexity :- O(n) , n is no of intervals
// Space Complexity :- O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n = intervals.size();
        vector<vector<int>> ans ;
        if(n==0)
        {
             ans.push_back(newInterval);
             return ans;
        }
        int flag=0;
        int i = 0;
        int start =-1;
        int end = -1;
        int a = newInterval[0];
            int b = newInterval[1];
        while(i<n)
        {
            
            if(flag==0)
            {
                if(((a>=intervals[i][0]) && (a<=intervals[i][1]))||(a<intervals[i][0]))
                {
                     start = min(a,intervals[i][0]);
                     flag=1;
                }
                else
                {
                    ans.push_back(intervals[i]);
                    i++;
                }
            }
            else if(flag==1)
            {
                if(b<intervals[i][0])
                {
                    end=b;
                    flag=2;
                    vector<int> temp {start,end};
                    ans.push_back(temp);
                }
                else if(((b>=intervals[i][0]) && (b<=intervals[i][1])))
                {
                    end = intervals[i][1];
                    flag=2;
                    i++;
                    vector<int> temp {start,end};
                    ans.push_back(temp);
                }
                else
                    i++;
            }
            else if(flag==2)
            {
                ans.push_back(intervals[i]);
                i++;
            }
        }
        if(start==-1 && end==-1)
        {
            vector<int> temp {a,b};
            ans.push_back(temp);
        }
        else if(start!=-1 && end==-1)
        {
             vector<int> temp {start,b};
            ans.push_back(temp);
        }
        return ans;
    }
};


// Optimal soln
// Time Complexity :- O(n) , n is no of intervals
// Space Complexity :- O(n)


vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
   int n = intervals.size();
        vector<Interval> ans ;
        if(n==0)
        {
             ans.push_back(newInterval);
             return ans;
        }
        int i = 0;
        int a = newInterval.start;
        int b = newInterval.end;
        while((i<n) && (intervals[i].end<newInterval.start))
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while((i<n) && (intervals[i].start<=newInterval.end))
        {
            a=min(intervals[i].start,a);
            b=max(intervals[i].end,b);
            i++;
        }
        Interval temp;
        temp.start =a;
        temp.end = b;
        ans.push_back(temp);
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
}

