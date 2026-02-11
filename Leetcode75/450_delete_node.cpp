struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
class Solution
{
	private:
		std::pair<TreeNode*, bool>	SearchDown(TreeNode* root, TreeNode* prev, bool leftTurn, int key);
		TreeNode*	EmplaceChildren(TreeNode* root);
		void		InsertNode(TreeNode* root, TreeNode* insert);
	public:
		TreeNode* deleteNode(TreeNode* root, int key);
};

TreeNode*	Solution::deleteNode(TreeNode* root, int key)
{
	TreeNode					dummy(0);
	std::pair<TreeNode*, bool>	foundPair;
	TreeNode*					parent;

	dummy.left = root;
	foundPair = SearchDown(root, &dummy, true, key);
	parent = foundPair.first;
	if (parent == nullptr)
		return root;
	if (foundPair.second)
		parent->left = EmplaceChildren(parent->left);
	else
		parent->right = EmplaceChildren(parent->right);
	return dummy.left;
}

std::pair<TreeNode*, bool>	Solution::SearchDown(TreeNode* root, TreeNode* prev, bool leftTurn, int key)
{
	std::pair<TreeNode*, bool>	find;

	if (root == nullptr)
		return std::pair<TreeNode*, bool>(nullptr, true);
	if (root->val == key)
		return std::pair<TreeNode*, bool>(prev, leftTurn);
	if (root->left != nullptr)
		find = SearchDown(root->left, root, true, key);
	if (find.first != nullptr)
		return find;
	if (root->right != nullptr)
		return SearchDown(root->right, root, false, key);
	return std::pair<TreeNode*, bool>(nullptr, true);
}

TreeNode*	Solution::EmplaceChildren(TreeNode* root)
{
	if (root == nullptr)
		return nullptr;
	if (root->left == nullptr && root->right == nullptr)
		return nullptr;
	if (root->right == nullptr)
		return root->left;
	InsertNode(root->right, root->left);
	return root->right;
}

void	Solution::InsertNode(TreeNode* root, TreeNode* insert)
{
	if (insert == nullptr || root == nullptr)
		return ;
	if (insert->val > root->val)
	{
		if (root->right == nullptr)
			root->right = insert;
		else
			InsertNode(root->right, insert);
	}
	else
	{
		if (root->left == nullptr)
			root->left = insert;
		else
			InsertNode(root->left, insert);
	}
}