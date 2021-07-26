// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/


// Time Complexity:- O(N)
//Space Complexity:- O(logN)


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* getTree(int l, int r, ListNode** head)
{
    if(l>r)
        return NULL;
    int m = l+(r-l)/2;
    
    
    
    TreeNode* leftChild = getTree(l,m-1,head);
    TreeNode* root = new TreeNode((*head)->val);
    (*head) = (*head)->next;
    TreeNode* rightChild = getTree(m+1,r,head);

    root->left = leftChild;
    root->right = rightChild;
    return root;
}


TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* temp = A;
    int c=0;
    while(A!=NULL)
    {
        c++;
        A=A->next;
    }
    return getTree(0,c-1,&temp);
}
