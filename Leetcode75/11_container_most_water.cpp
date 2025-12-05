#include <vector>
#include <iostream>

class Solution {
public:
	int maxArea(std::vector<int>& height)
	{
		int	indLeft = 0;
		int	indRight = height.size() - 1;
		int	maxCapacity = std::min(height[indLeft], height[indRight]) * indRight;
		int	currentVolume;

		while (indRight > indLeft)
		{
			if (height[indLeft] < height[indRight])
				indLeft++;
			else
				indRight--;
			currentVolume = std::min(height[indLeft], height[indRight]) * (indRight - indLeft);
			maxCapacity = std::max(currentVolume, maxCapacity);
		}
		return maxCapacity;
	}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::vector<int>	vec({1,8,6,2,5,4,8,3,7});
	
	std::cout << solve.maxArea(vec) << std::endl;
	return (0);
}