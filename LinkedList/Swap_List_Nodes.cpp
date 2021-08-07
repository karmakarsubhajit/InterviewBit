// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

// Time complexity:- O(n)
// Space complexity:- O(1)

ListNode* Solution::swapPairs(ListNode* A) 
{
    if(!A || !A->next)
    {
        return A;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    ListNode* prev=dummy;
    ListNode* temp = A;
    while(temp)
    {
        if(temp->next==NULL)
        {
            prev->next = temp;
            break;
        }
            
        else
        {
            ListNode* nextNode = temp->next;
            ListNode* nextTemp = nextNode->next;
            prev->next = nextNode;
            nextNode->next = temp;
            temp->next=NULL;
            prev=temp;
            temp = nextTemp;
        }
    }
    return dummy->next;
}


/********************/

//Alternate solution


// Time complexity:- O(n)
// Space complexity:- O(1)

ListNode* swapNodes(ListNode* a, ListNode* b)
{
    a->next = b->next;
    b->next = a;
    return b;
}
ListNode* Solution::swapPairs(ListNode* A) 
{
    if(!A || !A->next)
    {
        return A;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    ListNode* curr=dummy;
    while(curr->next && curr->next->next)   
    {
        curr->next = swapNodes(curr->next, curr->next->next);
        curr = curr->next->next;
    }
    return dummy->next;    
}