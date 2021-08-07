//https://www.interviewbit.com/problems/reverse-link-list-ii/

// Two pass solution
// Time complexity:- O(n)
// Space complexity:- O(1)


ListNode* reverse(ListNode* h, int t)
{
    if(!h || !h->next)
    {
        return h;
    }
    ListNode* curr = h;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    while(curr!=NULL && t!=0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        t--;
    }
    return prev;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    if(!A || !A->next || (B==C))
        return A;
    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    ListNode* temp = dummy;
    int i = 1;
    while(i<B)
    {
        temp = temp->next;
        i++;
    }
    ListNode* a = temp;
    ListNode* b = temp->next;
    
    temp= temp->next;
    while(i<C)
    {
        temp = temp->next;
        i++;
    }
    ListNode* c = temp;
    ListNode* d = temp->next;
    ListNode* rev = reverse(b, C-B+1);
    a->next = rev;
    b->next = d;
    return dummy->next;
}


/********************/

// One pass solution
// Time complexity:- O(n)
// Space complexity:- O(1)


ListNode* reverse(ListNode* h, int t)
{
    if(!h || !h->next)
    {
        return h;
    }
    ListNode* curr = h;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    while(curr!=NULL && t!=0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        t--;
    }
    h->next = next;
    return prev;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    if(!A || !A->next || (B==C))
        return A;
    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    ListNode* temp = dummy;
    int i = 1;
    while(i<B)
    {
        temp = temp->next;
        i++;
    }
    ListNode* a = temp;
    ListNode* b = temp->next;
    
    
    ListNode* rev = reverse(b, C-B+1);
    a->next = rev;
    
    return dummy->next;
}
