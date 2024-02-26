/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Brute Force
class Solution {
public:
    bool Build_Path(TreeNode* root, TreeNode* target,vector<TreeNode*>&path)
    {
        if(root==NULL)
            return false;
        path.push_back(root);
        if(root==target)
            return true;
        if(Build_Path(root->left,target,path) || Build_Path(root->right,target,path))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* LCA_BRUTE(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*>Path_For_p;
        if(!Build_Path(root,p,Path_For_p))
            return NULL;
        vector<TreeNode*>Path_For_q;
        if(!Build_Path(root,q,Path_For_q))
            return NULL;
        int size1=Path_For_q.size();
        int size2=Path_For_p.size();
        TreeNode* res=NULL;
        for(int i=0;i<size1 && i<size2;i++)
        {
            if(Path_For_p[i]==Path_For_q[i])
                res=Path_For_q[i];
            else
                break;
        }
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return LCA_BRUTE(root,p,q);    
    }
};


// Optimised
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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
            return NULL;
        if(root==p || root==q)
            return root;
        TreeNode* left_subtree=LCA(root->left,p,q);
        TreeNode* right_subtree=LCA(root->right,p,q);
        if(left_subtree!=NULL && right_subtree!=NULL)
            return root;
        else if(left_subtree==NULL)
            return right_subtree;
        else
            return left_subtree;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return LCA(root,p,q);    
    }
};
