//https://www.interviewbit.com/problems/merge-two-sorted-lists/

// Time complexity:- O(m+n) 
// Space complexity:- O(1)


ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(!A)
        return B;
    if(!B)
        return A;
    ListNode* dummy = new ListNode(-1);
    ListNode* t = dummy;
    while(A && B)
    {
        if(A->val<B->val)
        {
            t->next = A;
            A = A->next;
            t = t->next;
        }
        else
        {
            t->next = B;
            B = B->next;
            t = t->next;
        }
    }
    while(A)
    {
        t->next = A;
        A=A->next;
        t=t->next;
    }
    while(B)
    {
        t->next = B;
        B = B->next;
        t=t->next;
    }
    return dummy->next;
}
