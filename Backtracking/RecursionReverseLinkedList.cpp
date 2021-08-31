// https://www.interviewbit.com/problems/reverse-link-list-recursion/
/*
Reverse a linked list using recursion.

Example :

Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

*/

// Time complexity:- O(n)
// Space complexity:- O(n)

ListNode* reverseL(ListNode* A)
{
    if(A==NULL || A->next==NULL)
        return A;
    ListNode* curr = A;
    ListNode* nextNode = A->next;
    ListNode* head = reverseL(A->next);
    nextNode->next = curr;
    curr->next=NULL;
    return head;
    
}
ListNode* Solution::reverseList(ListNode* A) 
{
    if(A==NULL || A->next==NULL)
        return A;
    return reverseL(A);
}
