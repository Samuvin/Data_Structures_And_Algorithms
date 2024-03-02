class Solution {
public:
    bool isLeaf(Node *root)
    {
        return root->left==NULL && root->right==NULL;
    }
    void AddLeaf(Node* root,vector<int>&res)
    {
        if(isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if(root->left)
            AddLeaf(root->left,res);
        if(root->right)
            AddLeaf(root->right,res);
    }
    void LeftBoundary(Node* root,vector<int>&res)
    {
        root=root->left;
        while(root)
        {
            if(!isLeaf(root))
            {
                res.push_back(root->data);
            }
            if(root->left)
                root=root->left;
            else
                root=root->right;
        }
    }
    void RightBoundary(Node* root,vector<int>&res)
    {
        vector<int>temp;
        root=root->right;
        while(root)
        {
            if(!isLeaf(root))
            {
                temp.push_back(root->data);
            }
            if(root->right)
                root=root->right;
            else 
                root=root->left;
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            res.push_back(temp[i]);
        }
    }
    vector <int> boundary(Node *root)
    {
        if(root==NULL)
            return {};
        vector<int>res;
        if(!isLeaf(root))
            res.push_back(root->data);
        LeftBoundary(root,res);
        AddLeaf(root,res);
        RightBoundary(root,res);
        return res;
    }
};
