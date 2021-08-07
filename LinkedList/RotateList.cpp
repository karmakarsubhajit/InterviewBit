// https://www.interviewbit.com/problems/rotate-list/


// Time complexity:- O(n)
// Space complexity:- O(1)


ListNode* Solution::rotateRight(ListNode* A, int B) 
{
    int n = 0;
    ListNode* temp = A;
    if(!A || !A->next)
        return A; 
    ListNode* lastNode = NULL;    
    while(temp)
    {
        n++;
        lastNode = temp;
        temp = temp->next;
    }
    
    B = B%n;
    if(B==0)
        return A;
    int t = n-B;
    temp = A;
    int i=1;
    while(i<t)
    {
        i++;
        temp = temp->next;
    }
    ListNode* tempHead = temp->next;
    lastNode->next = A;
    temp->next = NULL;
    return tempHead;
}