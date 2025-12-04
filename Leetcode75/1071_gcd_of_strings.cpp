#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <string.h>

class Solution {
	private:
		int	gcd(int a, int b)
		{
			while (a != 0 && b != 0)
			{
				a %= b;
				if (a != 0)
					b %= a;
			}
			return a + b;
		}
		bool	CheckIsDivisible(std::string str, int quotient, char* divider, int lengthDiv)
		{
			char*	ptr = str.begin().base();

			for (int i = 0; i < quotient; i++)
			{
				if (strncmp(ptr, divider, lengthDiv) != 0)
					return false;
				ptr += lengthDiv;
			}
			return true;
		}
	public:
		std::string gcdOfStrings(std::string str1, std::string str2)
		{
			int		length1 = str1.size();
			int		length2 = str2.size();
			int		lengthSubstr = gcd(length1, length2);
			char	divider[std::max(length1, length2) + 1];

			while (lengthSubstr > 0)
			{
				if (((length1 % lengthSubstr) == 0) && ((length2 % lengthSubstr) == 0))
				{
					bool	isDivisible;

					strncpy(divider, str1.c_str(), lengthSubstr);
					divider[lengthSubstr] = '\0';
					isDivisible = CheckIsDivisible(str1, length1 / lengthSubstr, divider, lengthSubstr);
					if (isDivisible)
						isDivisible = CheckIsDivisible(str2, length2 / lengthSubstr, divider, lengthSubstr);
					if (isDivisible)
						return std::string(divider);
				}
				lengthSubstr--;
			}
			return std::string();
		}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::string	str1 = std::string("AB");
	std::string	str2 = std::string("ABABAB");
	std::cout << solve.gcdOfStrings(str1, str2) << std::endl;
	return (0);
}