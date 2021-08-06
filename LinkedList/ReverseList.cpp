//https://www.interviewbit.com/problems/reverse-linked-list/

// Time complexity:- O(n)
// Space complexity:- O(1)



ListNode* Solution::reverseList(ListNode* A) 
{
     if(!A || !A->next)
        return A;
    ListNode* prev =NULL;
    ListNode* next=NULL;
    ListNode* curr = A;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next= prev;
        prev= curr;
        curr = next;
    }
    return prev;
}