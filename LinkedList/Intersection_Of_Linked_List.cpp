// https://www.interviewbit.com/problems/intersection-of-linked-lists/

/*

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

//Time complexity:- O(m+n)
//Space complexity:- O(1)




ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
       if(!A || !B)
        return NULL;
    int l1 = 0;
    int l2 = 0;
    ListNode* t1 = A;
    ListNode* t2 = B;
    while(t1)
    {
        t1 = t1->next;
        l1++;
    }
    while(t2)
    {
        t2 = t2->next;
        l2++;
    }
    int d = abs(l1-l2);
    if(l1<l2)
    {
        t1 = A;
        t2 = B;
    }
    else
    {
        t1 = B;
        t2 = A;
    }
    while(d--)
    {
        t2=t2->next;
    }
    while(t1 && t2 && (t1!=t2))
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    if(!t1 || !t2)
        return NULL;
    return t1;

}
