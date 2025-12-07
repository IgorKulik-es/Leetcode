#include <vector>
#include <queue>
#include <iostream>

class Solution
{
	private:
			std::vector<bool>	visitedCities;
			std::queue<int>		visitOrder;
			int					size;
		void ScheduleVisits(std::vector<std::vector<int>>& isConnected, int currentCity);
	public:
		int findCircleNum(std::vector<std::vector<int>>& isConnected)
		{
			int	numComponents = 0;
			
			size = isConnected.size();
			visitedCities = std::vector<bool>(size, false);
			for (int currentCity = 0; currentCity < size; currentCity++)
			{
				if (visitedCities[currentCity])
					continue;
				numComponents++;
				ScheduleVisits(isConnected, currentCity);
				while (visitOrder.empty() == false)
				{
					ScheduleVisits(isConnected, visitOrder.front());
					visitOrder.pop();
				}
			}
			return numComponents;
		}
};

void Solution::ScheduleVisits(std::vector<std::vector<int>>& isConnected, int currentCity)
{
	visitedCities[currentCity] = true;
	for (int destination = 0; destination < size; destination++)
	{
		if (isConnected[currentCity][destination] && (visitedCities[destination] == false))
		{
			visitedCities[destination] = true;
			visitOrder.push(destination);
		}
	}
}

int	main()
{
	Solution	solve;


	std::vector<std::vector<int>>  map1{{1,1,0},
										{1,1,0},
										{0,0,1}};
	std::vector<std::vector<int>>  map2{{1,1,1},
										{1,1,0},
										{1,0,1}};

	std::cout << solve.findCircleNum(map1) << std::endl;
	std::cout << solve.findCircleNum(map2) << std::endl;
	return (0);
}