// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.

*/

// Time complexity:- O(n)
// Space complexity:- O(1)


ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    ListNode* dummy = new ListNode(-100005);
    dummy->next = A;
    ListNode* curr = A;
    ListNode* prev = dummy;
    while(curr)
    {
        int v = curr->val;
        if(curr->next && (curr->next->val ==v))
        {
            while(curr->next && (curr->next->val==v))
            {
                curr = curr->next;
            }
            prev->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
}
