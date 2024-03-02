bool SolvePathInATree(TreeNode<int>*root,int target,vector<int>&res)
{
	if(root==NULL)
		return false;
	res.push_back(root->data);
	if(target==root->data)
	{
		return true;
	}
	if(SolvePathInATree(root->left,target,res) || SolvePathInATree(root->right,target,res))
		return true;
	res.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int>res;
	SolvePathInATree(root,x,res);
    return res;
}
