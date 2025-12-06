#include <vector>
#include <queue>
#include <iostream>

struct Coords
{
	int	x;
	int	y;
	Coords(int x, int y): x(x), y(y){};
	Coords(): x(0), y(0){};
};

Coords operator+(const Coords& first, const Coords& other)
{
	return Coords(first.x + other.x, first.y + other.y);
}

class Solution {
	private:
		std::vector<std::vector<bool>>	visitedCells;
		int		width;
		int		height;
		int		depth = 0;

		int		FindExit(std::vector<std::vector<char>>& maze, Coords start);
		void	EnqueueOneNeighbour(std::vector<std::vector<char>>& maze, std::queue<Coords>& queue, Coords cell);
		void	EnqueueAllNeighbours(std::vector<std::vector<char>>& maze, std::queue<Coords>& queue, Coords cell);
		bool	IsExit(std::vector<std::vector<char>>& maze,  Coords cell);
		bool	IsPassable(std::vector<std::vector<char>>& maze,  Coords cell);
	public:
		int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance)
		{
			width = maze[0].size();
			height = maze.size();
			visitedCells = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
			maze[entrance[0]][entrance[1]] = '+';
			return FindExit(maze, Coords(entrance[1], entrance[0]));
		}
};

int		Solution::FindExit(std::vector<std::vector<char>>& maze, Coords start)
{
	std::queue<Coords>	expansionOrder[2];
	bool				isCicleEven = true;
	Coords				currentCell = start;

	expansionOrder[isCicleEven].push(start);
	visitedCells[start.y][start.x] = true;
	while (expansionOrder[0].empty() == false || expansionOrder[1].empty() == false)
	{
		while (expansionOrder[isCicleEven].empty() == false)
		{
			currentCell = expansionOrder[isCicleEven].front();
			if (IsExit(maze, currentCell))
				return depth;
			EnqueueAllNeighbours(maze, expansionOrder[!isCicleEven], currentCell);
			expansionOrder[isCicleEven].pop();
		}
		depth++;
		isCicleEven ^= true;
	}
	return -1;
}

void	Solution::EnqueueAllNeighbours(std::vector<std::vector<char>>& maze, std::queue<Coords>& queue, Coords cell)
{
	EnqueueOneNeighbour(maze, queue, cell + Coords(-1, 0));
	EnqueueOneNeighbour(maze, queue, cell + Coords(1, 0));
	EnqueueOneNeighbour(maze, queue, cell + Coords(0, -1));
	EnqueueOneNeighbour(maze, queue, cell + Coords(0, 1));
}


void	Solution::EnqueueOneNeighbour(std::vector<std::vector<char>>& maze, std::queue<Coords>& queue, Coords cell)
{
	if (IsPassable(maze, cell) && visitedCells[cell.y][cell.x] == false)
	{
		queue.push(cell);
		visitedCells[cell.y][cell.x] = true;
	}
}

bool Solution::IsExit(std::vector<std::vector<char>>& maze, Coords cell)
{
	if ((cell.x == 0 || cell.x == width - 1 || cell.y == 0 || cell.y == height - 1)
		&& maze[cell.y][cell.x] != '+')
		return true;
	return false;
}

bool Solution::IsPassable(std::vector<std::vector<char>>& maze, Coords cell)
{
	if ((cell.x < 0) || (cell.x > width - 1) || (cell.y < 0) || (cell.y > height - 1))
		return false;
	if (maze[cell.y][cell.x] == '.')
		return true;
	return false;
}

int	main()
{
	Solution	solve;


	std::vector<std::vector<char>> map1{{'+','+','.','+'}, {'.','.','.','+'}, {'+','+','+','.'}};
	std::vector<int>	entrance1 = {1, 2};
	std::vector<std::vector<char>> map2{{'+','+','+'}, {'.','.','.'}, {'+','+','+'}};
	std::vector<int>	entrance2 = {1, 0};

	std::vector<std::vector<char>> map3{{'+','.','+','+','+','+','+'},
										{'+','.','+','.','.','.','+'},
										{'+','.','+','.','+','.','+'},
										{'+','.','.','.','.','.','+'},
										{'+','+','+','+','.','+','.'}};
	std::vector<int>	entrance3 = {1, 0};
	std::vector<std::vector<char>> map4{{'+','.','+','+','+','+','+'},
										{'+','.','+','.','.','.','+'},
										{'+','.','+','.','+','.','+'},
										{'+','.','.','.','+','.','+'},
										{'+','+','+','+','+','+','.'}};
	std::vector<int>	entrance4 = {0, 1};

	// std::cout << solve.nearestExit(map1, entrance1) << std::endl;
	// std::cout << solve.nearestExit(map2, entrance2) << std::endl;
	// std::cout << solve.nearestExit(map3, entrance3) << std::endl;
	std::cout << solve.nearestExit(map4, entrance4) << std::endl;
	return (0);
}

// ТАБАЧНЫЕ КОРПОРАЦИИ ХОТЯТ ВЛАДЕТЬ ТВОЕЙ ДУШОЙ!