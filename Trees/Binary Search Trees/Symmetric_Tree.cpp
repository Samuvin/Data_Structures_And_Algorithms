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
    bool Check_IsSymmetric(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL || root2==NULL)
            return root1==root2;
        if(root1->val!=root2->val)
            return false;
        return Check_IsSymmetric(root1->left,root2->right) && Check_IsSymmetric(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        return Check_IsSymmetric(root->left,root->right);    
    }
};
