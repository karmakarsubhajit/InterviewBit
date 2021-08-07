// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

// Time complexity:- O(n)
// Space Complexity:- O(1)


ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    if(!A || !A->next)
        return A;
    ListNode* f = A;
    while(A)
    {
        int v = A->val;
        ListNode* t=A->next;
        while(t && (t->val==v))
        {
            ListNode* temp = t;
            t=t->next;
            delete temp;
            
        }
        A->next = t;
        A=t;
    }
    return f;
}