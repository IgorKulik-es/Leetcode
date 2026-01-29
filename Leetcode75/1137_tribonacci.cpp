#include <vector>
#include <iostream>

class Solution
{
	private:
		static std::vector<int>	knownNumbers;
		static int				lastKnown;
	public:
		int	tribonacci(int n);
};

std::vector<int>	Solution::knownNumbers = {0, 1, 1};
int					Solution::lastKnown = 2;

int	Solution::tribonacci(int n)
{
	if (n <= lastKnown)
		return knownNumbers[n];
	for (int i = lastKnown + 1; i <= n; i++)
		knownNumbers.push_back(knownNumbers[i - 1] + knownNumbers[i - 2] + knownNumbers[i - 3]);
	lastKnown = n;
	return knownNumbers[n];
}

int	main()
{
	Solution	solve;

	std::cout << solve.tribonacci(4) << std::endl;
	return (0);
}