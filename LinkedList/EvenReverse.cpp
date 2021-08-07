//https://www.interviewbit.com/problems/even-reverse/

// Time complexity:- O(n) 
// Space complexity:- O(1)


ListNode* reverse(ListNode* A)
{
    ListNode* curr = A;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while(curr)
    {
        
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* mergeList(ListNode* h1, ListNode* h2)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* t = dummy;
    int c = 1;
    while(h1 && h2)
    {
        if(c==1)
        {
            t->next = h1;
            t = t->next;
            h1 = h1->next;
        }
        else
        {
            t->next = h2;
            t = t->next;
            h2 = h2->next;
        }
        c=1-c;
    }
    if(h1)
    {
        t->next = h1;
        t= t->next;
        h1 = h1->next;
    }
    if(h2)
    {
        t->next = h2;
        t= t->next;
        h2 = h2->next;
    }
    
    return dummy->next;
}

ListNode* Solution::solve(ListNode* A) 
{
    if(!A || !A->next || !A->next->next|| !A->next->next->next)
        return A;
    ListNode* d1 = new ListNode(-1);
    ListNode* d2 = new ListNode(-1);
    ListNode* t1 = d1;
    ListNode* t2 = d2;
    ListNode* temp =A;
    int c = 1;
    while(temp)
    {
        if(c==1)
        {
            t1->next = temp;
            temp = temp->next;
            t1 = t1->next;
        }
        else
        {
            t2->next = temp;
            temp = temp->next;
            t2 = t2->next;
        }
        c = 1-c;
    }
    t1->next =NULL;
    t2->next=NULL;
    ListNode* h2 = reverse(d2->next);
    ListNode* h1 = d1->next;
    ListNode* h = mergeList(h1,h2);
    return h;
}
 