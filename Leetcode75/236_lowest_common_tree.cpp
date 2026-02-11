#include <iostream>

struct TreeNode
{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//This one is with recursion. It's heavy on the memory, but it's fast.
//Tried an iterative one with lists and it was way too slow, probably my fault=)

class Solution
{
	private:
		TreeNode*	DiveDown(TreeNode* root, TreeNode* p, TreeNode* q);
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};

TreeNode*	Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode*	find;

	find = DiveDown(root, p, q);
	return find;
}

TreeNode*	Solution::DiveDown(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode*	findLeft;
	TreeNode*	findRight;

	if (root == nullptr || root == p || root == q)
		return root;
	findLeft = DiveDown(root->left, p, q);
	findRight = DiveDown(root->right, p, q);
	if (findLeft != nullptr && findRight != nullptr)
		return root;
	else if (findLeft != nullptr)
		 return findLeft;
	return findRight;
}

int main()
{
	Solution	solve;
	TreeNode	root(3);
	TreeNode	leaf(2);

	root.left = &leaf;
	std::cout << (solve.lowestCommonAncestor(&root, &root, &leaf))->val << std::endl;
	return 0;
}