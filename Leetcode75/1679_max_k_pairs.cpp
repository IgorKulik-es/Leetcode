#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
	private:
		int	result;
	public:
		int maxOperations(std::vector<int>& nums, int k);
};

int	Solution::maxOperations(std::vector<int>& nums, int k)
{
	int	indLow = 0;
	int	indHigh = nums.size() - 1;
	int	difference;
	int	halfSum = k / 2;
	result = 0;

	std::sort(nums.begin(), nums.end());
	while (indLow < indHigh)
	{
		difference = k - nums[indLow];
		if (difference < halfSum)
			break;
		if (nums[indHigh] == difference)
		{
			indHigh--;
			indLow++;
			result++;
		}
		else if (nums[indHigh] > difference)
			indHigh--;
		else
			indLow++;
	}
	return result;
}

int	main()
{
	Solution	solve;
	int			result;

	std::vector<int>	vec1({1,2,3,4});
	result = solve.maxOperations(vec1, 5);
	std::cout << result << std::endl;

	std::vector<int>	vec2({3,1,3,4,3});
	result = solve.maxOperations(vec2, 6);
	std::cout << result << std::endl;

	{std::vector<int>	vec2({1,1,1,-1,2,0,3});
	result = solve.maxOperations(vec2, 2);
	std::cout << result << std::endl;}

	return (0);
}