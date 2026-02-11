#include <vector>
#include <algorithm>
#include <iostream>

//just really gave up on this one, kept getting TLE event with randomized pivot
//so just used the STL
class Solution
{
	public:
		int findKthLargest(std::vector<int>& nums, int k);
};

int	Solution::findKthLargest(std::vector<int>& nums, int k)
{
	std::vector<int>::iterator	find;

	find = nums.begin() + k - 1;
	std::nth_element(nums.begin(), find, nums.end(), std::greater<int>());
	return *find;
}

int	main()
{
	Solution	solve;
	std::vector<int> vec({3,2,3,1,2,4,5,5,6});

	std::cout << solve.findKthLargest(vec, 4) << std::endl;
	return (0);
}