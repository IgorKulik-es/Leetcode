#include <iostream>
#include <vector>


class Solution {
public:
	std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies)
	{
		int	size = candies.size();
		std::vector<bool>	result(size, false);
		int	maxCandy = 0;

		for (int i = 0; i < size; i++)
		{
			if (candies[i] > maxCandy)
				maxCandy = candies[i];
		}
		maxCandy -= extraCandies;
		for (int i = 0; i < size; i++)
		{
			result[i] = (candies[i] >= maxCandy);
			std::cout << result[i] << " ";
		}
		return result;
	}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::vector<int>	vec({2,3,5,1,3});

	solve.kidsWithCandies(vec, 3);
	std::cout << std::endl;
	return (0);
}