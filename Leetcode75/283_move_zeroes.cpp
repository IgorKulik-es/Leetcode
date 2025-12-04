#include <vector>
#include <iostream>
#include <string.h>

class Solution {
public:
	void moveZeroes(std::vector<int>& nums)
	{
		int	length = nums.size();

		int	temp[length];
		memset(temp, 0, sizeof(temp));
		int	j = 0;
		for (int i = 0; i < length; i++)
		{
			if (nums[i] != 0)
			{
				temp[j] = nums[i];
				j++;
			}
		}
		for (int i = 0; i < length; i++)
			nums[i] = temp[i];
		// for (int i = 0; i < length; i++)
		// 	std::cout << nums[i] << " ";
		// std::cout << std::endl;
	}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::vector<int>	nums = {1,0,-5,0,50,3,7,0,-20,1,1,1,1,0,1,1,1};
	solve.moveZeroes(nums);
	return (0);
}