// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// function should print the nodes at k distance from root
void NodeAtDistanceK(struct Node *root, int k, vector<int>&res)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        res.push_back(root->data);
        return;
    }
    NodeAtDistanceK(root->left,k-1,res);
    NodeAtDistanceK(root->right,k-1,res);
}
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int>res;
    NodeAtDistanceK(root,k,res);
    return res;
}
