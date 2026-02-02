#include <iostream>
#include <vector>

class Solution
{
	private:
		std::vector<std::vector<int>>	combos;
		std::vector<int>				currentCombo;
		int								targetSum;
		int								indPreLastDidit;
		void	backtrack(int indDigit, int currentSum, int minDigit);
		void	fillLastDigit(int remainder);
	public:
		std::vector<std::vector<int>>	combinationSum3(int k, int n);
};

std::vector<std::vector<int>>	Solution::combinationSum3(int k, int n)
{
	targetSum = n;
	indPreLastDidit = k - 2;
	currentCombo = std::vector<int>(k);
	if (n > (k * (19 - k)) / 2)
		return std::vector<std::vector<int>>();
	backtrack(0, 0, 1);
	return combos;
}

void	Solution::backtrack(int indDigit, int currentSum, int minDigit)
{
	int	remainder;

	for (int digit = minDigit; digit < 10; digit++)
	{
		remainder = targetSum - currentSum - digit;
		if (remainder <= digit)
			return ;
		currentCombo[indDigit] = digit;
		if (indDigit == indPreLastDidit)
			fillLastDigit(remainder);
		else
			backtrack(indDigit + 1, currentSum + digit, digit + 1);
	}
}

void	Solution::fillLastDigit(int remainder)
{
	if (remainder < 10)
	{
		currentCombo[indPreLastDidit + 1] = remainder;
		combos.push_back(currentCombo);
	}
}

template <class T>
void	PrintVector(std::vector<T>	vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}


int	main()
{

	{
		Solution	solve;
		std::vector<std::vector<int>>	result;
		result = solve.combinationSum3(2, 10);
		std::cout << "Found combos for 2, 10: " << result.size() << std::endl;
		for (size_t i = 0; i < result.size(); i++)
			PrintVector(result[i]);
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	result;
		result = solve.combinationSum3(4, 1);
		std::cout << "Found combos for 4, 1: " << result.size() << std::endl;
		for (size_t i = 0; i < result.size(); i++)
			PrintVector(result[i]);
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	result;
		result = solve.combinationSum3(2, 18);
		std::cout << "Found combos for 2, 18: " << result.size() << std::endl;
		for (size_t i = 0; i < result.size(); i++)
			PrintVector(result[i]);
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	result;
		result = solve.combinationSum3(3, 18);
		std::cout << "Found combos for 3, 18: " << result.size() << std::endl;
		for (size_t i = 0; i < result.size(); i++)
			PrintVector(result[i]);
	}
	return (0);
}