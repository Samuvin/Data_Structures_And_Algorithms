/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Build_Binary_Tree(vector<int>&inorder,int left,int right,vector<int>&preorder,int &root_idx,    unordered_map<int,int>&inorder_index)
    {
        if(left>right)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[root_idx]);
        int pivot=inorder_index[preorder[root_idx]];
        root_idx++;
        root->left=Build_Binary_Tree(inorder,left,pivot-1,preorder,root_idx,inorder_index);
        root->right=Build_Binary_Tree(inorder,pivot+1,right,preorder,root_idx,inorder_index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int limit=inorder.size();
        int start=0;
        unordered_map<int,int>inorder_index;
        for(int i=0;i<limit;i++)
            inorder_index[inorder[i]]=i;
        return Build_Binary_Tree(inorder,0,limit-1,preorder,start,inorder_index);    
    }
};
