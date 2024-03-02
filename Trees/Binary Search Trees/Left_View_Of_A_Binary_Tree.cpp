/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
void LeftView_Bfs(Node* root,vector<int>&res)
{
    queue<Node*>level;
    level.push(root);
    while(!level.empty())
    {
        int size=level.size();
        for(int i=0;i<size;i++)
        {
            Node* curr=level.front();
            level.pop();
            if(curr->left)
                level.push(curr->left);
            if(curr->right)
                level.push(curr->right);
            if(i==0)
            {
                res.push_back(curr->data);
            }
        }
    }
}
void LeftView_Dfs(Node* root,int &maxi,int level ,vector<int>&res)
{
    if(root==NULL)
        return;
    if(maxi<level)
    {
        res.push_back(root->data);
        maxi=level;
    }
    LeftView_Dfs(root->left,maxi,level+1,res);
    LeftView_Dfs(root->right,maxi,level+1,res);
}
vector<int> leftView(Node *root)
{
   if(root==NULL)
      return {};
   vector<int>res;
   int maxi=0;
   LeftView_Dfs(root,maxi,1,res);
   //LeftView_Bfs(root,res);
   return res;
}
