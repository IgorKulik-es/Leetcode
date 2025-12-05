#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int	maxDepthValue;

int	DigDown(struct TreeNode* node, int currentDepth)
{
	if (currentDepth > maxDepthValue)
		maxDepthValue = currentDepth;
	if (node->left != NULL)
		DigDown(node->left, currentDepth + 1);
	if (node->right != NULL)
		DigDown(node->right, currentDepth + 1);
	return maxDepthValue;
}


int maxDepth(struct TreeNode* root)
{
	maxDepthValue = 0;
	if (root == NULL)
		return 0;
	return (DigDown(root, 1));
}