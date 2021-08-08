//https://www.interviewbit.com/problems/k-reverse-linked-list/

/*
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
*/

// Time complexity:- O(n)
// Space complexity:- O(n/k)

ListNode* Solution::reverseList(ListNode* A, int B) 
{
    if(!A)
        return A;
    if(B==1)
        return A;
    ListNode* curr = A;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int i = 0;
    while(curr && i<B)
    {
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
        i++;
    }
    A->next = reverseList(next,B);
    return prev;
}



//Recursive constant space solution

// Time complexity:- O(n)
// Space complexity:- O(1)


ListNode* reverse(ListNode* A, int B)
{
    if(!A || !A->next)
        return A;
    ListNode* curr = A;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int i = 0;
     while(curr && i<B)
    {
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
        i++;
    }
    A->next = next;
    return prev;
}

ListNode* Solution::reverseList(ListNode* A, int B) 
{
    if(!A)
        return A;
    if(B==1)
        return A;
    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    ListNode* curr = A;
    ListNode* prev = dummy;
    while(curr!=NULL)
    {
        ListNode* newPrev = curr;
        ListNode* newHead = reverse(curr,B);
        prev->next = newHead;
        prev = newPrev;
        curr = curr->next;
    }
   return dummy->next;
}  