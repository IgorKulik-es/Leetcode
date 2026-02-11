#include <iostream>
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <map>

class Solution
{
	private:
		std::map<ssize_t, int>	sums;
		int						targetSum;
		int						result = 0;
		void					DepthSearch(TreeNode* root, ssize_t currentSum);
	public:
		int pathSum(TreeNode* root, int targetSum);
};

int	Solution::pathSum(TreeNode* root, int targetSum)
{
	this->targetSum = targetSum;
	result = 0;
	if (root == nullptr)
		return 0;
	DepthSearch(root, 0);
	return result;
}

void	Solution::DepthSearch(TreeNode* root, ssize_t currentSum)
{
	ssize_t	diff;

	currentSum += root->val;
	diff = currentSum - targetSum;
	if (sums[diff] > 0)
		result += sums[diff];
	if (diff == 0)
		result++;
	sums[currentSum]++;
	if (root->left != nullptr)
		DepthSearch(root->left, currentSum);
	if (root->right != nullptr)
		DepthSearch(root->right, currentSum);
	sums[currentSum]--;
}

int main()
{
	Solution	solve;
	TreeNode	root(1);
	TreeNode	left(-2);
	TreeNode	right(-3);

	root.left = &left;
	root.right = &right;
	std::cout << solve.pathSum(&root, -1) << std::endl;
	return 0;
}