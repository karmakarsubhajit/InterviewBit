//https://www.interviewbit.com/problems/reverse-alternate-k-nodes/
/*
Problem Description

Given a linked list A of length N and an integer B.

You need to reverse every alternate B nodes in the linked list A.



Problem Constraints
1 <= N <= 105
1<= Value in Each Link List Node <= 103
1 <= B <= N
N is divisible by B


Input Format
First argument is the head pointer of the linkedlist A.

Second argument is an integer B.



Output Format
Return the head pointer of the final linkedlist as described.



Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3



Example Output
Output 1:

 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15



Example Explanation
Explanation 1:

 The linked list contains 9 nodes and we need to reverse alternate 3 nodes.
 First sublist of length 3  is 3 -> 4 -> 7 so on reversing it we get 7 -> 4 -> 3.
 Second sublist of length 3 is 5 -> 6 -> 6 we don't need to reverse it.
 Third sublist of length 3 is 15 -> 61 -> 16 so on reversing it we get 16 -> 61 -> 15.

*/


// Time complexity:- O(n)
// Space complexity:- O(1)




ListNode* getReverse(ListNode* A, int B)
{
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = A;
    
    while(curr && B>=1)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        B--;
    }
    A->next = curr;
    return prev;
}


ListNode* Solution::solve(ListNode* A, int B) 
{
    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    ListNode* curr = A;
    int c = 1;
    ListNode* prev = dummy;
    while(curr!=NULL)
    {
        if(c==0)
        {
            int i=B;
            while(curr && (i>1))
            {
                curr = curr->next;
                i--;
            }
            prev = curr;
            curr = curr->next;
            c=1-c;
        }
        else
        {
            ListNode* newPrev = curr;
            ListNode* newHead = getReverse(curr,B);
            prev->next=newHead;
            prev = newPrev;
            curr = curr->next;
            c=1-c;
        }
    }
    return dummy->next;
}

// Recursive solution

// Time complexity:- O(n)
// Space complexity:- O(n/k)



ListNode* Solution::solve(ListNode* A, int B) 
{
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = A;
    int i=0;
    while(curr && i<B)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    A->next = next;
    if(next)
    {
        i=1;
        while(next && i<B)
        {
            next=next->next;
            i++;
        }
        if(next && next->next)
        {
            next->next = solve(next->next,B);
        }
    }
    return prev;
}
