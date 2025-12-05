

int largestAltitude(int* gain, int gainSize)
{
	int	currentHeight = 0;
	int	maxHeight = 0;

	for (int i = 0; i < gainSize; i++)
	{
		currentHeight += gain[i];
		if (currentHeight > maxHeight)
			maxHeight = currentHeight;
	}
	return maxHeight;
}