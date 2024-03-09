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
    TreeNode* Build_Binary_Tree(vector<int>&inorder,int left,int right,vector<int>&postorder,int &root_idx,unordered_map<int,int>&inorder_index)
    {
        if(left>right)
            return NULL;
        TreeNode* root=new TreeNode(postorder[root_idx]);
        int pivot=inorder_index[postorder[root_idx]];
        root_idx--;
        root->right=Build_Binary_Tree(inorder,pivot+1,right,postorder,root_idx,inorder_index);
        root->left=Build_Binary_Tree(inorder,left,pivot-1,postorder,root_idx,inorder_index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int root_idx=inorder.size()-1;
        unordered_map<int,int>inorder_index;
        for(int i=0;i<=root_idx;i++)
        {
            inorder_index[inorder[i]]=i;
        }    
        return Build_Binary_Tree(inorder,0,inorder.size()-1,postorder,root_idx,inorder_index);
    }
};
