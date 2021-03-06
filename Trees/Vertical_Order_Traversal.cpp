// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
/*
Problem Description

Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.

Go through the example and image for more details.

NOTE:

If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the pre-order traversal of tree comes first in the output.
Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the nodes on the rightmost vertical line.


Problem Constraints
0 <= N <= 104



Input Format
First and only argument is an pointer to root of the binary tree A.



Output Format
Return a 2D array denoting the vertical order traversal of A.



Example Input
Input 1:

      6
    /   \
   3     7
  / \     \
 2   5     9
Input 2:

           1
         /   \
        2     3
       / \
      4   5


Example Output
Output 1:

 [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
 ]
Output 2:

 [
    [4],
    [2],
    [1, 5],
    [3]
 ]


Example Explanation
Explanation 1:

 
 Nodes on Vertical Line 1: 2
 Nodes on Vertical Line 2: 3
 Nodes on Vertical Line 3: 6, 5
    As 6 and 5 are on the same vertical level but as 6 comes first in the pre-order traversal of the tree so we will output 6 before 5.
 Nodes on Vertical Line 4: 7
 Nodes on Vertical Line 5: 9
Explanation 2:

 Nodes on Vertical Line 1: 4
 Nodes on Vertical Line 2: 2
 Nodes on Vertical Line 3: 1, 5
 Nodes on Vertical Line 4: 3

*/

// DFS soln
// Time Complexity:- O(n)
// Space Complexity:- O(n)

void getVerticalOrder(TreeNode* root, int lev, unordered_map<int, vector<int>>& mp)
{
    if(root==NULL)
        return;
    mp[lev].push_back(root->val);
    
    getVerticalOrder(root->left,lev-1,mp);
    getVerticalOrder(root->right,lev+1,mp);
    
}


vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* A) 
{
    unordered_map<int,vector<int>> mp;
    getVerticalOrder(A,0,mp);
    vector<vector<int>> ans;
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}



// BFS soln || Level Order
// Time Complexity:- O(n)
// Space Complexity:- O(n)


vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* A) 
{
     vector<vector<int>> ans;
    if(A==NULL)
        return ans;
    unordered_map<int,vector<int>> mp;
    queue<pair<TreeNode*,int>> q;
    q.push(make_pair(A,0));
    int mn=0;
    int mx=0;
    while(q.size()!=0)
    {
        pair<TreeNode*,int> curr = q.front();
        q.pop();
        TreeNode* n = curr.first;
        int d = curr.second;
        mn = min(mn,d);
        mx =max(mx,d);
        mp[d].push_back(n->val);
        if(n->left!=NULL)
            q.push(make_pair(n->left,d-1));
        if(n->right!=NULL)
            q.push(make_pair(n->right,d+1));    
    }

   
    for(int i=mn;i<=mx;i++)
    {
        ans.push_back(mp[i]);
    }
    return ans;
}
