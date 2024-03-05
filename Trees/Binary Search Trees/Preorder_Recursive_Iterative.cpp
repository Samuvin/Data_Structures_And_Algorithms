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
    void Preorder_Recursive(TreeNode* root,vector<int>&preorder)
    {
        if(root==NULL)
            return;
        preorder.push_back(root->val);
        Preorder_Recursive(root->left,preorder);
        Preorder_Recursive(root->right,preorder);
    }
    vector<int> Preorder_Iterative(TreeNode* root)
    {
        stack<TreeNode*>Stack_Trace;
        vector<int>preorder;
        TreeNode* curr=root;
        while(curr!=NULL || !Stack_Trace.empty())
        {
            while(curr!=NULL)
            {
                preorder.push_back(curr->val);
                if(curr->right)
                    Stack_Trace.push(curr->right);
                curr=curr->left;
            }
            if(!Stack_Trace.empty())
            {
                curr=Stack_Trace.top();
                Stack_Trace.pop();
            }
        }
        return preorder;
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(root==NULL)
            return {};
        return Preorder_Iterative(root);    
        // vector<int>preorder;
        // Preorder_Recursive(root,preorder);
        // return preorder;
    }
};
