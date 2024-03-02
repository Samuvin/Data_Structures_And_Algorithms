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
    void RightSideView_BFS(TreeNode* root,vector<int>&res)
    {
        queue<TreeNode*>level;
        level.push(root);
        while(!level.empty())
        {
            int size=level.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=level.front();
                level.pop();
                if(curr->left)
                    level.push(curr->left);
                if(curr->right)
                    level.push(curr->right);
                if(i==size-1)
                    res.push_back(curr->val);
            }
        }
    }
    void RightSideView_DFS(TreeNode* root,vector<int>&res,int level)
    {
        if(root==NULL)  
            return;
        if(level==res.size())
            res.push_back(root->val);
        RightSideView_DFS(root->right,res,level+1);
        RightSideView_DFS(root->left,res,level+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<int>res;
        RightSideView_DFS(root,res,0);
        return res;    
    }
};
