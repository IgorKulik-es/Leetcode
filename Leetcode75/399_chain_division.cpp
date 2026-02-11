#include <iostream>
#include <vector>
#include <map>

typedef std::vector<std::vector<std::string>> WordPairs;

class Solution
{
	private:
		std::map<std::string, int>			dictionary;
		std::vector<std::vector<double>>	map;
		int									numLines = 0;
		bool								isFound = false;

		int		ConvertToIndex(std::string& line, bool emplace);
		void	FillDictionary(std::vector<std::vector<std::string>>& equations, std::vector<double>& values);
		double	FindRatio(int currentNode, int finish, std::vector<bool>& visited, double currentRatio);
	public:
		std::vector<double>	calcEquation(WordPairs& equations, std::vector<double>& values, WordPairs& queries);
};

std::vector<double>	Solution::calcEquation(WordPairs& equations, std::vector<double>& values, WordPairs& queries)
{
	int		firstWord;
	int		secondWord;
	double	ratio;
	std::vector<double>	result(queries.size(), -1.0);
	std::vector<bool>	visited;

	FillDictionary(equations, values);
	visited.resize(numLines);
	for (size_t i = 0; i < queries.size(); i++)
	{
		firstWord = ConvertToIndex(queries[i][0], false);
		secondWord = ConvertToIndex(queries[i][1], false);
		if (firstWord == -1 || secondWord == -1)
			continue;
		isFound = false;
		std::fill(visited.begin(), visited.end(), false);
		ratio = FindRatio(firstWord, secondWord, visited, 1.0);
		if (isFound)
			result[i] = ratio;
	}
	return result;
}

int	Solution::ConvertToIndex(std::string& line, bool emplace)
{
	std::map<std::string, int>::iterator	find;

	find = dictionary.find(line);
	if (find != dictionary.end())
		return (*find).second;
	if (emplace)
	{
		dictionary.emplace(std::pair<std::string, int>(line, numLines));
		numLines++;
		return numLines - 1;
	}
	return -1;
}

void	Solution::FillDictionary(std::vector<std::vector<std::string>>& equations, std::vector<double>& values)
{
	int	first;
	int	second;

	for(std::vector<std::string> pair: equations)
	{
		ConvertToIndex(pair[0], true);
		ConvertToIndex(pair[1], true);
	}
	map = std::vector<std::vector<double>>(numLines, std::vector<double>(numLines, 0));
	for(size_t i = 0; i < equations.size(); i++)
	{
		first = ConvertToIndex(equations[i][0], true);
		second = ConvertToIndex(equations[i][1], true);
		map[first][second] = values[i];
		map[second][first] = 1 / values[i];
	}
}

double	Solution::FindRatio(int currentNode, int finish, std::vector<bool>& visited, double currentRatio)
{
	double	foundRatio = 0.0;

	if (map[currentNode][finish] != 0.0)
	{
		isFound = true;
		return map[currentNode][finish] * currentRatio;
	}
	for (int nextNode = 0; nextNode < numLines && !isFound; nextNode++)
	{
		if (!visited[nextNode] && map[currentNode][nextNode] > 0.0)
		{
			visited[nextNode] = true;
			foundRatio += FindRatio(nextNode, finish, visited, currentRatio * map[currentNode][nextNode]);
		}
	}
	return foundRatio;
}

template <class T>
void	PrintVector(std::vector<T>	vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main()
{
	{
		Solution	solve;
		WordPairs	pairs({{"a", "b"}, {"b", "c"}});
		std::vector<double>	values({2.0, 3.0});
		WordPairs	queries({{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}});
		PrintVector(solve.calcEquation(pairs, values, queries));
	}
	{
		Solution	solve;
		WordPairs	pairs({{"a", "b"}});
		std::vector<double>	values({2.0});
		WordPairs	queries({{"b","a"}});
		PrintVector(solve.calcEquation(pairs, values, queries));
	}
	return 0;
}
