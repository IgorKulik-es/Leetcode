#include <iostream>
#include <vector>
#include <queue>

class Solution
{
	private:
		int	maxLength = 0;
		void UpdateLength(int& current);
	public:
		int longestOnes(std::vector<int>& nums, int k)
		{
			std::queue<int>	fills;
			int				currentLength = 0;
			int				fillersLeft = k;
			int				size = nums.size();

			for (int index = 0; index < size; index++)
			{
				if (nums[index] == 1)
					UpdateLength(currentLength);
				else if (fillersLeft > 0)
				{
					fills.push(index);
					fillersLeft--;
					UpdateLength(currentLength);
				}
				else if (fills.empty())
					currentLength = 0;
				else
				{
					currentLength = (index - fills.front() - 1);
					fills.pop();
					fills.push(index);
					UpdateLength(currentLength);
				}
			}
			return maxLength;
		}
};

void Solution::UpdateLength(int& current)
{
	current++;
	if (maxLength < current)
		maxLength = current;
}


int	main()
{
	Solution	solve;

	std::vector<int>	vec{1,0,0,0,0,0,0,0, 1};

	std::cout << solve.longestOnes(vec, 6) << std::endl;
	return (0);
}