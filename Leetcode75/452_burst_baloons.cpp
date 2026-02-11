#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
	private:
		static bool	CompareIntervals(const std::vector<int>& a, const std::vector<int>& b);
	public:
		int findMinArrowShots(std::vector<std::vector<int>>& points);
};

bool	Solution::CompareIntervals(const std::vector<int>& a, const std::vector<int>& b)
{
	return a[1] < b[1];
}

int	Solution::findMinArrowShots(std::vector<std::vector<int>>& points)
{
	int	lastArrow;
	int	size = points.size();
	int	totalArrows = 1;

	std::sort(points.begin(), points.end(), CompareIntervals);
	lastArrow = points[0][1];
	for (int i = 1; i < size; i++)
	{
		if (points[i][0] > lastArrow)
		{
			totalArrows++;
			lastArrow = points[i][1];
		}
	}
	return totalArrows;
}

int	main()
{
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{1,2},{3,4},{5,6},{7,8}});
		std::cout << solve.findMinArrowShots(vec) << std::endl;
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{1,2},{2,3},{3,4},{4,5}});
		std::cout << solve.findMinArrowShots(vec) << std::endl;
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{11,12},{1,2},{2,3},{1,5},{-10,5}});
		std::cout << solve.findMinArrowShots(vec) << std::endl;
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{1,2}});
		std::cout << solve.findMinArrowShots(vec) << std::endl;
	}
	return (0);
}