#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
	public:
		bool uniqueOccurrences(std::vector<int>& arr)
		{
			std::vector<short>		hits(2001, 0);
			std::vector<bool>		frequencies(1000, false);

			for (int element: arr)
				hits[element + 1000]++;
			for (int frequency: hits)
			{
				if (frequency != 0)
				{
					if (frequencies[frequency] == true)
						return false;
					frequencies[frequency] = true;
				}
			}
			return true;
		}
};

int	main()
{
	Solution	solve;

	std::vector<int>	vec{1};

	std::cout << solve.uniqueOccurrences(vec) << std::endl;
	return (0);
}