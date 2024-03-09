int Ceil_Bst_Iterative(Node* root,int input)
{
    int res=-1;
    Node* curr=root;
    while(root)
    {
        if(root->data==input)
        {
            return input;
            break;
        }
        else if(root->data>input)
        {
            res=root->data;
            root=root->left;
        }
        else
            root=root->right;
    }
    return res;
    
}
void DFS(Node* root,int input,int &res)
{
    if(root==NULL)
        return;
    else if(root->data==input)
    {
        res=input;
        return;
    }
    else if(root->data>input)
    {
        res=root->data;
        DFS(root->left,input,res);
    }
    else
    {
        DFS(root->right,input,res);
    }
}
int findCeil(Node* root, int input)
{
    int res=-1;
    return Ceil_Bst_Iterative(root,input);
    DFS(root,input,res);
    return res;
}
