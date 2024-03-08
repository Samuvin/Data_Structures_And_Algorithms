/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Mark_Parent(TreeNode* root,unordered_map<TreeNode* ,TreeNode*>&Parent_Nodes)
    {
        queue<TreeNode*>level;
        level.push(root);
        while(!level.empty())
        {
            TreeNode* curr=level.front();
            level.pop();
            if(curr->left)
            {
                level.push(curr->left);
                Parent_Nodes[curr->left]=curr;
            }
            if(curr->right)
            {
                level.push(curr->right);
                Parent_Nodes[curr->right]=curr;
            }
        }
    }
    vector<int> Nodes_At_Dist_K(TreeNode* Start_Node,unordered_map<TreeNode*, TreeNode*>Parent_Nodes,int k)
    {
        vector<int>res;
        queue<TreeNode*>level;
        map<TreeNode*,int>visited;
        level.push(Start_Node);
        visited[Start_Node]=1;
        while(!level.empty())
        {
            int size=level.size();
            if(k==0)
                break;
            k--;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=level.front();
                level.pop();
                if(curr->left && !visited[curr->left])
                {
                    level.push(curr->left);
                    visited[curr->left]=1;
                }
                if(curr->right && !visited[curr->right])
                {
                    level.push(curr->right);
                    visited[curr->right]=1;
                }
                if(Parent_Nodes[curr] && !visited[Parent_Nodes[curr]])
                {
                    level.push(Parent_Nodes[curr]);
                    visited[Parent_Nodes[curr]]=1;
                }
            }
        }
        while(!level.empty())
        {
            res.push_back(level.front()->val);
            level.pop();
        }
        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*, TreeNode*>Parent_Nodes;
        Mark_Parent(root,Parent_Nodes);   
        return Nodes_At_Dist_K(target,Parent_Nodes,k);
    }
};
