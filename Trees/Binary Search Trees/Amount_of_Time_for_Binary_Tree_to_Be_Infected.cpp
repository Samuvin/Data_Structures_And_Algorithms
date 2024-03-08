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
    TreeNode* Mark_Parent_Pointer(TreeNode* root,int start,map<TreeNode*,TreeNode*>&Parent_Node)
    {
        TreeNode* Start_Node;
        queue<TreeNode*>level;
        level.push(root);
        while(!level.empty())
        {
            TreeNode* curr=level.front();
            level.pop();
            if(curr->val==start)
                Start_Node=curr;
            if(curr->left)
            {
                Parent_Node[curr->left]=curr;
                level.push(curr->left);
            }
            if(curr->right)
            {
                Parent_Node[curr->right]=curr;
                level.push(curr->right);
            } 
        }
        return Start_Node;
    }
    int Find_Max_Time(TreeNode* Start_Node,map<TreeNode*,TreeNode*>&Parent_Node)
    {
        map<TreeNode*,int>visited;
        visited[Start_Node]=1;
        queue<TreeNode*>Infected;
        Infected.push(Start_Node);
         int Max_Time=0;
        while(!Infected.empty())
        {
            int size=Infected.size();
            cout<<size<<" ";
            bool IsInfected=false;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=Infected.front();
                Infected.pop();
                if(curr->left && !visited[curr->left])
                {
                    visited[curr->left]=1;
                    Infected.push(curr->left);
                    IsInfected=true;
                }
                if(curr->right && !visited[curr->right])
                {
                    visited[curr->right]=1;
                    Infected.push(curr->right);
                    IsInfected=true;
                }
                if(Parent_Node[curr] && !visited[Parent_Node[curr]])
                {
                    visited[Parent_Node[curr]]=1;
                    IsInfected=true;
                    Infected.push(Parent_Node[curr]);
                }
            }
            if(IsInfected)
            {
                Max_Time++;
            }
            
        }
        return Max_Time;
    }
    int amountOfTime(TreeNode* root, int start)
    {
        map<TreeNode*,TreeNode*>Parent_Node;
        TreeNode* Start_Node=Mark_Parent_Pointer(root,start,Parent_Node);  
        int MaxTime=Find_Max_Time(Start_Node,Parent_Node);
        return MaxTime;  
    }
};
