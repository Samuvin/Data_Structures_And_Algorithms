class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void Binary_Tree_To_Linked_List(Node* root,Node* &prev,Node* &Head)
    {
        if(root==NULL)
            return;
        Binary_Tree_To_Linked_List(root->left,prev,Head);
        if(Head==NULL)
        {
            Head=root;
        }
        else
        {
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        Binary_Tree_To_Linked_List(root->right,prev,Head);
    }
    Node * bToDLL(Node *root)
    {
        Node* prev=NULL;
        Node* Head=NULL;
        Binary_Tree_To_Linked_List(root,prev,Head);
        return Head;
    }
};
