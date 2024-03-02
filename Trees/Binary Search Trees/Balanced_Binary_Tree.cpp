class Solution {
public:
    int Check_Helper(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left=Check_Helper(root->left);
        if(left==-1)
            return -1;
        int right=Check_Helper(root->right);
        if(right==-1)
            return -1;
        if(abs(left-right)>1)
            return -1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) 
    {
        int Height = Check_Helper(root);
        return Height!=-1;    
    }
};
