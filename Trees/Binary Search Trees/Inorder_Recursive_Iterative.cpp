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
class Solution
{
public:
    void Inorder_Iterative(TreeNode *root, vector<int> &inorder)
    {
        TreeNode *curr = root;
        stack<TreeNode *> Stack_Trace;
        while (curr != NULL || !Stack_Trace.empty())
        {
            while (curr)
            {
                Stack_Trace.push(curr);
                curr = curr->left;
            }
            if (!Stack_Trace.empty())
            {
                curr = Stack_Trace.top();
                Stack_Trace.pop();
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
                break;
        }
    }
    void Inorder_Recursive(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        Inorder_Recursive(root->left, inorder);
        inorder.push_back(root->val);
        Inorder_Recursive(root->right, inorder);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        // Inorder_Recursive(root,inorder);
        Inorder_Iterative(root, inorder);
        return inorder;
    }
};
