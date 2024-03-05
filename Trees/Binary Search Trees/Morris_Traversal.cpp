// inorder
class Solution {
public:
    vector<int> Morris_Traversal(TreeNode* root)
    {
        vector<int>inorder;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* predecessor=curr->left;
                while(predecessor->right!=NULL && predecessor->right!=curr)
                {
                    predecessor=predecessor->right;
                }
                if(predecessor->right==NULL)
                {
                    predecessor->right=curr;
                    curr=curr->left;
                }
                else if(predecessor->right==curr)
                {
                    inorder.push_back(curr->val);
                    predecessor->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(root==NULL)
            return {};
        return Morris_Traversal(root);    
    }
};
//preorder
class Solution {
public:
    vector<int> Morris_Traversal(TreeNode* root)
    {
        vector<int>preorder;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* predecessor=curr->left;
                while(predecessor->right && predecessor->right!=curr)
                    predecessor=predecessor->right;
                if(predecessor->right==NULL)
                {
                    predecessor->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    predecessor->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        return Morris_Traversal(root);    
    }
};
//postorder
class Solution {
public:
    vector<int> Morris_Traversal(TreeNode* root)
    {
        vector<int>postorder;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->right==NULL)
            {
                postorder.push_back(curr->val);
                curr=curr->left;
            }
            else
            {
                TreeNode* successor=curr->right;
                while(successor->left && successor->left!=curr)
                {
                    successor=successor->left;
                }
                if(successor->left==NULL)
                {
                    postorder.push_back(curr->val);
                    successor->left=curr;
                    curr=curr->right;
                }
                else if(successor->left==curr)
                {
                    successor->left=NULL;
                    curr=curr->left;
                }
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        return Morris_Traversal(root);    
    }
};
