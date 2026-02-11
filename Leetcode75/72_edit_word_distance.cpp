#include <iostream>
#include <string>
#include <vector>

class Solution
{
	public:
		int minDistance(std::string word1, std::string word2);
};

int	Solution::minDistance(std::string word1, std::string word2)
{
	int	length1 = word1.length();
	int	length2 = word2.length();
	std::vector<int>	lastRow(length2 + 1);
	int	prevCell;
	int	currentCell = length1;
	
	for (int i = 0; i <= length2; i++)
		lastRow[i] = i;
	for (int idx1 = 1; idx1 <= length1; idx1++)
	{
		prevCell = idx1;
		for (int idx2 = 1; idx2 <= length2; idx2++)
		{
			if (word1[idx1 - 1] == word2[idx2 - 1])
				currentCell = lastRow[idx2 - 1];
			else
				currentCell = std::min(prevCell, std::min(lastRow[idx2], lastRow[idx2 - 1])) + 1;
			lastRow[idx2 - 1] = prevCell;
			prevCell = currentCell;
		}
		lastRow[length2] = currentCell;
	}
	return lastRow[length2];
}

int main()
{
	Solution	solve;	
	std::cout << solve.minDistance("abc", "abd") << std::endl;
	std::cout << solve.minDistance("abc", "abc") << std::endl;
	std::cout << solve.minDistance("abd", "abddd") << std::endl;
	std::cout << solve.minDistance("", "abd") << std::endl;
	std::cout << solve.minDistance("abc", "") << std::endl;
	std::cout << solve.minDistance("ddabc", "abc") << std::endl;
	std::cout << solve.minDistance("ddabc", "abddabc") << std::endl;
	std::cout << solve.minDistance("", "") << std::endl;
	std::cout << solve.minDistance("horse", "ros") << std::endl;
	std::cout << solve.minDistance("intention", "execution") << std::endl;
	return 0;
}