
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int res=0;
        auto DFS=[&](auto self,TreeNode* root)->int
        {
            if(root==NULL)
                return 0;
            int lh=self(self,root->left);
            int rh=self(self,root->right);
            res=max(res,lh+rh);
            return 1+max(lh,rh);
        };
        DFS(DFS,root);
        return res;
    }
};
