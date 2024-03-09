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
    void DFS(TreeNode* root,vector<int>&inorder)
    {
        if(root==NULL)
            return;
        DFS(root->left,inorder);
        inorder.push_back(root->val);
        DFS(root->right,inorder);
    }
    bool Two_Sum_Brute(TreeNode* root,int target)
    {
        vector<int>inorder;
        DFS(root,inorder);
        int lo=0;
        int hi=inorder.size()-1;
        while(lo<hi)
        {
            int sum=inorder[lo]+inorder[hi];
            if(sum==target)
                return true;
            if(sum<target)
                lo++;
            else 
                hi--;
        }
        return false;
    }
    bool Two_Sum(TreeNode* root,set<int>&hash,int target)
    {
        if(root==NULL)
            return false;
        if(Two_Sum(root->left,hash,target))
        {
            return true;
        }
        if(hash.find(target-root->val)!=hash.end())
            return true;
        hash.insert(root->val);
        return Two_Sum(root->right,hash,target);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        set<int>hash;
        return Two_Sum(root,hash,k);
        return Two_Sum_Brute(root,k);
    }
};
