#include <vector>
#include <queue>
#include <iostream>
#define UNVISITED 0
#define PLANNED 1
#define VISITED 2

class Solution
{
	public:
		bool canVisitAllRooms(std::vector<std::vector<int>>& rooms)
		{
			std::queue<int>		visitOrder;
			std::vector<int>	visitedRooms(rooms.size(), UNVISITED);
			int					numUnvisited = rooms.size();
			int					numPlanned = 1;
			int					room;

			visitOrder.push(0);
			while (visitOrder.empty() == false)
			{
				if (numPlanned >= numUnvisited)
					return (true);
				room = visitOrder.front();
				if (visitedRooms[room] != VISITED)
				{
					numPlanned--;
					numUnvisited--;
					for (int nextRoom : rooms[room])
					{
						if (visitedRooms[nextRoom] == UNVISITED)
						{
							visitedRooms[nextRoom] = PLANNED;
							numPlanned++;
							if (numPlanned >= numUnvisited)
								return (true);
							visitOrder.push(nextRoom);
						}
					}
					visitedRooms[room] = VISITED;
				}
				visitOrder.pop();
			}
			return (false);
		}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::vector<std::vector<int>>	map1 = {{1,3},{3,0,1},{2},{0}};
	std::vector<std::vector<int>>	map2 = {{1,2},{2},{0},{}};

	std::cout << solve.canVisitAllRooms(map2) << std::endl;
	return (0);
}