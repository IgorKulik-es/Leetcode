#include <iostream>
#include <string>
#include <string.h>

class Solution
{
	private:
		bool	CheckIsVowel(char c)
		{
			if(c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i')
				return true;
			return false;
		}
	public:
		int maxVowels(std::string s, int k)
		{
			int	front = k;
			int	back = 0;
			int	maxV = 0;
			int	currentV;

			for (int i = 0; i < front; i++)
				maxV += CheckIsVowel(s[i]);
			currentV = maxV;
			while (s[front])
			{
				currentV += CheckIsVowel(s[front]) - CheckIsVowel(s[back]);
				if (currentV > maxV)
					maxV = currentV;
				front++;
				back++;
			}
			return (maxV);
		}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::string	str1 = std::string("novowels");

	std::cout << solve.maxVowels(str1, 1) << std::endl;
	return (0);
}