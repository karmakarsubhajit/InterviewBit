//https://www.interviewbit.com/problems/unique-binary-search-trees/

//Time Complexity:- O(n*Gn) Gn is catalan number
//Space Complexity:-  O(n*Gn) Gn is catalan number


vector<TreeNode*> generateList(int l, int r)
{
    if(l>r)
    {
        vector<TreeNode*> v;
        v.push_back(NULL);
        return v;
    }
    else if(l==r)
    {
        vector<TreeNode*> v;
        v.push_back(new TreeNode(r));
        return v;
    }
    else
    {
        vector<TreeNode*> ans;
        for(int s=l;s<=r;s++)
        {
            
            vector<TreeNode*> leftList = generateList(l,s-1);
            vector<TreeNode*> rightList = generateList(s+1,r);
            
            for(auto ln:leftList)
            {
                for(auto rn:rightList)
                {
                    TreeNode* root = new TreeNode(s);
                    root->left = ln;
                    root->right = rn;
                    ans.push_back(root);
                }
            }  
        }
        return ans;
    }
    vector<TreeNode*> p;
    return p;
}


vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return generateList(1,A);

}
