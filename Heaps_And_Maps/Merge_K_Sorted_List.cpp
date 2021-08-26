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


// Using merge sorted lists approach
// Time complexity:- O(nk^2), where k is no of lists, and n is no of nodes in a list
// Space complexity:- O(1)

ListNode* mergeTwoList(ListNode* a, ListNode* b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(a && b)
    {
        if(a->val<b->val)
        {
            temp->next = a;
            a = a->next;
            temp = temp->next;
        }
        else
        {
            temp->next = b;
            b = b->next;
            temp = temp->next;
        }
    }
    while(a)
    {
         temp->next = a;
        a = a->next;
        temp = temp->next;
    }
    while(b)
    {
         temp->next = b;
        b = b->next;
        temp = temp->next;
    }
    return dummy->next;
}


ListNode* Solution::mergeKLists(vector<ListNode*> &lists) 
{
     if(lists.size()==0)
        return NULL;
    ListNode* head=lists[0];
    for(int i=1;i<lists.size();i++)
    {
        head= mergeTwoList(head,lists[i]);
    }
    return head;
}

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
