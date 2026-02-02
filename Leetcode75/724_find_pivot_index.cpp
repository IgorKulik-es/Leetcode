#include <iostream>
#include <vector>

class Solution
{
	private:
		int	size;
	public:
		int	pivotIndex(std::vector<int>& nums);
};

int	Solution::pivotIndex(std::vector<int>& nums)
{
	size = nums.size();
	int	totalSum = 0;
	int	leftSum = 0;

	for (int num: nums)
		totalSum += num;
	for (int i = 0; i < size; i++)
	{
		totalSum -= nums[i];
		if (leftSum == totalSum)
			return i;
		leftSum += nums[i];
	}
	return -1;
}

int	main()
{
	Solution	solve;

	{
		std::vector<int>	vec({1,7,3,6,5,6});
		std::cout << solve.pivotIndex(vec) << std::endl;
	}
	{
		std::vector<int>	vec({1,2,3});
		std::cout << solve.pivotIndex(vec) << std::endl;
	}
	{
		std::vector<int>	vec({2,1,-1});
		std::cout << solve.pivotIndex(vec) << std::endl;
	}
	{
		std::vector<int>	vec({1,-1,1,-1,1000});
		std::cout << solve.pivotIndex(vec) << std::endl;
	}
	{
		std::vector<int>	vec({1});
		std::cout << solve.pivotIndex(vec) << std::endl;
	}
	return (0);
}