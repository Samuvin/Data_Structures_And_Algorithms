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
    void Preorder_Iterative(TreeNode* root,vector<int>&preorder)
    {
        if(root==NULL)
            return;
        stack<TreeNode*>Stack_Trace;
        Stack_Trace.push(root);
        TreeNode* curr;
        while(!Stack_Trace.empty())
        {
            curr=Stack_Trace.top();
            Stack_Trace.pop();
            preorder.push_back(curr->val);
            if(curr->right)
            {
                Stack_Trace.push(curr->right);
            }
            if(curr->left)
            {
                Stack_Trace.push(curr->left);
            }
        }
    }
    void Preorder_Space_Optimised(TreeNode* root,vector<int>&preorder)
    {
        stack<TreeNode*>Stack_Trace;
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
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>preorder;
        //Preorder_Recursive(root,preorder);
        //Preorder_Iterative(root,preorder);
        Preorder_Space_Optimised(root,preorder);
        return preorder;    
    }
};
