// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

//Time complexity:- O(max(m,n)) where m, n are no of digits in two numbers
//Space complexity:- O(1)


ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    ListNode* dummy = new ListNode(-1);
    int sum = 0;
    int carr = 0;
    ListNode* t = dummy;
    while(A && B)
    {
        int temp = A->val+B->val+carr;
        sum = temp%10;
        carr = temp/10;
        t->next = new ListNode(sum);
        t = t->next;
        A=A->next;
        B=B->next;    
    }
    while(A)
    {
        int temp = A->val+carr;
        sum = temp%10;
        carr = temp/10;
        t->next = new ListNode(sum);
        t = t->next;
        A=A->next;
    }
    
    while(B)
    {
        int temp = B->val+carr;
        sum = temp%10;
        carr = temp/10;
        t->next = new ListNode(sum);
        t = t->next;
        B=B->next;
    }
    if(carr)
    {
        t->next = new ListNode(1);
        t = t->next;
    }
    return dummy->next;
}
