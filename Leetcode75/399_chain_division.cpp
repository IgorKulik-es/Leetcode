#include <iostream>
#include <vector>
#include <map>

class Solution
{
	private:
		std::map<std::string, int>				dictionary;
		std::vector<std::vector<int, double>>	map;
		int										numLines = 0;

		int		ConvertToIndex(std::string& line);
		void	FillDictionary(std::vector<std::vector<std::string>>& equations, std::vector<double>& values);
		void	FillMap();
	public:
		std::vector<double>	calcEquation(std::vector<std::vector<std::string>>& equations,
			std::vector<double>& values, std::vector<std::vector<std::string>>& queries);
};

int	Solution::ConvertToIndex(std::string& line)
{
	std::map<std::string, int>::iterator	find;

	find = dictionary.find(line);
	if (find != dictionary.end())
		return (*find).second;
	dictionary.emplace(std::pair<std::string, int>(line, numLines));
	numLines++;
	return numLines - 1;
}

void	Solution::FillDictionary(std::vector<std::vector<std::string>>& equations, std::vector<double>& values)
{
	int	first;
	int	second;
	int	index = 0;

	for(std::vector<std::string> pair: equations)
	{
		ConvertToIndex(pair[0]);
		ConvertToIndex(pair[1]);
	}
	map = std::vector<std::vector<int, double>>(numLines, std::vector<int, double>(numLines, 0));
	for(std::vector<std::string> pair: equations)
	{
		first = ConvertToIndex(pair[0]);
		second = ConvertToIndex(pair[1]);
		map[first][second] = values[index];
		map[second][first] = 1 / values[index];
	}
}

void	FillMap()
{
	std::
}