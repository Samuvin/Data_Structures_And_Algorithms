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
    bool helper(TreeNode* root,int &k,int &ans)
    {
        if(root==NULL)
            return false;
        if(helper(root->left,k,ans))
            return true;
        k--;
        if(k==0)
        {
            ans=root->val;
            return true;
        }
        if(helper(root->right,k,ans))
            return true;
        return false;
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans=-1;
        helper(root,k,ans);
        return ans;    
    }
};
