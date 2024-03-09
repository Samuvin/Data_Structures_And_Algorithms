class Solution{

public:
    int Floor_Bst_Iterative(Node* root,int x)
    {
        int res=-1;
        Node* curr=root;
        while(curr)
        {
            if(curr->data==x)
            {
                return x;
            }
            else if(curr->data>x)
            {
                curr=curr->left;
            }
            else
            {
                res=curr->data;
                curr=curr->right;
            }
        }
        return res;
    }
    void Floor_Bst(Node* root,int x,int &res)
    {
        if(root==NULL)
            return;
        if(root->data==x)
        {
            res=x;
            return;
        }
        else if(root->data>x)
        {
            Floor_Bst(root->left,x,res);
        }
        else
        {
            res=root->data;
            Floor_Bst(root->right,x,res);
        }
    }
    int floor(Node* root, int x) 
    {
        return Floor_Bst_Iterative(root,x);
        int res=-1;
        Floor_Bst(root,x,res);
        return res;
    }
};
