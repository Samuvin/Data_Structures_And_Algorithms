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
    void DFS_LINK(TreeNode* root,TreeNode* &prev)
    {
        if(root==NULL)
            return;
        DFS_LINK(root->right,prev);
        DFS_LINK(root->left,prev);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    void Stack_Link(TreeNode* root)
    {
        stack<TreeNode*>Stack_Trace;
        Stack_Trace.push(root);
        while(!Stack_Trace.empty())
        {
            TreeNode* curr=Stack_Trace.top();
            Stack_Trace.pop();
            if(curr->right)
            {
                Stack_Trace.push(curr->right);
            }
            if(curr->left)
            {
                Stack_Trace.push(curr->left);
            }
            curr->left=NULL;
            if(!Stack_Trace.empty())
            {
                curr->right=Stack_Trace.top();
            }
        }
    }
    void Morris_Link(TreeNode* root)
    {
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* prev=curr->left;
                while(prev->right)
                {
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
    void flatten(TreeNode* root) 
    {    
        if(root==NULL)
            return;
        //TreeNode* prev=nullptr;
        //Stack_Link(root);
        Morris_Link(root);
    }
};
