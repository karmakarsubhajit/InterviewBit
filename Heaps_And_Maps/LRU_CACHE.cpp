//https://www.interviewbit.com/problems/lru-cache/
/*
Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example :
Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 
*/

// O(1) access time for both get and put operations
// Implemented after lots of trying, hope it will help the reader :)

#include <bits/stdc++.h>
using namespace std;

unordered_map<int,list <pair<int,int>>::iterator> mp;
list<pair<int,int>> ls;
size_t sz;

LRUCache::LRUCache(int capacity) 
{
    ls.clear();
    mp.clear();
    sz = capacity;
}

int LRUCache::get(int key) 
{
    if(mp.find(key)==mp.end())
        return -1;
    auto itr = mp[key];
    int tmp = itr->second;
    ls.erase(itr);
    ls.push_front(make_pair(key,tmp));
    mp[key] = ls.begin();
    return tmp;
}

void LRUCache::set(int key, int value) 
{
    if(mp.find(key)==mp.end())
    {
        if(ls.size()==sz)
        {
            auto itr = ls.back();
            ls.pop_back();
            mp.erase(itr.first);
        }       
    }
    else
        ls.erase(mp[key]);
    ls.push_front(make_pair(key,value));
    mp[key]=ls.begin();
}


