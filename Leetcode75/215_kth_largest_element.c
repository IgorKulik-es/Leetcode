#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	swap(int* a, int* b)
{
	int	temp = *a;

	*a = *b;
	*b = temp;
}

int	splitSubarray(int* nums, int left, int right)
{
	int	idxLeft = left + 1;
	int	idxRight = right;
	int	pivot;

	pivot = left + rand() % (right - left + 1);
	swap(&nums[left], &nums[pivot]);
	pivot = nums[left];
	while (idxLeft < idxRight)
	{
		while (idxLeft <= right && nums[idxLeft] >= pivot)
			idxLeft++;
		while (idxRight >= left && nums[idxRight] < pivot)
			idxRight--;
		if (idxLeft < idxRight)
			swap(&nums[idxLeft], &nums[idxRight]);
	}
	swap(&nums[left], &nums[idxRight]);
	return idxRight;
}


int	findKthLargest(int* nums, int numsSize, int k)
{
	int	left = 0;
	int	right = numsSize - 1;
	int	pivotIndex;

	srand(time(NULL));
	k--;
	while (left < right)
	{
		pivotIndex = splitSubarray(nums, left, right);
		if (pivotIndex == k)
			return nums[k];
		else if (pivotIndex < k)
			left = pivotIndex + 1;
		else
			right = pivotIndex - 1;
	}
	return nums[k];
}

int	main()
{
	int	solve1[11] = {3,2,1,5,3,0,6,7,3,3,3};
	printf("%d\n", findKthLargest(solve1, 1, 1));

	int	solve2[11] = {3,2,1,5,3,0,6,7,3,3,3};
	printf("%d\n", findKthLargest(solve2, 8, 1));

	int	solve3[11] = {3,2,1,5,3,0,6,7,3,3,3};
	printf("%d\n", findKthLargest(solve3, 4, 2));

	int	solve4[11] = {8,7,6,5,4,3,2,1};
	printf("%d\n", findKthLargest(solve4, 8, 5));	

	int	solve5[11] = {3,3,3,3,3,3,1,3,3};
	printf("%d\n", findKthLargest(solve5, 8, 8));

	int	solve6[11] = {3,1,2,4};
	printf("%d\n", findKthLargest(solve6, 4, 2));
	return (0);
}