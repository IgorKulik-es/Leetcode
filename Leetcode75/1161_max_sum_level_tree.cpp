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

#include <queue>

class Solution
{
	public:
		int maxLevelSum(TreeNode* root);
};

int	Solution::maxLevelSum(TreeNode* root)
{
	std::queue<TreeNode*>	queueLevel;
	TreeNode*				front;
	int						nodesCurrent = 1;
	int						currentLevel = 1;
	int						bestLevel = 1;
	long long				currentSum = 0;
	long long				bestSum = root->val;

	queueLevel.push(root);
	while (queueLevel.empty() == false)
	{
		while (nodesCurrent > 0)
		{
			front = queueLevel.front();
			currentSum += front->val;
			if (front->left != nullptr)
				queueLevel.push(front->left);
			if (front->right != nullptr)
				queueLevel.push(front->right);
			nodesCurrent--;
			queueLevel.pop();
		}
		nodesCurrent = queueLevel.size();
		if (currentSum > bestSum)
		{
			bestSum = currentSum;
			bestLevel = currentLevel;
		}
		currentSum = 0;
		currentLevel++;
	}
	return bestLevel;
}

int main()
{
	Solution	solve;
	TreeNode	root(5);

	std::cout << solve.maxLevelSum(&root) << std::endl;
	return 0;
}