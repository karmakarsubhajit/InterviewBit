// https://www.interviewbit.com/problems/reorder-list/

// Time complexity:- O(n)
// Space Complexity:- O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* mid(ListNode* A)
{
    if(!A || !A->next)
        return A;
    ListNode* temp1 = A;
    ListNode* temp2 = A;
    while(temp1 && temp2 && temp2->next)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    return temp1;
}

ListNode* reverse(ListNode* A)
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

ListNode* mergeList(ListNode* h1, ListNode* h2)
{
     ListNode* dummyNode = new ListNode(-1);
     ListNode* temp = dummyNode;
     int c=0;
     while(h1 && h2)
     {
         if(c==0)
         {
             temp->next = h1;
             temp=temp->next;
             h1 = h1->next;
         }
         else 
         {
              temp->next = h2;
             temp=temp->next;
             h2 = h2->next;
         }
         c=1-c;
     }
     if(h2)
     {
         temp->next = h2;
        temp=temp->next;
     }
     temp->next=NULL;
     return dummyNode->next;
}

ListNode* Solution::reorderList(ListNode* A) 
{
    if(!A || !A->next || !A->next->next)
        return A;

    ListNode* md = mid(A);
    ListNode* leftH =A;
    ListNode* rightH = reverse(md);
    ListNode* mergelist = mergeList(leftH,rightH);
    return mergelist;

}
