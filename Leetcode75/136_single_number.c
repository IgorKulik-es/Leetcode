int singleNumber(int* nums, int numsSize)
{
	int	result = nums[0];

	for (int i = 1; i < numsSize; i++)
	{
		result ^= nums[i];
	}
	return result;
}

int	main()
{
	int	nums1[4] = {1,2,3,1};
	int	nums2[3] = {1,2,3};
	int	result;

	result = findPeakElement(nums1, 4);
	printf("%d\n", result);
	result = findPeakElement(nums2, 3);
	printf("%d\n", result);
	return (0);
}