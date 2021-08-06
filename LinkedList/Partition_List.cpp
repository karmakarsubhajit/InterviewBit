// https://www.interviewbit.com/problems/partition-list/

// Maintain dummy head pointers and rearrange the list
// Time complexity:- O(n)
// Space complexity:- O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) 
{
    if(!A || !A->next)
        return A;
    ListNode* lessHead = new ListNode(-1);
    ListNode* highHead = new ListNode(-2);
    ListNode* lessTemp = lessHead;
    ListNode* highTemp = highHead;


    while(A!=NULL)
    {
        if(A->val<B)
        {
            lessTemp->next=A;
            A=A->next;
            lessTemp = lessTemp->next;
        }
        else if(A->val>=B)
        {
            highTemp->next = A;
            A=A->next;
            highTemp = highTemp->next;
        }
    }
    highTemp->next = NULL;
    lessTemp->next=highHead->next;
    return lessHead->next;
}
