//https://www.interviewbit.com/problems/merge-k-sorted-lists/
/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/

// Using min heap approach
// Time complexity:- O(nklogk), where k is no of lists, and n is no of nodes in a list
// Space complexity:- O(k)

struct compare {
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
       int n = A.size();
    if(n==0)
        return NULL;
    priority_queue<ListNode*,vector<ListNode*>, compare> pq;
    for(auto it:A)
    {
        pq.push(it);
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* t = dummy;
    while(!pq.empty())
    {
        ListNode* temp = pq.top();
        pq.pop();
        t->next=temp;
        t=t->next;
        if(temp->next)
        {
            pq.push(temp->next);
        }
    }
    return dummy->next;
}
