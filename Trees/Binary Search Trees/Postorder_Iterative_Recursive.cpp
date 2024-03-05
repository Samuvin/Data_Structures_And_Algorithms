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
    void Postorder_Recursive(TreeNode* root, vector<int>&postorder)
    {
        if(root==NULL)
            return;
        Postorder_Recursive(root->left,postorder);
        Postorder_Recursive(root->right,postorder);
        postorder.push_back(root->val);
    }
    vector<int> Postorder_Iterative(TreeNode* root)
    {
        vector<int>postorder;
        stack<TreeNode*>Stack_Trace;
        TreeNode* curr=root;
        while(curr!=NULL || !Stack_Trace.empty())
        {
            if(curr!=NULL)
            {
                Stack_Trace.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode* prev=Stack_Trace.top()->right;
                if(prev==NULL)
                {
                    prev=Stack_Trace.top();
                    Stack_Trace.pop();
                    postorder.push_back(prev->val);
                    while(!Stack_Trace.empty() && prev==Stack_Trace.top()->right)
                    {
                        prev=Stack_Trace.top();
                        Stack_Trace.pop();
                        postorder.push_back(prev->val);
                    }
                }
                else
                {
                    curr=prev;
                }
            }
        }
        return postorder;
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int>postorder;
        Postorder_Recursive(root,postorder);
        return postorder;
        return Postorder_Iterative(root);    
    }
};
