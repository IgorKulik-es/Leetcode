#include <stdio.h>

int longestSubarray(int* nums, int numsSize)
{
	int	indCut = -1;
	int	maxLength = 0;
	int	currentLength = 0;

	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 1)
			currentLength++;
		else
		{
			currentLength = i - indCut - 1;
			indCut = i;
		}
		if (currentLength > maxLength)
			maxLength = currentLength;
	}
	if (indCut == -1)
		maxLength--;
	return maxLength;
}


int	main()
{
	{
	int	test[9] = {1,1,0,1};
	printf("Longest sequence: %d\n", longestSubarray(test, 4));
	}
	{
	int	test[9] = {0,1,1,1,1,1,0,1};
	printf("Longest sequence: %d\n", longestSubarray(test, 49));
	}
	{
	int	test[9] = {1,1,1};	
	printf("Longest sequence: %d\n", longestSubarray(test, 3));
	}
	{
	int	test[9] = {0,1,0,0,0,1,1,1,0};	
	printf("Longest sequence: %d\n", longestSubarray(test, 9));
	}
	{
	int	test[9] = {1,1,0,1,1,0,1,1,1};
	printf("Longest sequence: %d\n", longestSubarray(test, 9));
	}
	return (0);
}