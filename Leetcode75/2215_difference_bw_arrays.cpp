#include <unordered_set>
#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::unordered_set<int>	set1;
		std::unordered_set<int>	set2;
		std::unordered_set<int>	results[2];

		for (int i = 0; i< nums1.size(); i++)
			set1.emplace(nums1[i]);
		for (int i = 0; i< nums2.size(); i++)
		{
			if (set1.count(nums2[i]) == 0)
				results[1].emplace(nums2[i]);
			set2.emplace(nums2[i]);
		}
		for (int i = 0; i< nums1.size(); i++)
		{
			if (set2.count(nums1[i]) == 0)
				results[0].emplace(nums1[i]);
		}
		return (std::vector<std::vector<int>>{{results[0].begin(), results[0].end()}, {results[1].begin(), results[1].end()}});
	}
};

template <class T>
void	PrintVector(std::vector<T>	vec)
{
	for (int i = 0; i< vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}


int	main(int argc, char** argv)
{
	Solution	solve;

	std::vector<int>	vec1({1,2,3});
	std::vector<int>	vec2({2,4,6});
	std::vector<std::vector<int>> result;

	result = solve.findDifference(vec1, vec2);
	PrintVector(result[0]);
	PrintVector(result[1]);
	std::cout << std::endl;
	return (0);
}