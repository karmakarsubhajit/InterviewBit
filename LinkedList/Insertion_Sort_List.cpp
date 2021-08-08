//https://www.interviewbit.com/problems/insertion-sort-list/

/*
Sort a linked list using insertion sort.


Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3
*/ 

// Time complexity:- O(n^2)
// Space complexity:- O(1)

ListNode* Solution::insertionSortList(ListNode* head) 
{
    if(head==NULL || head->next==NULL)
            return head;
        ListNode* dummy = new ListNode(-100005);
        
        while(head!=NULL)
        {
            ListNode* prev = dummy;
            ListNode* nextNode = head->next;
            while(prev->next && prev->next->val<head->val)
                prev=prev->next;
            
            head->next = prev->next;
            prev->next = head;
            head=nextNode;
             
        }
        return dummy->next;
}







