#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
	private:
		int					result;
		int					size;
		std::vector<int>	lastPair;
		static bool			compareLess(const std::vector<int>& a, const std::vector<int>& b);
	public:
		int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals);
};

bool	Solution::compareLess(const std::vector<int>& a, const std::vector<int>& b)
{
	if (a.size() < 2 || b.size() < 2)
		return false;
	if (a[1] < b[1])
		return true;
	return false;
}
int	Solution::eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
{
	std::sort(intervals.begin(), intervals.end(), compareLess);

	std::vector<int>&	lastPair = intervals[0];
	result = 0;
	size = intervals.size();

	for (int i = 1; i < size; i++)
	{
		if (intervals[i][0] < lastPair[1])
			result++;
		else
			lastPair = intervals[i];
	}
	return result;
}

int	main()
{
	Solution	solve;
	int			result;

	std::vector<std::vector<int>>	vec1{{1,2},{2,3},{3,4},{1,3}};
	result = solve.eraseOverlapIntervals(vec1);
	std::cout << result << std::endl;

	std::vector<std::vector<int>>	vec2{{1,2},{1,2},{1,2}};
	result = solve.eraseOverlapIntervals(vec2);
	std::cout << result << std::endl;

	{std::vector<std::vector<int>>	vec2{{1,2}};
	result = solve.eraseOverlapIntervals(vec2);
	std::cout << result << std::endl;}

	return (0);
}