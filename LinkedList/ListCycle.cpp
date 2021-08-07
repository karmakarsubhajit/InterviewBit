// https://www.interviewbit.com/problems/list-cycle/

//Time Complexity:- O(n)
//Space Complexity:- O(1)


ListNode* Solution::detectCycle(ListNode* A) {
   
    if(!A || !A->next)
        return NULL;
    
    if(A==A->next)
        return A;
    
    ListNode* slow =A;
    ListNode* fast =A;
    
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    if(!slow || !fast || !fast->next) 
        return NULL;
    ListNode* t = A;
    
    while(t!=slow)
    {
        t=t->next;
        slow=slow->next;
    }
    
    return t;
}
