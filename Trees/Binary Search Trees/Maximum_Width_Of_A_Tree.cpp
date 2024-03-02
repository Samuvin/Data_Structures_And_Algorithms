class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root)
    {
        if(root==NULL)
            return 0;
        queue<Node*>level;
        level.push(root);
        int res=0;
        while(!level.empty())
        {
            int size=level.size();
            res=max(res,size);
            for(int i=0;i<size;i++)
            {
                Node* curr=level.front();
                level.pop();
                if(curr->left)
                    level.push(curr->left);
                if(curr->right)
                    level.push(curr->right);
            }
        }
        return res;
        
    }
};
