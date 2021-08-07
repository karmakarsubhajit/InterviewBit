// https://www.interviewbit.com/problems/palindrome-list/

// Time complexity:- O(n)
// Space complexity:- O(1)



ListNode* getMid(ListNode* A)
{
    if(!A || !A->next)
        return A;
    ListNode* slow = A;
    ListNode* slowPrev=NULL;
    ListNode* fast = A;
    while(slow && fast && fast->next)
    {
        slowPrev=slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    slowPrev->next=NULL;
    return slow;
}

ListNode* reverse(ListNode* A)
{
    ListNode* curr = A;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int Solution::lPalin(ListNode* A) 
{
    if(!A || !A->next)
        return 1;
    ListNode* mid = getMid(A);
    ListNode* h2 = reverse(mid);
    ListNode* h1 = A;
    while(h1 && h2)
    {
        if(h1->val!=h2->val)
            return 0;
        h1=h1->next;
        h2=h2->next;
    }
    return 1;
}