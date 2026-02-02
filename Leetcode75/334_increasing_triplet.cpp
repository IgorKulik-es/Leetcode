#include <vector>
#include <iostream>

class Solution
{
	public:
		bool increasingTriplet(std::vector<int>& nums);
};

bool Solution::increasingTriplet(std::vector<int>& nums)
{
	int	lowest = INT32_MAX;
	int	middle = INT32_MAX;

	for (int num : nums)
	{
		if (num <= lowest)
			lowest = num;
		else if (num <= middle)
			middle = num;
		else
			return true;
	}
	return false;
}

int	main()
{
	Solution	solve;

	std::vector<int>	vec({6,5,5,4,4,6});
	bool				result;

	result = solve.increasingTriplet(vec);
	std::cout << result << std::endl;
	return (0);
}