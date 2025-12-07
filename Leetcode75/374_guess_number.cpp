int guess(int num);

class Solution {
public:
	int guessNumber(int n)
	{
		long	lowerBound = 1;
		long	upperBound = n;
		long	middle = ((long)n + 1) / 2;
		long	guessResult;

		while (lowerBound < upperBound)
		{
			guessResult = guess(middle);
			if (guessResult == 0)
				return middle;
			if (guessResult > 0)
				lowerBound = middle + 1;
			else
				upperBound = middle - 1;
			middle = (lowerBound  + upperBound) / 2;
		}
		return lowerBound;
	}
};