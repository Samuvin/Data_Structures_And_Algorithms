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
    int MaxPathSumHelper(TreeNode *root,int &res)
    {
        if(root==NULL)
            return 0;
        int left=max(MaxPathSumHelper(root->left,res),0);
        int right=max(MaxPathSumHelper(root->right,res),0);
        res=max(res,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) 
    {
        int res=-1e9;
        MaxPathSumHelper(root,res);
        return res;    
    }
};
