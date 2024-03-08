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
    int check_right_height(TreeNode* root)
    {
        int cnt=0;
        TreeNode* curr=root;
        while(curr)
        {
            curr=curr->right;
            cnt++;
        }
        return cnt;
    }
    int check_left_height(TreeNode* root)
    {
        int cnt=0;
        TreeNode* curr=root;
        while(curr)
        {
            curr=curr->left;
            cnt++;
        }
        return cnt;
    }
    int Count_nodes_Complete_Tree(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int right_child=check_right_height(root);
        int left_child=check_left_height(root);
        if(right_child==left_child)
        {
            return (1<<right_child)-1;
        }
        return 1+Count_nodes_Complete_Tree(root->left)+Count_nodes_Complete_Tree(root->right);
    }
    int count_nodes_brute(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+count_nodes_brute(root->left)+count_nodes_brute(root->right);
    }
    int countNodes(TreeNode* root)
    {
        return Count_nodes_Complete_Tree(root);
        return count_nodes_brute(root);    
    }
};
