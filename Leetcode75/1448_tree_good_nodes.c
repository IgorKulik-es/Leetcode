#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int	CheckNode(struct TreeNode* node, int maxValue)
{
	int	countGood = 0;

	if (node->val >= maxValue)
	{
		countGood = 1;
		maxValue = node->val;
	}
	if (node->left != NULL)
		countGood += CheckNode(node->left, maxValue);
	if (node->right != NULL)
		countGood += CheckNode(node->right, maxValue);
	return countGood;
}

int goodNodes(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return CheckNode(root, root->val);
}