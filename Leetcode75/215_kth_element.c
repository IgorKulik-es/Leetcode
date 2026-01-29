#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>


void swap(int *a, int *b)
{
	int	temp = *a;
	*a = *b;
	*b = temp;
}

int	trivialCase(int* nums, int left, int right, int pivot)
{
	if (nums[left] < nums[right])
		swap(&nums[left], &nums[right]);
	if (nums[right] >= pivot)
		return right;
	return left;
}

int	splitInterval(int* nums, int start, int end)
{
	int	left;
	int	right;
	int	pivot;
	int	result;

	left = start;
	right = end;
	pivot = nums[left];
	//  + rand() % (right - left + 1)
	while ((right - left) > 1)
	{
		while (((right - left) > 1) && (nums[right] < pivot))
			right--;
		while (((right - left) > 1) && (nums[left] >= pivot))
			left++;
		if ((right - left) <= 1)
			result = trivialCase(nums, left, right, pivot);
		else
			swap(&nums[left], &nums[right]);
	}
	return result;
}

int	findSmallest(int* nums, int start, int k)
{
	int	min = nums[start];
	for (int i = start + 1; i <= k; i++)
		if (min > nums[i])
			min = nums[i];
	return min;
}

int	findHeighest(int* nums, int start, int k)
{
	int	max = nums[start];
	for (int i = start + 1; i <= k; i++)
		if (max < nums[i])
			max = nums[i];
	return max;
}

int findKthLargest(int* nums, int numsSize, int k)
{
	int	start = 0;
	int	end = numsSize - 1;
	int	middle;

	k--;
	while ((end - start) > 1)
	{
		middle = splitInterval(nums, start, end);
		if (middle < k)
			start = middle + 1;
		else
			end = middle;
		if (start == k)
			return findHeighest(nums, k, end);
		if (end == k)
			return findSmallest(nums, start, k);
	}
	trivialCase(nums, start, end, 0);
	return nums[k];
}

int	main()
{
	int	solve1[11] = {3,2,1,5,3,0,6,7,3,3,3};
	printf("%d\n", findKthLargest(solve1, 1, 1));

	int	solve2[11] = {3,2,1,5,3,0,6,7,3,3,3};
	printf("%d\n", findKthLargest(solve2, 8, 1));

	int	solve3[11] = {3,2,1,5,3,0,6,7,3,3,3};
	printf("%d\n", findKthLargest(solve3, 4, 3));

	int	solve4[11] = {3,2,1,5,3,0,6,7,3,3,3};
	printf("%d\n", findKthLargest(solve4, 11, 8));	

	int	solve5[11] = {3,3,3,3,3,3,3,3,3};
	printf("%d\n", findKthLargest(solve5, 8, 8));
	return (0);
}