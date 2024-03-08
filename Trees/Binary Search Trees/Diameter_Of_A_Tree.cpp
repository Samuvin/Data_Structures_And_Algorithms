
class Solution {
public:

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int res=0;
        auto Dfs_Height=[](auto self,TreeNode* root)->int
        {
            if(root==NULL)
                return 0;
            return 1+max(self(self,root->left),self(self,root->right));
        };
        auto DFS_Brute=[&](auto self,TreeNode* root) 
        {
            if(root==NULL)
                return ;
            int left=Dfs_Height(Dfs_Height,root->left);
            int right=Dfs_Height(Dfs_Height,root->right);
            res=max(res,left+right);
            self(self,root->left);
            self(self,root->right);
        };
        auto DFS_Optimal=[&res](auto self,TreeNode* root)
        {
            if(root==NULL)
                return 0;
            int left_child=self(self,root->left);
            int right_child=self(self,root->right);
            res=max(res,left_child+right_child);
            return 1+max(right_child,left_child);
        };
        //DFS_Brute(DFS_Brute,root);
        DFS_Optimal(DFS_Optimal,root);
        return res;
    }
};
