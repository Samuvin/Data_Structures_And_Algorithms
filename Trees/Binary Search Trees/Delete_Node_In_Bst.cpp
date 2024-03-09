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
    TreeNode* Find_Successor(TreeNode* root)
    {
        TreeNode* curr=root->right;
        while(curr!=NULL && curr->left!=NULL)
            curr=curr->left;
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
            return NULL;
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }    
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            if(root->left==NULL)
            {
                TreeNode* Replace=root->right;
                delete root;
                return Replace;
            }
            else if(root->right==NULL)
            {
                TreeNode* Replace=root->left;
                delete root;
                return Replace;
            }
            else
            {
                TreeNode* inorder_successor=Find_Successor(root);
                root->val=inorder_successor->val;
                root->right=deleteNode(root->right,inorder_successor->val);
            }
        }
        return root;
    }
};
