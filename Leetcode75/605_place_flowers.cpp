#include <iostream>
#include <vector>

class Solution
{
	private:
		bool IsNeighboured(std::vector<int>& flowerbed, size_t index);
	public:
		bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
		{
			int		planted = 0;
			int		size = flowerbed.size();

			if (n == 0)
				return true;
			for (int i=0; i < size; i++)
			{
				if (IsNeighboured(flowerbed, i) == false && flowerbed[i] == 0)
				{
					planted++;
					if (planted == n)
						return true;
					flowerbed[i] = 1;
				}
			}
			return false;
		}
};

bool Solution::IsNeighboured(std::vector<int>& flowerbed, size_t index)
{
	if (index > 0 && flowerbed[index - 1] == 1)
		return true;
	if ((index + 1 < flowerbed.size()) && flowerbed[index + 1] == 1)
		return true;
	return false;
}


int	main()
{
	Solution	solve;

	std::vector<int>	vec{0,0,1,0,1};

	std::cout << solve.canPlaceFlowers(vec, 2) << std::endl;
	return (0);
}