#include <vector>
#include <iostream>

class Solution
{
	private:
		std::vector<int>	postfixProducts;
		int					size;
		int					prefixProduct;
	public:
		std::vector<int>	productExceptSelf(std::vector<int>& nums);
};

std::vector<int>	Solution::productExceptSelf(std::vector<int>& nums)
{
	size = nums.size();
	postfixProducts = std::vector<int>(size);

	postfixProducts[size - 1] = nums[size - 1];
	for (int i = size - 2; i > 0; i--)
		postfixProducts[i] = postfixProducts[i + 1] * nums[i];
	postfixProducts[0] = postfixProducts[1];
	prefixProduct = 1;
	for (int i = 1; i < size - 1; i++)
	{
		prefixProduct *= nums[i - 1];
		postfixProducts[i] = prefixProduct * postfixProducts[i + 1];
	}
	postfixProducts[size - 1] = prefixProduct * nums[size - 2];
	return postfixProducts;
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
	Solution	solve;
	std::vector<int>	result;

	std::vector<int>	vec1({1,2,3,4});
	result = solve.productExceptSelf(vec1);
	PrintVector(result);

	std::vector<int>	vec2({-1,1});
	result = solve.productExceptSelf(vec2);
	PrintVector(result);

	return (0);
}