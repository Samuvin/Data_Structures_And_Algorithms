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
    TreeNode* InsertBstNode_Iterative(TreeNode* root,int val)
    {
        TreeNode* node=new TreeNode(val);
        TreeNode* parent=NULL;
        TreeNode* curr=root;
        while(curr)
        {
            parent=curr;
            cout<<curr->val<<" ";
            if(val>curr->val)
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            } 
        }
        if(parent==NULL)
            return node;
        if(parent->val>val)
            parent->left=node;
        else
            parent->right=node;
        return root;
    }
    TreeNode* InsertBstNode(TreeNode* root, int val) 
    {
        if(root==NULL)
            return new TreeNode(val);
        if(root->val>val)
            root->left=insertIntoBST(root->left,val);
        else if(root->val<val)
            root->right=insertIntoBST(root->right,val);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        return InsertBstNode_Iterative(root,val);
        return InsertBstNode(root,val);
    }
};
