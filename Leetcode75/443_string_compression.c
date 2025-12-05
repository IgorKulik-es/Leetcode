#include <math.h>
#include <stdio.h>

int	putCurrentChar(char* line, char c, int num)
{
	*line = c;
	if (num == 1)
		return (1);

	int	numCopy = num;
	int length = 1;

	while (numCopy /= 10)
		length++;
	line = line + length;
	while (num > 0)
	{
		*line = '0' + num % 10;
		line--;
		num /= 10;
	}
	return (length + 1);
}

int compress(char* chars, int charsSize)
{
	int		index = 0;
	int		carriage = 0;
	char	currentChar = *chars;
	int		countChar = 0;

	while (index < charsSize)
	{
		if (currentChar == chars[index])
			countChar++;
		else
		{
			carriage += putCurrentChar(&(chars[carriage]), currentChar, countChar);
			currentChar = chars[index];
			countChar = 1;
		}
		index++;
	}
	carriage += putCurrentChar(&(chars[carriage]), currentChar, countChar);
	return (carriage);
}

int	main(int argc, char** argv)
{
	char	test[30] = "abbbbbbbbbbbb";
	
	printf("Length: %d, string: %s\n", compress(test, 13), test);
	return (0);
}