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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        vector<vector<int>>res;
        queue<TreeNode*>level;
        level.push(root);
        bool reverse=true;
        while(!level.empty())
        {
            int size=level.size();
            vector<int>Line(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=level.front();
                level.pop();
                if(curr->left)
                    level.push(curr->left);
                if(curr->right)
                    level.push(curr->right);
                if(reverse)
                {
                    Line[i]=curr->val;
                }
                else
                {
                    Line[size-i-1]=curr->val;
                }
            }
            res.push_back(Line);
            reverse=!reverse;
        }
        return res;    
    }
};
