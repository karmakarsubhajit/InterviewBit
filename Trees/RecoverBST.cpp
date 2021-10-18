// https://www.interviewbit.com/problems/recover-binary-search-tree/
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Tell us the 2 values swapping which the tree will be restored.

Note:

A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          
*/

// Extra space by vector and recursion stack || Two pass
// Time Complexity:- O(n)
// Space Complexity:- O(n)


void inorder(TreeNode* r, vector<int>& t)
{
    if(r==NULL)
        return;
    inorder(r->left,t);
    t.push_back(r->val);
    inorder(r->right,t);
}


vector<int> Solution::recoverTree(TreeNode* A) 
{
    vector<int> t;
    inorder(A,t);
    int a=INT_MIN,b=INT_MIN,c=INT_MIN;
    for(int i=1;i<t.size();i++)
    {
        if(t[i]<t[i-1])
        {
            if(a==INT_MIN)
            {
                a = t[i-1];
                b = t[i];
            }
            else
            {
                c=t[i];
            }
        }
    }
    vector<int> ans;
    if(c==INT_MIN)
    {
        ans.push_back(b);
        ans.push_back(a);
        
    }
    else
    {
        ans.push_back(c);
        ans.push_back(a);
        
    }
    return ans;
}


// Recursive solution || One pass
// Time Complexity:- O(n)
// Space Complexity:- O(n)


void inorder(TreeNode* root, TreeNode** prev, TreeNode** first, TreeNode** middle, TreeNode** last)
{
    if(root==NULL)
        return;
    inorder(root->left,prev,first,middle,last);
    if((*prev!=NULL)&&((*prev)->val>root->val))
    {
        if(*first==NULL)
        {
            *first=*prev;
            *middle=root;
        }
        else
            *last = root;
    }
    *prev = root;
    inorder(root->right,prev,first,middle,last);
}


vector<int> Solution::recoverTree(TreeNode* A) 
{
    vector<int> ans;
    TreeNode* prev =NULL;
    TreeNode* last =NULL;
    TreeNode* middle =NULL;
    TreeNode* first =NULL;
    
    inorder(A,&prev,&first,&middle,&last);
    if(last==NULL)
    {
        ans.push_back(middle->val);
        ans.push_back(first->val);
    }
    else
    {
        ans.push_back(last->val);
        ans.push_back(first->val);
    }
    return ans;
}



// Iterative || Constant space || One pass || Optimal
// Time Complexity:- O(n)
// Space Complexity:- O(1)



vector<int> Solution::recoverTree(TreeNode* A) 
{
    vector<int> ans;
    TreeNode* prev =NULL;
    TreeNode* last =NULL;
    TreeNode* middle =NULL;
    TreeNode* first =NULL;
    TreeNode* curr = A;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            if((prev!=NULL) && (prev->val>curr->val))
            {
                if(first==NULL)
                {
                    first = prev;
                    middle = curr;
                }
                else
                    last = curr;
            }
            prev = curr;
            curr = curr->right;
        }
        else
        {
            TreeNode* pred = curr->left;
            TreeNode* temp = curr->left;
            while(pred->right!=NULL)
                pred = pred->right;
            pred->right = curr;
            curr->left = NULL;
            curr = temp;
        }

    }
    
    if(last==NULL)
    {
        ans.push_back(middle->val);
        ans.push_back(first->val);
    }
    else
    {
        ans.push_back(last->val);
        ans.push_back(first->val);
    }
    return ans;
}
