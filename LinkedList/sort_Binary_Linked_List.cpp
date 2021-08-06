//https://www.interviewbit.com/problems/sort-binary-linked-list/

//One pass solution by rearranging nodes
// Time complexity :- O(n)
// Space complexity:- O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::solve(ListNode* A) 
{
    ListNode* oddHead = new ListNode(-1);
    ListNode* evenHead = new ListNode(-2);
    ListNode* oTemp = oddHead;
    ListNode* hTemp = evenHead;
    while(A!=NULL)
    {
        if(A->val==0)
        {
            hTemp->next = A;
            A = A->next;
            hTemp = hTemp->next;
        }
        else
        {
            oTemp->next = A;
            A = A->next;
            oTemp = oTemp->next;
        }
    }
    oTemp->next=NULL;
    hTemp->next= oddHead->next;
    return evenHead->next;
}
