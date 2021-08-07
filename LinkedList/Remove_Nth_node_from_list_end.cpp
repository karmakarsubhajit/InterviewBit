//https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

// Time complexity:- O(n)
// Space Complexity:- O(1)



ListNode* Solution::removeNthFromEnd(ListNode* A, int B) 
{
    if(!A)
        return A;
    ListNode* temp = A;
    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    int i = 1;
    while(temp && (i<B))
    {
        temp = temp->next;
        i++;
    }
    if(temp==NULL)
        return A->next;
    ListNode* s = A;
    ListNode* s_prev = dummy;
    while(temp->next)
    {
        temp = temp->next;
        s = s->next;
        s_prev = s_prev->next;
    }    
    s_prev->next = s->next;
    delete s;
    return dummy->next;
}
