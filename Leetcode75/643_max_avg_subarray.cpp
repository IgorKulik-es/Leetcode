#include <vector>
#include <iostream>


class Solution {
public:
	double findMaxAverage(std::vector<int>& nums, int k)
	{
		long						maxSum = 0;
		long						currentSum;
		std::vector<int>::iterator	iterFront;
		std::vector<int>::iterator	iterBack;
		std::vector<int>::iterator	end;

		for (int i = 0; i < k; i++)
			maxSum += nums[i];
		currentSum = maxSum;
		iterFront = nums.begin() + k;
		iterBack = nums.begin();
		end = nums.end();
		while (iterFront != end)
		{
			currentSum += *iterFront - *iterBack;
			if (currentSum > maxSum)
				maxSum = currentSum;
			iterFront++;
			iterBack++;
		}
		return (((double)maxSum) / k);
	}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::vector<int>	nums = {1,12,-5,-6,50,3,7,-10,-20,1,1,1,1,1,1,1,1};

	std::cout << solve.findMaxAverage(nums, 10) << std::endl;
	return (0);
}