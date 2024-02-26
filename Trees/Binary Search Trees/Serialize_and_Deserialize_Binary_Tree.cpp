/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//DFS
class Codec {
public:

    // Encodes a tree to a single string.
    void Serialize_Helper(TreeNode* root,string &res)
    {    
        if(root==NULL)
        {
            res+='#';
            res+=',';
            return ;
        }
        res+=to_string(root->val);
        res+=',';
        Serialize_Helper(root->left,res);
        Serialize_Helper(root->right,res);
    }
    string serialize(TreeNode* root)
    {
        string str;
        Serialize_Helper(root,str);   
        str+="@,";
        cout<<str<<" ";
        return str; 
    }
    TreeNode* Deserialize_Helper(stringstream &stream,string &helper)
    {
        getline(stream,helper,',');
        if(helper=="@" || helper=="#")
            return NULL;
        TreeNode* root=new TreeNode(stoi(helper));
        root->left=Deserialize_Helper(stream,helper);
        root->right=Deserialize_Helper(stream,helper);
        return root;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        stringstream stream(data);
        string helper;
        return Deserialize_Helper(stream,helper);    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


//BFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root==NULL)
            return "";
        queue<TreeNode*>level;
        string str;
        level.push(root);
        while(!level.empty())
        {
            TreeNode* curr=level.front();
            level.pop();
            if(curr==NULL)
            {
                str+="#,";
            }
            else
            {
                str+=to_string(curr->val);
                str+=',';
                level.push(curr->left);
                level.push(curr->right);
            }
        }
        return str;    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(!data.size())
            return NULL;
        stringstream stream(data);
        string value;
        getline(stream,value,',');
        TreeNode* root=new TreeNode(stoi(value));
        queue<TreeNode*>level;
        level.push(root);
        while(!level.empty())
        {
            TreeNode* curr=level.front();
            level.pop();
            getline(stream,value,',');
            if(value=="#")
            {
                curr->left=NULL;
            }
            else
            {
                TreeNode* leftchild=new TreeNode(stoi(value));
                curr->left=leftchild;
                level.push(leftchild);
            }
            getline(stream,value,',');
            if(value=="#")
            {
                curr->right=NULL;
            }
            else
            {
                TreeNode* rightchild=new TreeNode(stoi(value));
                curr->right=rightchild;
                level.push(rightchild);
            }
        }
        return root;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
