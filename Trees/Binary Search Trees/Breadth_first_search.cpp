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
void levelOrder_Printing(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> width;
    width.push(root);
    while (!width.empty())
    {
        TreeNode *curr = width.front();
        width.pop();
        cout << curr->val << " ";
        if (curr->left)
            width.push(curr->left);
        if (curr->right)
            width.push(curr->right);
    }
    return;
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> levelorder;
    if (root == NULL)
        return levelorder;
    queue<TreeNode *> width;
    width.push(root);
    while (!width.empty())
    {
        int width_size = width.size();
        vector<int> level;
        for (int i = 0; i < width_size; i++)
        {
            TreeNode *node = width.front();
            width.pop();
            if (node->left)
            {
                width.push(node->left);
            }
            if (node->right)
            {
                width.push(node->right);
            }
            level.push_back(node->val);
        }
        levelorder.push_back(level);
    }
    return levelorder;
}
vector<vector<int>> BFS(TreeNode *root)
{
    return levelOrder(root);
    levelOrder_Printing(root);
}
